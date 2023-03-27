/*
 * Linked_List.c
 *
 *  Created on: Mar 27, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */

#include "Linked_List.h"


void List_Init(List* list)
{
  list->head = 0;
  list->tail = 0;
  list->length = 0;
}


int List_isEmpty(List* const list)
{
  return (list->head == 0);
}

void List_pushBack(List* const list, const Node_ItemType item)
{
  /* Create a new node dynamically */
  Node* n = (Node *)malloc( sizeof(Node) );

  /*if the node is create Successfully*/
  if(n != 0){
    n->item = item;
    n->next = 0;

    /* in case of empty list*/
    if( List_isEmpty(list) ){
      list->head = n;
    }
    else{
      list->tail->next = n;
    }

    list->tail = n;
    list->length++;
  }
}
void List_pushFront(List* const list, const Node_ItemType item)
{
  /* Create a new node dynamically */
  Node* n = (Node *)malloc( sizeof(Node) );

  /*if the node is create Successfully*/
  if(n != 0)
  {
    n->item = item;

    if( List_isEmpty(list) ){
      list->tail = n;
    }
    else{
      n->next = list->head;
    }
    list->head = n;
    list->length++;
  }
}

void List_popFront(List* const list, Node_ItemType* item)
{
  if(!List_isEmpty(list))
  {
    *item = list->head->item;
    Node* tmp = list->head->next;
    free(list->head);

    if(list->length == 1){
      list->head = 0;
      free(list->tail);
      list->tail = 0;
    }
    else{
      list->head = tmp;
    }
    list->length--;
  }
  else
  {
    /*empty list*/
  }
}



void List_popBack(List* const list, Node_ItemType* item)
{
  if(!List_isEmpty(list))
  {
    *item = list->tail->item;
    if(list->length == 1)
    {
      free(list->head);
      list->head = 0;
    }
    else
    {
      Node* n = list->head;
      while (n->next->next != 0) {
        n = n->next;
      }
      free(n->next);
      n->next= 0;
      list->tail = n;
    }
    list->length--;
  }
  else
  {
    /*empty list*/
  }


}

unsigned int List_Length(List* const list)
{
  return (list->length);
}

void List_Print(List* const list)
{
  Node* n = list->head;
  while(n != 0)
  {
    printf("%d --> ", n->item);
    n = n->next;
  }
  printf("NULL\n");
}
