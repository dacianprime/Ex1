/*
 =======================================================================================
 Name        : c_test_candidate.c
 Author      : simon b
 Version     :
 Copyright   : Your copyright notice
 Description : C test
             : Represent a number of strings using a binary tree data structure
             : Print out each string and it's number of occurences in alphabetical order
 =======================================================================================*/


#include "c_test_candidate.h"

/*======================================================================================
 *  function   : createNode
 *  description: creates a Node from a given string
 *  parameters : pointer to a given string
 *  returns    : pointer to the new node instance
 *======================================================================================*/

p_bitree_t createNode(char *p_text)
{
	p_bitree_t bitree_instance = (p_bitree_t) malloc(sizeof(struct bitree_t));
	    (void)strcpy(bitree_instance->current_node, p_text);

	    bitree_instance->instance_count = 1;
	    bitree_instance->leftNode = NULL;
	    bitree_instance->rightNode = NULL;
	    return(bitree_instance);
}


/*======================================================================================
 *  function   : displayItems
 *  description: displays in alphabetical order each node and the number of instances
 *  parameters: pointer to the binary tree
 *  returns   : nothing
 *======================================================================================*/

void displayItems (p_bitree_t treeToDisplay)
{
	if (treeToDisplay == NULL)						/* contains no items */
         return;

	displayItems(treeToDisplay->leftNode);			/* display left node */

    printf("%s %d\n", treeToDisplay->current_node, treeToDisplay->instance_count); /* display number of node instances */

    displayItems(treeToDisplay->rightNode);			/* display right node */
}


/*======================================================================================
 *  function   : processNode
 *  description: places each node in position within the data structure
 *  parameters : pointer to the binary tree, pointer to the string
 *  returns    : nothing
 *======================================================================================*/

void processNode(p_bitree_t *p_tree, char *p_string)
{

	if(*p_tree == NULL)											/* special case for first node */
         *p_tree = createNode(p_string);

	else														/* data structure already exists */
    {
        int strCmpVal = strcmp(p_string, (*p_tree)->current_node);	/* compare new text string with existing item */

        if (strCmpVal == 0)										/* string already exists.. don't add node */
            (*p_tree)->instance_count++;						/* increment number of occurences to existing node*/

        else if (strCmpVal < 0)									/* new string < existing string */
        {
        	processNode (&(*p_tree)->leftNode,p_string); 		/* create a new left node */
        }
       	else													/* new string > existing string */
        {
        	processNode (&(*p_tree)->rightNode,p_string);		/* create a new right node */
        }
    }
}

int main(void)
{
    p_bitree_t pNodeInstance = NULL;

    processNode(&pNodeInstance, "toffee");						/* add nodes */
    processNode(&pNodeInstance, "bandit");
    processNode(&pNodeInstance, "cat");
    processNode(&pNodeInstance, "bandit");

    displayItems(pNodeInstance);								/* display nodes and number of instances */

    return (0);
}

