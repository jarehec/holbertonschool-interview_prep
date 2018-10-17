# Double Circular Linked List
 * `add_node_end` - adds a node to the end of a doubly circular linked-list  
 * `add_node_begin` - adds a node to the beginning of a doubly circular linked-list  

## Data Structures
```
/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List {
  char *str;
  struct List *prev;
  struct List *next;
} List;
```

## Authors
* Jared Heck
