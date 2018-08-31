#ifndef BINARY_TREES
#define BINARY_TREES
#include <stdlib.h>
#include <stdio.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
heap_t *heapify(heap_t *node);
void binary_tree_print(const binary_tree_t *);

size_t binary_tree_height(heap_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
int binary_tree_balance(heap_t *tree);
int is_balanced_heap(heap_t *root);
#endif /* BINARY_TREES */
