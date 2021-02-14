#include "hahaha.h"

void add_one(node** head1, node **tail1);

node *division(node **head1, node **tail1, node **head2, node **tail2, node **headR, node **tailR)
{
        node *temp;
        int status;
        int flag = 0;

        node *hmp = NULL;
        node *tmp = NULL;

        hmp = (node *)malloc(sizeof(node));
        if (hmp == NULL)
        {
                printf("Heap overflow\n");
                exit(FAILURE);
        }
        tmp = hmp;
        hmp->data = 0;
        hmp->next = NULL;
        hmp->prev = NULL;

        if ((status= checkSmall(*head1, *head2, *tail1, *tail2)) == SMALL) 
        {
                sl_insert_first(headR, 0);
                return hmp;
#if 0
                temp = *head1;
                *head1 = *head2;
                *head2 = temp;

                temp = *tail1;
                *tail1 = *tail2;
                *tail2 = temp;
#endif
        } 
        else if (status == EQUAL) 
        {
                sl_insert_first(headR, 0);
                tmp->data = tmp->data + 1;
                return hmp;
        }

#if 1
                do
                {
                        *headR = NULL;
                        *tailR = NULL;
#if 1
        printf("\t\t\t\t");
        print_list(hmp);
                        printf("\t\t\t\t");
                        printf(BOLDRED " :" BOLDMAGENTA ")" BOLDGREEN "--- " RESET);
#endif
#if 0
                        printf("\nbefore Subtraction: \n");
                        print_list(*head1);
                        print_list(*head2);
#endif
                        subtraction(head1, tail1, head2, tail2, headR, tailR, &flag);
                        dl_delete_list(head1, tail1);
                        if ((*headR)->data == 0)
                               (*headR) = (*headR)->next;
                        if (flag == 1)
                        {
                                print_list(*head2);
                                print_list(*head1);
                                //addition(head2, tail2, head1, tail1, headR, tailR, &flag);
                                return hmp;
                        }

                        temp = *headR;
                        while (temp)
                        {
                                dl_insert_first(head1, tail1, temp->data);
                                temp = temp->next;
                        }
                        dl_delete_list(headR, tailR);
#if 1
     //                   printf("after Subtraction: ");
                        print_list(*head1);
#endif
                        add_one(&hmp, &tmp);
                        
                        usleep(10000);
#if 0
                        printf("after reverse\n");
                        print_list(*head1);
#endif
                } while(1);
#endif
}

void add_one(node **hmp, node **tmp)
{
        node *t1 = (node *)malloc(sizeof(node));
        t1->data = 1;
        t1->next = NULL;
        t1->prev = NULL;
        node *t2 = t1;

        node *Hres = NULL;
        node *Tres = NULL;
        addition(hmp, tmp, &t1, &t2, &Hres, &Tres);
        dl_delete_list(hmp, tmp);
        *hmp = Hres;
        *tmp = Tres;

        printf("%d", (*tmp)->data);
       // putchar('\n');
}
