#ifndef __LIST_H__
#define __LIST_H__

struct node {
  int n;
  struct node *next;
};

void freeNode(struct node*);
int addAsHead(struct node**, int);
void printList(struct node *);
void freeHead(struct node **);
void freeList(struct node **);
int addAsTail(struct node **, int);
int addAfter(struct node **, int, int);
int addBefore(struct node **, int, int);

#endif
