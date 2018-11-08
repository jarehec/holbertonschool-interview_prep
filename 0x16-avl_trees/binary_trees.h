#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

void binary_tree_print(const binary_tree_t *);
size_t bst_height(const binary_tree_t *tree);
size_t plz_be_avl(const binary_tree_t *tree, int max, int min);
int binary_tree_is_avl(const binary_tree_t *);

#endif /* _BINARY_TREES_H_ */
