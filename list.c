#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct node*
newNode(int n) {
  struct node *element = NULL;

  if ((element = malloc(sizeof(struct node))) == NULL) {
    fprintf(stderr, "Malloc error at line %d in file %s\n", __LINE__, __FILE__);
    return NULL;
  }

  element->n = n;
  element->next = NULL;

  return element;
}

void
freeNode(struct node* element) {
  if (element != NULL) {
    free(element);
    element = NULL;
  }
}

int
addAsHead(struct node **list, int n) {
  struct node *newElement = newNode(n);

  if (newElement == NULL) {
    return -1;
  }

  if (list == NULL) {
    *list = newElement;
    return 0;
  }

  newElement->next = *list;
  *list = newElement;

  return 0;
}

int
addAsTail(struct node **list, int n) {
  struct node *newElement = newNode(n);
  struct node *tmp;

  if (newElement == NULL) {
    return -1;
  }

  if (list == NULL) {
    *list = newElement;
    return 0;
  }

  // move to the end of the list
  for (tmp = *list; tmp->next != NULL; tmp = tmp->next);

  tmp->next = newElement;

  return 0;
}

int
addAfter(struct node **list, int n, int value) {
  struct node *tmp;
  struct node *elementToInsert;

  for (tmp = *list; tmp != NULL && tmp->n != value; tmp = tmp->next);

  if (tmp == NULL) {
    return -1;
  }

  if ((elementToInsert = newNode(n)) == NULL) {
    return -1;
  }

  elementToInsert->next = tmp->next;
  tmp->next = elementToInsert;

  return 0;
}

int
addBefore(struct node **list, int n, int value) {
  struct node *tmp;
  struct node *elementToInsert;

  for (tmp = *list; tmp->next != NULL && tmp->next->n != value; tmp = tmp->next);

  if (tmp->next == NULL) {
    return -1;
  }

  if ((elementToInsert = newNode(n)) == NULL) {
    return -1;
  }

  elementToInsert->next = tmp->next;
  tmp->next = elementToInsert;

  return 0;
}

void
printList(struct node *list) {
  for (; list != NULL; list = list->next) {
    printf("%d -> ", list->n);
  }

  printf("NULL\n");
}

void
freeHead(struct node **list) {
  struct node *tmp = *list;

  *list = (*list)->next;

  freeNode(tmp);
}

void
freeList(struct node **list) {
  while(*list != NULL) {
    freeHead(list);
  }
}
