/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : dl_delete_list.c
 *   Title          : Function to delete all the nodes in a doubly linked list.
 *   Description    : This function deletes every node in a doubly linked list, 
 *                    accepts pointers to the first and last node of the list, 
 *                    returns SUCCESS on success, FAILURE if list is empty.
 * ---------------------------------------------------------------------------- */
#include "hahaha.h"

int dl_delete_list(node **head, node **tail)
{
        /* If list is empty */
        if (*head == NULL || *tail == NULL)
                return FAILURE;
        
        /* If not */
        while ((*head) != NULL)
        {
                *head = (*head)->next;
                free(*head);
        }
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
}
