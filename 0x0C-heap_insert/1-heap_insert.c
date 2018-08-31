#include "binary_trees.h"


/**
 * heapify - bottom-up heap fixer
 * @node: pointer to heap node
 * Return: the new location of node
*/
heap_t *heapify(heap_t *node)
{
	int i;

	if (!node || !node->parent)
		return (NULL);
	while (node->parent && node->n > node->parent->n)
	{
		i = node->parent->n;
		node->parent->n = node->n;
		node->n = i;
		node = node->parent;
	}
	return (node);
}

/**
 * binary_tree_balance - measures the balance of a binary tree
 * @tree: binary tree
 *
 * Return: balance factor
 */
int binary_tree_balance(heap_t *tree)
{
	int left = 0, right = 0;

	if (tree)
	{
		if (tree->left)
			left = binary_tree_height(tree->left) + 1;
		if (tree->right)
			right = binary_tree_height(tree->right) + 1;
	}
	return (left - right);
}

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
		if (tree->left)
		{
			left += binary_tree_height(tree->left);
			left++;
		}
		if (tree->right)
		{
			right += binary_tree_height(tree->right);
			right++;
		}
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
 * heap_insert - builds max heap binary tree
 * @root: pointer to the root node
 * @value: value to insert
 * Return: pointer to a new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;

	if (!root || !*root)
	{
		new_node = (heap_t *)binary_tree_node(NULL, value);
		if (!new_node)
			return (NULL);
		(*root) = new_node;
		return (new_node);
	}
	if (!(*root)->left)
	{
		new_node = (heap_t *)binary_tree_node((*root), value);
		if (!new_node)
			return (NULL);
		(*root)->left = new_node;
		return (heapify(new_node));
	}
	if (!(*root)->right)
	{
		new_node = (heap_t *)binary_tree_node((*root), value);
		if (!new_node)
			return (NULL);
		(*root)->right = new_node;
		return (heapify(new_node));
	}
	if (binary_tree_height((*root)->left) > binary_tree_height((*root)->right))
	{
		if (binary_tree_size((*root)->left) % 2 == 0 ||
			binary_tree_balance((*root)->left) != 0)
			return (heap_insert(&(*root)->left, value));
		else
			return (heap_insert(&(*root)->right, value));
	}
	if (binary_tree_size((*root)->left) > binary_tree_size((*root)->right))
		return (heap_insert(&(*root)->right, value));
	else
		return (heap_insert(&(*root)->left, value));
}
