/**************************************************************************************************************************************************************
*Author		:Manoharan Balakrishnan
*Date		: 10-08-2024
*Title		: main function(Driver function)
*Description: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"

int count1;																			//global variable for deciding the size of operand. 
int count2;																			//global variable for deciding the size of the another operand.
int flag=0;																			//global variable for sign of the result.

/**
 * @brief main function which is calling all other functions.
 * @param argc command line argument count.
 * @param argv command line arguments. 
 * @return return 0 or non zero values.
 */
int main(int argc, char *argv[])
{
	//validating whether the user have passed enough command line arguments to do the operations.
	if(argc<2){																						
		printf("ERROR:Pass the operands and operator through the command line.\n");
		return 0;
	}	

	//initialising pointers for two operand lists and one result list.
	Dlist *head1, *tail1, *head2, *tail2, *headR,*tailR;
	//character variable for user option and operator.
	char option, operator;
	//function call to validate the operation passed through the command line argument.
	read_and_validate(argv[1],&operator,&head1,&head2,&tail1,&tail2);
	//switch case to do the operations.
		switch (operator)
		{
			case '+':
				//function call for the addition operation.
				addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				print_list(headR);
				break;
			case '-':	
				//function call for substraction function.
				subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				print_listft(tailR);
				break;
			case '*':	
				//function call for multiplication function.
				multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				print_list(headR);
				break;
			case '/':	
				//function call for division function.
				division(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				print_list(headR);
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
	return 0;
}
/**
 * @brief read and validate function to validate the argument passed through the CLA.
 * @param arg operation which has been passed as a string through the CLA.
 * @param operator character pointer to store the operator.
 * @param head1_and_head2 head pointers of two doubly linked lists.
 * @param tail1_tail2 tail pointers of two doubly linked lists. 
 * @return void functions.
 */
void read_and_validate(char *arg, char *operator, Dlist **head1, Dlist **head2, Dlist **tail1, Dlist **tail2)
{
    int i = 0;

    // Handle sign of the first operand
    if (arg[i] == '-') {
        flag = -1;
        i++;
    }

    // Read the first operand
    while (isdigit(arg[i])) {
        Dlist *temp = malloc(sizeof(Dlist));
        temp->data = arg[i] - '0';
        temp->next = NULL;
        temp->prev = *tail1;

        if (*tail1) {
            (*tail1)->next = temp;
        } else {
            *head1 = temp;
        }
        *tail1 = temp;
        i++;
		//incrementing count 1 inorder to keep the size of 1st operand.
        count1++;
    }

    // Read the operator
    *operator = arg[i];
    i++;
	//reading the sign of the second operand.
	if((*operator=='*'||*operator=='/')&&(arg[i]=='-')){
		flag=flag*-1;
		i++;
	}

    // Read the second operand
    while (isdigit(arg[i])) {
        Dlist *temp = malloc(sizeof(Dlist));
        temp->data = arg[i] - '0';
        temp->next = NULL;
        temp->prev = *tail2;

        if (*tail2) {
            (*tail2)->next = temp;
        } else {
            *head2 = temp;
        }
        *tail2 = temp;
        i++;
        count2++;
    }

    // Handle sign adjustments based on the operator and operand signs
    if (flag == -1 && *operator == '-') {
        flag = -1;
        *operator = '+';
    } else if (*operator == '-' && flag == 0) {
		//checking cases if operand 1 is greater than operand 2 by using compare functions.
        if (count1 > count2 || (count1 == count2 && compare_lists(*head1, *head2) >= 0)) {
            flag = 1;
        } else {
            flag = -1;
        }
    } else if (flag == -1 && *operator == '+') {
        *operator = '-';
    } else if (flag == -1 && (*operator == '*' || *operator == '/')) {
        flag = -1;
    }
}
/**
 * @brief compare function to compare both operands.
 * @param head1 pointer of doubly linked list.
 * @param head2 head pointer of doubly linked list. 
 * @return return 1 or zero.
 */
int compare_lists(Dlist *head1, Dlist *head2) {
	//loop to compare  both the lists.
    while (head1 && head2) {
        if (head1->data > head2->data) return 1;
        if (head1->data < head2->data) return -1;
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 && !head2) return 1;
    if (!head1 && head2) return -1;
    return 0;
}


/**
 * @brief print function to print the result linked list from head.
 * @param head pointer of doubly linked list.
 * @return void function.
 */
void print_list(Dlist *head)
 {
	if(flag==-1){
		printf("-");
	}
	Dlist *temp=head;
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
 }
/**
 * @brief print function to print the result linked list from tail.
 * @param head pointer of doubly linked list.
 * @return void function.
 */
 void print_listft(Dlist *tail)
 {
	if(flag==-1){
		printf("-");
	}
	Dlist *temp=tail;
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->prev;
	}
	printf("\n");
 }



