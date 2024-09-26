/**************************************************************************************************************************************************************
*Author        :Manoharan Balakrishnan
*Date          : 12-08-2024
*Title         : Division Function
*Description   : This function is used for the division operation.
***************************************************************************************************************************************************************/
#include "apc.h"

/**
 * @brief to perform the division operation in the APC.
 * @param headR_tailR head and tail pointers to store the results.
 * @param head1_and_head2 head pointers of two doubly linked lists.
 * @param tail1_tail2 tail pointers of two doubly linked lists. 
 * @return SUCCESS or FAILURE.
 */

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) {
    //temporary pointer to traverse through the first list.
	Dlist *temp1 = *tail1;
	//temporary pointer to traverse through the second list.
    Dlist *temp2 = *tail2;
    //temporary pointer for result.
	Dlist *temp3 = NULL;

	//variable to validate whether the second operand is zero or not.
    int zero = 1;
	//variable to add the quotient in the result list. 
    int count = 0;
	//carry variable for subtraction.
    int carry = 0;

    // Check if the divisor is zero
    while (temp2 != NULL) {
        if (temp2->data > 0) {
            zero = 0;
            break;
        }
        temp2 = temp2->prev;
    }
    if (zero) {
        printf("INFO: You cannot divide anything by zero\n");
        return FAILURE;
    }

    temp2 = *tail2;

    // Division by subtraction logic
    while (carry != 1) {
        temp1 = *tail1;
        temp2 = *tail2;
        carry = 0;
		//running a loop until both of the lists reaches null.
        while (temp1 || temp2) {
            if (temp1 != NULL && temp2 != NULL) {
				//making changes based on the carry
                if (carry == 1) {
                    if (temp1->data == 0) {
                        temp1->data = 9;
                        carry = 1;
                    } else {
                        temp1->data -= 1;
                        carry = 0;
                    }
                }
				//case for if the first list's node is greater than the second lists node.
                if (temp1->data >= temp2->data) {
                    temp1->data = temp1->data - temp2->data;
                } else {
					//case where the second node data is greater.
                    temp1->data = (temp1->data + 10) - temp2->data;
                    carry = 1;
                }
                temp1 = temp1->prev;
                temp2 = temp2->prev;
            } else if (temp1 == NULL && temp2 != NULL) {
				//appending the count value at the head. 
                res_insert_at_first(headR, &temp3, count % 10);
                return SUCCESS;
            } else {
				//traversing through first list until it reaches null.
                while (temp1 != NULL) {
                    if (carry == 1) {
                        if (temp1->data == 0) {
                            temp1->data = 9;
                            carry = 1;
                        } else {
                            temp1->data -= 1;
                            carry = 0;
                        }
                    }
                    temp1 = temp1->prev;
                }
            }
        }
		//appending carry at head of the result node.
        if (carry == 1) {
            if (count == 0) {
                res_insert_at_first(headR, &temp3, count);
            }
            while (count) {
                res_insert_at_first(headR, &temp3, count % 10);
                count /= 10;
            }
        }
        count++;
    }
    return SUCCESS;
}
/**
 * @brief to perform the division operation in the APC.
 * @param headR head pointer to store the results.
 * @param tailR tail pointer to store the results.
 * @param data data to be stored at the head of result node.
 * @return SUCCESS or FAILURE.
 */
int res_insert_at_first(Dlist **headR, Dlist **tailR, int data) {
    // Create a new node
    Dlist *new_node = (Dlist *)malloc(sizeof(Dlist));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    // If the list is empty, update both head and tail to the new node
    if (*headR == NULL) {
        *headR = new_node;
        *tailR = new_node;
    } else {
        // Insert the new node at the beginning
        new_node->next = *headR;
        (*headR)->prev = new_node;
        *headR = new_node;
    }
    return 0;
}