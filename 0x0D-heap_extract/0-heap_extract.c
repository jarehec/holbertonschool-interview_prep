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
	heap_t *walk = root;
	int tmp;

	if (!root)
		return;

	while (walk->left || walk->right)
	{
		tmp = walk->n;
		if (walk->left && walk->right)
		{
			if ((walk->n < walk->left->n) && (walk->left->n > walk->right->n))
			{
				walk->n = walk->left->n;
				walk->left->n = tmp;
				walk = walk->left;
			}
			else
			{
				walk->n = walk->right->n;
				walk->right->n = tmp;
				walk = walk->right;
			}
		}
		else if (walk->left && (walk->n < walk->left->n))
		{
			walk->n = walk->left->n;
			walk->left->n = tmp;
			walk = walk->left;
		}
		else if (walk->right && (walk->n < walk->right->n))
		{
			walk->n = walk->right->n;
			walk->right->n = tmp;
			walk = walk->right;
		}
		else
			return;
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

	if (!root || !*root)
		return (0);

	n = (*root)->n;
	last_inserted = get_last_inserted(*root);
	if ((*root) == last_inserted)
	{
		free(*root);
		*root = NULL;
	}
	else
	{
		(*root)->n = last_inserted->n;
		if (last_inserted->parent && last_inserted->parent->left == last_inserted)
			last_inserted->parent->left = NULL;
		else if (last_inserted->parent)
			last_inserted->parent->right = NULL;
		free(last_inserted);
		heapify_down(*root);
	}
	return (n);
}
