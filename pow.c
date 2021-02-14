#include "hahaha.h"

void mypow(node **head1, node **tail1, node **head2, node **tail2, node **headR, node **tailR)
{
        int count = 0;

        node *temp1 = *head1;
        node *temp2 = *tail1;

                node *head_Sval = (node *)malloc(sizeof(node));
                head_Sval->data = 1;
                head_Sval->next = NULL;
                head_Sval->prev = NULL;
                node *tail_Sval = head_Sval;

                node *head_Rval = NULL;
                node *tail_Rval = NULL;

                if ((*head2)->data == 0)
                {
                        /* return headR with key 1 */
                        *headR = head_Sval;
                        return;
                }
                else if ((*head2)->data == 1)
                {
                        *headR = *head1;
                        return;
                }

        while ((*head2)->data > 1)
        {

                subtraction(head2, tail2, &head_Sval, &tail_Sval, &head_Rval, &tail_Rval, 0);
                dl_delete_list(head2, tail2);
                while (head_Rval)
                {
                        dl_insert_last(head2, tail2, head_Rval->data);
                        head_Rval = head_Rval->next;
                }
#if 0
                printf("\nThe operands:\n");
                print_list(*head1);
                print_list(temp1);
#endif
                multiplication(tail1, head1, &temp2, &temp1, headR, tailR);
//                printf("\nRes: ");
                print_list(*headR);
                dl_delete_list(head1, tail1);
                *head1 = NULL;
                *tail1 = NULL;

                while (*headR != NULL)
                {
                        dl_insert_last(head1, tail1, (*headR)->data);
                        (*headR) = (*headR)->next;
                }
                dl_delete_list(headR, tailR);
#if 0
                printf("\nhead1 Res: ");
                print_list(*head1);
#endif
                *headR = NULL;
                *tailR = NULL;

#if 0
                print_list(*head2);
#endif
                reverse_list_iterative(head1);
                reverse_list_iterative(&temp1);

                count = 1;
        }

        if (count)
        {
                while (*head1)
                {
                        dl_insert_last(headR, tailR, (*head1)->data);
                        (*head1) = (*head1)->next;
                }
                
                dl_delete_list(head1, tail1);
                *head1 = NULL;
                *tail1 = NULL;

                reverse_list_iterative(headR);
        }
}
