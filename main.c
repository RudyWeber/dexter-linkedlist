#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int
main() {
  struct node *list = NULL;

  printList(list);

  addAsHead(&list, 3);  
  printList(list);
  
  addAsHead(&list, 1);
  printList(list);

  addAsTail(&list, 4);
  printList(list);

  addBefore(&list, 2, 3);
  printList(list);

  freeList(&list);
  printList(list);

  return EXIT_SUCCESS;
}
