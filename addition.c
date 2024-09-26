/**************************************************************************************************************************************************************
*Author		:Manoharan Balakrishnan
*Date		:07-08-2024
*Title		:Addition function
*Description: This function is used for the addition operation.
***************************************************************************************************************************************************************/
#include "apc.h"
/**
 * @brief to perform the addition operation in the APC.
 * @param headR_tailR head and tail pointers to store the results.
 * @param head1_and_head2 head pointers of two doubly linked lists.
 * @param tail1_tail2 tail pointers of two doubly linked lists. 
 * @return return zero or non zero values.
 */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	//carry varible to store the borrow.
	int carry=0;
	//sum variable to store the total of two nodes.
	int sum=0;
	*headR=NULL;
	*tailR=NULL;
	//temporary pointers to traverse through the doubly linked lists.
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	char str[50];
	int i=0;
	//running a loop to traverse through the doubly linked lists.
	while(temp1!=NULL||temp2!=NULL){
		//storing the carry into the sum.
		sum=carry;
		//adding the temp1 node into the sum.
		if(temp1!=NULL){
			sum=sum+temp1->data;
			temp1=temp1->prev;
		}
		//adding the temp2 node into the sum .
		if(temp2!=NULL){
			sum=sum+temp2->data;
			temp2=temp2->prev;
		}
		//calculating the carry value.
		carry=sum/10;
		//calculating the sum variable to store it into the node.
		sum=sum%10;
		//new node which is going to be stored into  the result list.
		Dlist *new=malloc(sizeof(Dlist));
		new->data=sum;
		new->next=NULL;
		new->prev=NULL;
		if(*headR==NULL){
			new->prev=NULL;
			*headR=*tailR=new;
		}
		else{
			new->next=(*headR);
			(*headR)->prev=new;
			*headR=new;
		}
		
		
	}
	//checking whether the carry is there or not after the addition operation.
	if(carry>0){
		//creating a new node to append the carry into the result list.
		Dlist *new=malloc(sizeof(Dlist));
		new->data=carry;
		new->prev=NULL;
		new->next=*headR;
		(*headR)->prev=new;
		*headR=new;
	}
	//end of the function.
	return 0;
}




