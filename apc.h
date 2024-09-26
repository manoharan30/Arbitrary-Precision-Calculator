/**************************************************************************************************************************************************************
*Author		:Manoharan Balakrishnan
*Date		: 09-08-2024
*Title		: header file
*Description: This file contains all the function prototypes and macros used for this project.
***************************************************************************************************************************************************************/
#ifndef APC_H
#define APC_H
#define SUCCESS 0										//macro for successfull function.
#define FAILURE -1										//macro for failure of function.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef int data_t;
typedef struct node										//structure for doubly linked lists
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;


//function to read and validate the command line argument.
void read_and_validate(char* arg,char* operator,Dlist**,Dlist**,Dlist**,Dlist**);
//function to print the doubly linked lists.
void print_list(Dlist *head);
//function to do the addition operation in APC.
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
//function to do the subtraction operation in APC.
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
//function to do the multiplication operation in APC.
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
//function to do the division operation in APC.
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
//helper function for division operation.
int devide_helper(Dlist **head1,Dlist **head2);
//subtraction function for division.
void my_subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);
//function to compare the two operands to find which one is greater.
int compare_lists(Dlist *head1, Dlist *head2);
//function to print the doubly linked list.
void print_listft(Dlist *tail);

int res_insert_at_first(Dlist **headR, Dlist **tailR, int data);
#endif
