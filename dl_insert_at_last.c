/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : dl_insert_at_last.c
 *   Title          : Function to insert a node at the end of a doubly linked list.
 *   Description    : This function inserts a new node at the end of a 
 *                    doubly linked list.
 * ---------------------------------------------------------------------------- */
#include "hahaha.h"

/* dl_insert_at_last : insert a new node at last of list */
int dl_insert_last(node **head, node **tail, data_t data)
{
        node *new = (node *)malloc(sizeof(node));
        /* Check whether new node created or not */
        if (new == NULL)
        {
            return FAILURE;
        }

        new->data = data;
	new->next = NULL;
	new->prev = NULL;

	/* If list is empty */
	if (*tail == NULL)
        {
		*head = *tail = new;
                return SUCCESS;
        }

	/* If not empty */
        new->prev = *tail;
        (*tail)->next = new;
        *tail = new;
	return SUCCESS;
}
