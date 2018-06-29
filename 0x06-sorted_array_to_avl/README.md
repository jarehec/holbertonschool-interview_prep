# Array to AVL

## Synopsis
This function builds an AVL tree from a sorted array

## Compilatiion
`gcc -Wall -Werror -Wextra -pedantic *.c -o sorted_array_to_avl`

## Usage
* `./0-sorted_array_to_avl`

## Data Structures
```
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
typedef struct binary_tree_s avl_t;
```

## Authors
* Jared Heck
* :D
