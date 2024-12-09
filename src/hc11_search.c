#include "hc11_search.h"
#include <stdlib.h>

static size_t opcode_bytes(inst_t *inst)
{
    size_t bytes = 0;
    while(inst->opcode & (0xFF << 8*bytes))
    {
        bytes++;
    }
    return bytes;
}

tree_level_t *make_tree(inst_t *lookup, size_t n)
{
    tree_level_t *root = calloc(1, sizeof(tree_level_t));
    for(int i = 0; i < n; i++)
    {
        tree_level_t *ptr = root;
        ptr->instruction = NULL;
        int op_bytes = opcode_bytes(&lookup[i]);
        for(int j = op_bytes; j > 0; j--)
        {
            uint8_t current_search_byte = (lookup[i].opcode >> 8*(j - 1)) & 0xFF;
            if(ptr->children == NULL)
            {
                ptr->children = (tree_level_t**)calloc(LEVEL_SIZE, sizeof(tree_level_t*));
            }
            if(ptr->children[current_search_byte] == NULL)
            {
                ptr->children[current_search_byte] = (tree_level_t*)calloc(1, sizeof(tree_level_t));
            }
            ptr = ptr->children[current_search_byte];
        }
        ptr->instruction = &lookup[i];
    }
    return root;
}

inst_t *search_tree(hc11_t *hc11, tree_level_t *root)
{
    tree_level_t *ptr = root;
    while(ptr->instruction == NULL)
    {
        ptr = ptr->children[hc11->memory[hc11->pc++]];
    }
    return ptr->instruction;
}

void end_tree(tree_level_t *root)
{
    if(root->children != NULL)
    {
        for(int i = 0; i < LEVEL_SIZE; i++)
        {
            if(root->children[i]) end_tree(root->children[i]);
        }
    }
    free(root->children);
    free(root);

}