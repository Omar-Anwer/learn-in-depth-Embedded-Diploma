/*
 * Linked_List.h
 *
 *  Created on: Mar 27, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef int Node_ItemType;

typedef struct Node Node;

struct Node
{
    Node_ItemType item;
    Node* next;
};

typedef struct
{
    Node* head;
    Node* tail;
    unsigned int length;
}List;


#endif /* LINKED_LIST_H_ */
