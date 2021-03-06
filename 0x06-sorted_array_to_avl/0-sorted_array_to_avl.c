#include "binary_trees.h"

/**
 * create_node - creates a tree node
 * Return: pointer to tree node
 */
avl_t *create_node(void)
{
	avl_t *new_tree = malloc(sizeof(avl_t));

	if (new_tree == NULL)
		exit(EXIT_FAILURE);

	new_tree->left = NULL;
	new_tree->parent = NULL;
	new_tree->right = NULL;
	return (new_tree);
}

/**
 * divine_intellect - a holy function
 * @left: index of left node
 * @right: index of right node
 * @arr: array of ints
 * @tree: parent of current node
 * Return: pointer to a node
 */
avl_t *divine_intellect(size_t left, size_t right, int *arr, avl_t *tree)
{
	avl_t *r_node = NULL, *l_node = NULL;
	size_t mid = (left + right) / 2;

	if (!tree)
		return (NULL);
	tree->n = arr[mid];
	if (mid > left && mid < right)
	{
		l_node = create_node();
		r_node = create_node();
		l_node->parent = tree;
		r_node->parent = tree;
		tree->left = divine_intellect(left, mid - 1, arr, l_node);
		tree->right = divine_intellect(mid + 1, right, arr, r_node);
	}
	else if (mid + 1 == right)
	{
		r_node = create_node();
		r_node->parent = tree;
		tree->right = r_node;
		r_node->n = arr[right];
	}

	return (tree);
}

/**
 * sorted_array_to_avl - creates an AVL tree from a sorted array
 * @array: pointer to array
 * @size: number of elements in the array
 * Return: root node of AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (size < 1 || !array)
		return (NULL);

	root = create_node();
	root = divine_intellect(0, size - 1, array, root);

	return (root);
}
