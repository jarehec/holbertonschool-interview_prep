#include "binary_trees.h"

/**
 * bst_height - measures the height of a binary search tree
 * @tree: binary tree
 *
 * Return: height of binary tree
 */
size_t bst_height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (tree)
	{
		if (tree->left)
			left += bst_height(tree->left) + 1;
		if (tree->right)
			right += bst_height(tree->right) + 1;
	}
	return (right < left ? left : right);
}

/**
 * plz_be_avl - checks if a binary tree is an AVL
 * @tree: pointer to binary tree
 * @max: max limit
 * @min: min limit
 * Return: boolean
 */
size_t plz_be_avl(const binary_tree_t *tree, int max, int min)
{
	size_t l = bst_height(tree->left), r = bst_height(tree->right);

	if (!tree)
		return (0);
	l = l > r ? l - r : r - l;
	if (l > 0)
		return (0);
	l = 1;
	r = 1;
	if (tree->left && ((tree->left->n >= tree->n) || (tree->left->n <= min)))
		return (0);
	if (tree->right && ((tree->right->n <= tree->n) || (tree->right->n >= max)))
		return (0);
	if (tree->left)
		l = plz_be_avl(tree->left, tree->n, min);
	if (tree->right)
		r = plz_be_avl(tree->right, max, tree->n);
	return (l == 1 && r == 1);
}

/**
 * binary_tree_is_avl - determines if a binary tree is an avl tree
 * @tree: pointer to a binary tree
 * Return: boolean
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (tree ? plz_be_avl(tree, INT_MAX, INT_MIN) : 0);
}
