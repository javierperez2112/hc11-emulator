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
        // printf("inst: %s, %04X, %d bytes\n", lookup[i].mnemonic, lookup[i].opcode, op_bytes);
        for(int j = op_bytes; j > 0; j--)
        {
            uint8_t current_search_byte = (lookup[i].opcode >> (j - 1)) & 0xFF;
            if(ptr->children[current_search_byte] == NULL)
            {
                ptr->children[current_search_byte] = calloc(1, sizeof(tree_level_t));
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
        ptr = ptr->children[hc11->memory[hc11->pc]];
        // printf("Searching... PC = %04X -> %02X\n", hc11->pc, hc11->memory[hc11->pc]);
        hc11->pc++;
    }
    // printf("Found!\n");
    return ptr->instruction;
}