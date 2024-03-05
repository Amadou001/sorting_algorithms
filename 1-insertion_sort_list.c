#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;  // Nothing to sort

    listint_t *sorted = NULL;  // Initialize sorted list

    // Traverse the original list
    while (*list != NULL)
    {
        listint_t *current = *list;  // Point to the current node
        *list = (*list)->next;  // Move to the next node

        // If the sorted list is empty or the current node value is less than the sorted list's head value
        if (sorted == NULL || current->n <= sorted->n)
        {
            current->prev = NULL;  // Set the previous pointer of the current node to NULL
            current->next = sorted;  // Set the next pointer of the current node to the sorted list
            if (sorted != NULL)
                sorted->prev = current;  // Set the previous pointer of the sorted list's head to the current node
            sorted = current;  // Update the sorted list's head
        }
        else
        {
            listint_t *temp = sorted;  // Point to the head of the sorted list

            // Find the correct position to insert the current node in the sorted list
            while (temp->next != NULL && temp->next->n < current->n)
                temp = temp->next;

            // Insert the current node into the sorted list
            current->prev = temp;  // Set the previous pointer of the current node
            current->next = temp->next;  // Set the next pointer of the current node
            if (temp->next != NULL)
                temp->next->prev = current;  // Set the previous pointer of the next node to the current node
            temp->next = current;  // Update the next pointer of the previous node
        }
        print_list(*list);  // Print the list after each swap
    }

    // Update the list pointer to point to the sorted list
    *list = sorted;
}
