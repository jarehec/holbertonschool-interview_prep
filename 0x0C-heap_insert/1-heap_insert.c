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
 * is_balanced_heap - checks if the heap is balanced
 * @root: pointer to root node
 * Return: 1 if balanced otherwise 0
 */
int is_balanced_heap(heap_t *root)
{
	int left = 0, right = 0;

	if (root)
	{
		if (root->left)
			left = binary_tree_height(root->left) + 1;
		if (root->right)
			right = binary_tree_height(root->right) + 1;
	}
	return (left == right);
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
	if (value > (*root)->n)
	{
		new_node = (heap_t *)binary_tree_node(NULL, value);
		if (!new_node)
			return (NULL);
		new_node->parent = (*root)->parent;
		(*root)->parent = new_node;
		if (!(*root)->left)
		{
			new_node->left = (*root);
			new_node->right = (*root)->right;
			(*root)->right = NULL;
			if (new_node->right)
				new_node->right->parent = new_node;
		}
		else if (!(*root)->right)
		{
			new_node->left = (*root)->left;
			new_node->right = (*root);
			new_node->left->parent = new_node;
			(*root)->left = NULL;
		}
		else if (!is_balanced_heap((*root)->right) &&
				 is_balanced_heap((*root)->left))
		{
			new_node->left = (*root)->left;
			new_node->left->parent = new_node;
			new_node->right = (*root)->right;
			new_node->right->parent = new_node;
			value = (*root)->n;
			free(*root);
			heap_insert(&(new_node->right), value);
		}
		else
		{
			new_node->left = (*root)->left;
			new_node->left->parent = new_node;
			new_node->right = (*root)->right;
			new_node->right->parent = new_node;
			value = (*root)->n;
			free(*root);
			heap_insert(&(new_node->left), value);
		}
		(*root) = new_node;
		return (new_node);
	}
	if (!(*root)->left)
	{
		new_node = (heap_t *)binary_tree_node((*root), value);
		if (!new_node)
			return (NULL);
		(*root)->left = new_node;
		return (new_node);
	}
	if (!(*root)->right)
	{
		new_node = (heap_t *)binary_tree_node((*root), value);
		if (!new_node)
			return (NULL);
		(*root)->right = new_node;
		return (new_node);
	}
	if (!is_balanced_heap((*root)) && is_balanced_heap((*root)->left))
		return (heap_insert(&(*root)->right, value));
	return (heap_insert(&(*root)->left, value));

	return (NULL);
}
