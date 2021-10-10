/**
 * SimpleHeapMain.c
 */

#include <stdio.h>
#include "SimpleHeap.h"

int main(void) {
    Heap heap;
    HeapInit(&heap); // 힙의 초기화

    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    /*
           A
          / \
         B   C
    */

    printf("%c \n", HDelete(&heap));
    /*
           B
          /
         C
    */
    printf("------------- \n");

    HInsert(&heap, 'A', 1);
    /*
           A
          / \
         C   B
    */

    HInsert(&heap, 'B', 2);
    /*
           A
          / \
         B   B
        /
       C
    */

    HInsert(&heap, 'C', 3);
    /*
           A
          / \
         B   B
        / \
       C   C
     */
    printf("%c \n", HDelete(&heap));
    // === A === 
    /*
         B
        / \
       C   B
      /
     C
    */

    while (!HIsEmpty(&heap)) {
        printf("%c \n", HDelete(&heap));
    }
  
     // === B === 
     /*
            B
           /
          C
         /
        C
     */

     // === B === 
     /*
            C
           /
          C
     */

     // === C === 
     /*
           C
     */
         
     // === C ===
     /*
           비워짐
     */
    return 0;
}