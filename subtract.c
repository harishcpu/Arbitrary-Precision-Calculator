#include "hahaha.h"

void print_back(node *tail);

/* subtraction: Subtracts the two large numbers in two linked lists and stores the result in another linked list */
int subtraction(node **head1, node **tail1, node **head2, node **tail2, node **headR, node **tailR, int *button)
{
#if 0
        printf("In Subtraction: ");  print_list(*head1);
#endif
        node *temp1, *temp2;
        int status, diff = 0, borrow = 0;
        
        temp1 = *head1;
        temp2 = *head2;

        /* turn this off for division */
                if ((status= checkSmall(*head1, *head2, *tail1, *tail2)) == LARGE) {
                        temp1 = *head1;
                        temp2 = *head2;
                } else if (status == SMALL) {
                        temp1 = *head2;
                        temp2 = *head1;
                        *button = 1;
                        putchar('-');
                } else {
                        dl_insert_first(headR, tailR, diff);
                        return SUCCESS;
                }

#if 0
        puts("\nIn Subtraction: ");
        print_list(temp1);
        print_list(temp2);
        putchar('\n');
#endif
        while (temp1 || temp2)
        {
                diff = (temp1 ? temp1->data : 0) - (temp2 ? temp2->data : 0) - borrow;
#if 0
    //          printf("%d - %d", temp1->data, temp2->data);
                printf("<--" BOLDRED "%d" RESET "-->\n", diff);
#endif               
                if (diff < 0)
                {
                        dl_insert_first(headR, tailR, diff + 10000);
                     //   print_list(*headR);
                     //   print_back(*tailR);
                }
                else if (diff > 0)
                {
                        dl_insert_first(headR, tailR, diff);
                      //  print_list(*headR);
                      //  print_back(*tailR);
                }
                else
                {
                        dl_insert_first(headR, tailR, diff);
                      //  print_list(*headR);
                      //  print_back(*tailR);
#if 0
                        sl_insert_first(headR, diff);
                        sl_insert_first(headR, diff);
                        sl_insert_first(headR, diff);
#endif
                }
#if 0
                print_list(*headR);
#endif 
                if (diff < 0)
                        diff = (-diff + 10000);
                borrow = diff / 10000;
#if 0
                diff = diff % 10000;
                printf("diff: %d borrow: %d\n", diff, borrow);
                
                sl_insert_first(headR, diff);
#endif
                if (temp1)
                        temp1 = temp1->next;
                if (temp2)
                       temp2 = temp2->next;
        }
#if 0 
//        diff = (temp1 ? temp1->data : 0) - (temp2 ? temp2->data : 0) - borrow;
//        sl_insert_first(headR, diff);
#endif
        return SUCCESS;
}

int checkSmall(node *l1, node *l2, node *tail1, node *tail2)
{
#if 0
        printf("In checksmall: \n");
        printf("head1: "); print_list(l1);
        printf("head2: "); print_list(l2);
#endif

        int i, j;

        i = j = 0;
        while (l1)
        {
                ++i;
                l1 = l1->next;
        }
        while (l2)
        {
                ++j;
                l2 = l2->next;
        }

        if (i < j)
                return SMALL;
        else if (i > j)
                return LARGE;
        else
        {
#if 0
        printf("Inside EQUAL: ");
        print_list(tail1);
        print_list(tail2);
#endif
                node *temp1, *temp2;

                temp1 = tail1;
                temp2 = tail2;
                while (temp1 && temp2)
                {
//                        printf("%d --- %d\n", temp1->data, temp2->data);
/*                        if (temp1->prev != NULL && temp1->data == 0)
                        {
                                temp1->data  = 10000;
                        }
                        if (temp2->prev != NULL && temp2->data == 0)
                        {
                                temp2->data  = 10000;
                        }
*/
                        if ((temp1)->data > (temp2)->data)
                        {
#if 0
                                printf("Large has got returned\n");
#endif
                                return LARGE;
                        }
                        else if ((temp2)->data > (temp1)->data)
                        {
#if 0
                                printf("Small has got returned\n");
#endif
                                return SMALL;
                        }
                        else if (temp1->data == temp2->data)
                        {
                                temp1 = temp1->prev;
                                temp2 = temp2->prev;
                        }
                }
#if 0
                printf("Equal has returned\n");
#endif
                return EQUAL;
        }
}
