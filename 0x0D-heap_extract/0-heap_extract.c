#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: binary tree
 *
 * Return: height of binary tree
 */
size_t binary_tree_height(heap_t *tree)
{
	size_t right = 0, left = 0;

	if (tree)
	{
		if (!tree->left && !tree->right)
			return (1);
		if (tree->left)
			left += binary_tree_height(tree->left) + 1;
		if (tree->right)
			right += binary_tree_height(tree->right) + 1;
	}
	return (right < left ? left : right);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: binary tree
 *
 * Return: number of nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		if (tree->left)
			count += binary_tree_size(tree->left);
		if (tree->right)
			count += binary_tree_size(tree->right);
		count++;
	}
	return (count);
}

/**
 * get_last_inserted - finds the node to push to the top
 * @root: root node
 * Return: pointer to newly inserted node
*/
heap_t *get_last_inserted(heap_t *root)
{
	if (!root)
		return (NULL);

	if (!root->left && !root->right)
		return (root);

	if (binary_tree_height(root->left) > binary_tree_height(root->right))
		return (get_last_inserted(root->left));

	if (binary_tree_size(root->left) > binary_tree_size(root->right))
		return (get_last_inserted(root->right));

	return (get_last_inserted(root->right));
}

/**
 * heapify_down - drags a number down to it's proper place
 * @root: pointer to binary heap
 * todo: make it pretty
 */
void heapify_down(heap_t *root)
{
	heap_t *benis = root;
	int tmp;

	if (!root)
		return;

	while (benis->left || benis->right)
	{
		if (benis->left && benis->right)
		{
			tmp = benis->n;
			if ((benis->n < benis->left->n) && (benis->left->n > benis->right->n))
			{
				benis->n = benis->left->n;
				benis->left->n = tmp;
				benis = benis->left;
			}
			else
			{
				benis->n = benis->right->n;
				benis->right->n = tmp;
				benis = benis->right;
			}
		}
		else if (benis->left)
		{
			benis->n = benis->left->n;
			benis->left->n = tmp;
			benis = benis->left;
		}
		else if (benis->right)
		{
			benis->n = benis->right->n;
			benis->right->n = tmp;
			benis = benis->right;
		}
	}
}

/**
 * heap_extract - deletes the root node
 * @root: pointer to root of binary heap
 * Return: number in root node
*/
int heap_extract(heap_t **root)
{
	heap_t *last_inserted = NULL;
	int n;

	if (!root)
		return (0);

	n = (*root)->n;
	last_inserted = get_last_inserted(*root);
	if (last_inserted->parent && last_inserted->parent->left == last_inserted)
		last_inserted->parent->left = NULL;
	else if (last_inserted->parent)
		last_inserted->parent->right = NULL;
	last_inserted->left = (*root)->left;
	last_inserted->right = (*root)->right;
	if (last_inserted->left)
		last_inserted->left->parent = last_inserted;
	if (last_inserted->right)
		last_inserted->right->parent = last_inserted;
	last_inserted->parent = NULL;
	free(*root);
	(*root) = last_inserted;
	heapify_down(*root);
	return (n);
}
