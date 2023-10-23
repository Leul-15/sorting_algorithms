#include "sort.h"

/**
 * swap - swaps two nodes in a linked list
 * @list: pointer to doubly linked list
 * @new: pointer to first node
 * @node: pointer to second node
 */
void swap(listint_t **list, listint_t *new, listint_t *node)
{
    listint_t *aprev = new->prev;
    listint_t *bnext = node->next;

    if (aprev)
        aprev->next = node;
    if (bnext)
        bnext->prev = new;

    new->prev = node;
    node->prev = aprev;
    new->next = bnext;
    node->next = new;

    if (node->prev == NULL)
        *list = node;
}
/**
 * insertion_sort_list - sorts a doubly linked list with
 * insertion sort algorithm
 * @list: pointer to doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current;
    listint_t *temp;

    if (list == NULL || *list == NULL)
        return;

    current = *list;
    current = current->next;

    while (current)
    {
        temp = current;
        while (temp)
        {
            if (temp->n > current->n)
            {
                swap(list, temp, current);
                print_list(*list);
            }
            temp = temp->prev;
        }
        current = current->next;
    }
}
