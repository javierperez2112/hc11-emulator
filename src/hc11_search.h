#ifndef _HC11_SEARCH_H
#define _HC11_SEARCH_H

#include "hc11_inst.h"
#include "hc11.h"

#define LEVEL_SIZE 0x100    // 8*n-bit address

typedef struct tree_level_t tree_level_t;

typedef struct tree_level_t
{
    inst_t *instruction;
    tree_level_t *children[LEVEL_SIZE];
} tree_level_t;

tree_level_t *make_tree(inst_t *lookup, size_t n);
inst_t *search_tree(hc11_t *hc11, tree_level_t *root);

#endif  // _HC11_SEARCH_H