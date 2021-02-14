/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : reverse_list.c
 *   Title          : Reverse a linked list 
 *   Description    : These functions will reverse a linked list using iterative method.
 * ---------------------------------------------------------------------------- */
#include "hahaha.h"

void reverse_list_iterative(node **head)
{
        /* if the list is empty or has only one node */
        if (*head == NULL || (*head)->next == NULL)
                return;

        /* else if has more than one node */
        node *curr, *prev, *next;

        prev = NULL;
        curr = *head;
        while (curr != NULL)
        {
                /* make current node's link as next node */
                next = curr->next;
                /* store prev node's address in current node's link */
                curr->next = prev;

                /* update prev node to current node */
                prev = curr;
                /* update current node to next node */
                curr = next;
        }

        /* update head */
        *head = prev;
}
