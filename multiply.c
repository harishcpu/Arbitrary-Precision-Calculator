/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Wed Mar 12
 *   File           : Multiplylists.c
 *   Title          : multiplication function
 *   Description    : This multiplication function performs multiplication on two large numbers
 *                    and stores the result in another linked list.
 * ---------------------------------------------------------------------------- */
#include "hahaha.h"

/* multiplication: Multiply two large numbers in two linked lists and store the result in another linked list */
int multiplication(node **head1, node **tail1, node **head2, node **tail2, node **headR, node **tailR)
{
        node *temp1 = *head1;
        node *temp2 = *head2;

        /* create a new list of length as head1 */
        int n_nodes = find_length(head1);
        create_new_list(headR, tailR, n_nodes);

        int carry, Res;
        node *tail = *tailR;
        node *Rtail = *tailR;

#if 0
        printf("In multiplication: ");
        print_list(*head1);
        print_list(*head2);
        print_list(*headR);
#endif
        while (temp2)
        {
                temp1 = *head1;
                Res = 0;
                carry = 0;
                while (temp1)
                {
                        Res =  temp1->data * temp2->data;
#if 0
                        printf("\n<--" BOLDRED "%d * %d" RESET "--> %d\n", temp1->data, temp2->data, Res);
#endif
                        Res = Res + carry;
                        carry = Res / 10000;
#if 0
                        printf("carry : %d\n", carry);
                        printf("Res : %d\n", Res % 10000);
#endif
                        Res = Res % 10000;
                        To_headR(headR, &tail, Res);

                        temp1 = temp1->next;
                        if (tail)
                                tail = tail->prev;
                }
                if (carry)
                        To_headR(headR, &tail, carry);
#if 0
                putchar('\n');
#endif
                temp2 = temp2->next;

                Rtail = Rtail->prev;
                tail = Rtail;
#if 0
                print_list(*headR);
#endif
        }
}

void To_headR(node **headR, node **tailR, int data)
{
        if (*tailR == NULL)
        {
                node *new = (node *)malloc(sizeof(node));
                if (new == NULL)
                        exit(FAILURE);
                new->data = data;
                new->prev = NULL;
                new->next = *headR;

                (*headR)->prev = new;
                *headR = new;
                return;
        }
#if 0
        printf("\t\t\t\t"BOLDRED "Node: " RESET "%d + %d: ", (*tailR)->data, data);
#endif
        int sum = (*tailR)->data + data;
        
        int carry = sum / 10000;
        (*tailR)->data = sum % 10000;
        
        if (carry)
        {
                if ((*tailR)->prev)
                        (*tailR)->prev->data += carry;
                else
                        To_headR(headR, &((*tailR)->prev), carry);
        }

#if 0
        printf("%d   ", (*tailR)->data);
#endif
}

void create_new_list(node **headR, node **tailR, int n_nodes)
{
        for (int i = 0; i < n_nodes; ++i)
                dl_insert_last(headR, tailR, 0);
}

int find_length(node **head)
{
        int i = 0;
        node *temp = *head;
        while (temp)
        {
                ++i;
                temp = temp->next;
        }
        return i;
}
