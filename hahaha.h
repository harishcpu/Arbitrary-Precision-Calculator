#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "colors.h"

#define SUCCESS 0
#define FAILURE 1

#define SMALL 0
#define LARGE 1
#define EQUAL -1

typedef int data_t;
/* structure definition */
typedef struct _node
{
        struct _node* prev;
        data_t data;
        struct _node* next;
} node;

/* function prototypes */
int addition(node **head1, node **tail1, node **head2, node **tail2, node **headR, node **tailR);

/* for subtraction */
int subtraction(node **head1, node **tail1, node **head2, node **tail2, node **headR,node **tailR, int *key);

/* for multiplication */
int multiplication(node **head1, node **tail1, node **head2, node **tail2, node **headR, node **tailR);

/* for division */
node *division(node **head1, node **tail1, node **head2, node **tail2, node **headR, node **tailR);
void reverse_list_iterative(node **head);
void addone(node **hmp, node **tmp);

/* for power */
void mypow(node **head1, node **tail1, node **head2, node **tail2, node **headR, node **tailR);

/* common for multiplication and division */
void To_headR(node **headR, node **tailR, int data);
void create_new_list(node **headR, node **tailR, int n_nodes);
int find_length(node **head);

/* common for division and subtraction */
int checkSmall(node *l1, node *l2, node *tail1, node *tail2);

/* common for all functions */
int feed_numbers(node **head1, node **tail1, node **head2, node **tail2);

int sl_insert_first(node **headR, data_t data);

int dl_insert_last(node **head, node **tail, data_t data);

int dl_insert_first(node **headR, node **tailR, data_t data);

int dl_delete_list(node **head, node **tail);

void print_list(node* head);

#endif
