/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
/**
 * @brief to perform the subtraction operation in the APC.
 * @param headR_tailR head and tail pointers to store the results.
 * @param head1_and_head2 head pointers of two doubly linked lists.
 * @param tail1_tail2 tail pointers of two doubly linked lists. 
 * @return return zero or non zero values.
 */
#include "apc.h"
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	//carry variable to store the borrow.
	int carry=0;
	//sum variable to store the sum of each nodes.
	int sum=0;
	//count variables for comparission of lists.
	extern int count1;
	extern int count2;
	*headR=NULL;
	*tailR=NULL;
	Dlist *temp1=NULL;
	Dlist *temp2=NULL;
	//comparisson between lists.
	if(count1>count2){
	temp1=*tail1;
	temp2=*tail2;
	}
	else if(count1<count2){
	temp1=*tail2;
	temp2=*tail1;
	}
	else{
		//traversing through the lists incase of equal count of nodes in d lists.
	if(compare_lists(*head1, *head2) >= 0){
	temp1=*tail1;
	temp2=*tail2;
	}
	else{
	temp1=*tail2;
	temp2=*tail1;
	}
	}
	int i=0;
	//traversing through the lists untill second d lists become null.
	while(temp2!=NULL){
		sum=0;
		if(temp2!=NULL){
			//calculating sum incase of carry is present.
			if(carry==1){
				temp1->data=temp1->data-carry;
				carry=0;
			}
			//calculating incase of temp2 data greater than temp1 then we need to add carry for subtraction.
			if(temp2->data>temp1->data){
				temp1->data=temp1->data+10;
				sum=temp1->data-temp2->data;
				carry=1;
			}
			else{
				sum=temp1->data-temp2->data;
			}
			//traversing from tail to head.
			temp1=temp1->prev;
			temp2=temp2->prev;
		}
		//creation of new node to add into the result list.
		Dlist *new=malloc(sizeof(Dlist));
		new->data=sum;
		new->next=NULL;
		if(*headR==NULL){
			new->prev=NULL;
			*headR=*tailR=new;
			*tailR=new;
		}
		else{
		new->prev=*tailR;
		(*tailR)->next=new;
		*tailR=new;
		}
		
		
	}
	//traversing  through the first list to find the individual nodes .
	while (temp1!=NULL)
	{
		//appending the last carry into the result list(if carry present).
		if(carry==1){
			temp1->data=temp1->data-carry;
			sum=temp1->data;
			carry=0;
		}
		else{
			sum=temp1->data;
		}
		Dlist *new=malloc(sizeof(Dlist));
		new->data=sum;
		new->next=NULL;
		if(*headR==NULL){
			new->prev=NULL;
			*headR=*tailR=new;
			*tailR=new;
		}
		else{
		new->prev=*tailR;
		(*tailR)->next=new;
		*tailR=new;
		}
		temp1=temp1->prev;
	}
	
	return 0;
}
