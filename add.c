/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Wed Mar 12
 *   File           : Addlists.c
 *   Title          : addition function
 *   Description    : This addition function performs addition on two large numbers
 *                    and stores the result in a linked list.
 * ---------------------------------------------------------------------------- */
#include "hahaha.h"

/* addition: adds the two large numbers in two linked lists and stores the result in another linked list */
int addition(node **head1, node **tail1, node **head2, node **tail2, node **headR, node **tailR)
{
        node *temp, *temp1;
        int sum, carry = 0; 
        
        node *tail = NULL;
        temp = *head1;
        temp1 = *head2;

        while (temp || temp1)
        {
                sum = carry + (temp ? temp->data : 0) + (temp1 ? temp1->data : 0);
                
#if 0
                printf("%d - %d", temp->data, temp1->data);
                printf("<--%d-->\n", sum);
#endif                
                        carry = sum / 10000;
                        sum = sum % 10000;
#if 0
                        printf("sum: %d carry: %d\n", sum, carry);
#endif
                        dl_insert_first(headR, tailR, sum);
                
                if (temp)
                        temp = temp->next;
                if (temp1)
                       temp1 = temp1->next;
        }
        
        return SUCCESS;
}
