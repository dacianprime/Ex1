/*
 * c_test_candidate.h
 *
 *  Created on: 21 Jul 2017
 *  Author: Simon B
 */

#ifndef C_TEST_CANDIDATE_H_
#define C_TEST_CANDIDATE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct bitree_t *p_bitree_t;
struct bitree_t {
    char current_node[30];
	int instance_count;
    p_bitree_t leftNode;
    p_bitree_t rightNode;
};


/* function prototypes */
p_bitree_t createNode(char *p_text);
void displayItems (p_bitree_t treeToDisplay);
void processNode(p_bitree_t *p_tree, char *p_string);


#endif /* C_TEST_CANDIDATE_H_ */
