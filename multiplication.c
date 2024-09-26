/**************************************************************************************************************************************************************
*Author		:Manoharan Balakrishnan
*Date		: 12-08-2024
*Title		: multiplication function
*Description: This function is used for the multiplication operation.
***************************************************************************************************************************************************************/
#include "apc.h"

/**
 * @brief to perform the multiplication operation in the APC.
 * @param headR_tailR head and tail pointers to store the results.
 * @param head1_and_head2 head pointers of two doubly linked lists.
 * @param tail1_tail2 tail pointers of two doubly linked lists. 
 * @return return zero or non zero values.
 */
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR){
	//temporary pointer to traverse.
	Dlist *tth=*tail1;
	//temporary pointer to traverse.
	Dlist *ttt=*tail2;
	
	//temporary pointers to store one order.
	Dlist *temp1=NULL;
	Dlist *temp1t=NULL;

	//temporary pointer to store temp1 and temp2 lists.
	Dlist *temp3=NULL;
	Dlist *temp3t=NULL;

	int i=0;

	//traversing through the multiplicand.
	while(ttt!=NULL){
		//carry variable.
		int carry=0;
		tth=*tail1;
		Dlist *temp2=NULL;
		Dlist *temp2t=NULL;
		//traversing through the number which is going to be multiplied.
		while(tth!=NULL){
			int sum=(tth->data*ttt->data)+carry;
			carry=sum/10;
			sum=sum%10;

			Dlist *new=malloc(sizeof(Dlist));
			new->data=sum;
			new->next=NULL;
			new->prev=NULL;

			if(temp2==NULL){
				temp2=temp2t=new;
			}
			else{
				temp2->prev=new;
				new->next=temp2;
				temp2=new;
			}
			tth=tth->prev;
		}
		//appending carry to the list.
		if(carry>0){
			Dlist *new=malloc(sizeof(Dlist));
			new->data=carry;
			new->prev=NULL;
			new->next=temp2;
			temp2->prev=new;
			temp2=new;
		}
		//appending the leading zeros.
		for(int j=0;j<i;j++){
			Dlist *new=malloc(sizeof(Dlist));
			new->data=0;
			(temp2t)->next=new;
			new->next=NULL;
			new->prev=temp2t;
			temp2t=new;
		}
		if(temp1==NULL){
			temp1=temp2;
			temp1t=temp2t;
		}
		else{		
			temp3=NULL;
			temp3t=NULL;
			//function call to add 2 doubly linked lists.
			addition(&temp1,&temp1t,&temp2,&temp2t,&temp3,&temp3t);
			temp1=temp3;
			temp1t=temp3t;
		}
		i++;
		//moving the pointer of multiplicand.
		ttt=ttt->prev;
	} 
	//storing the result into result pointers.
	*headR=temp1;
	*tailR=temp1t;
}