/**
 * SimpleHeapMain.c
 */

#include <stdio.h>
#include "SimpleHeap.h"


 /**
  * 힙 형태로 저장한 배열 출력
  */
int printArray(HeapElem array[], int lastIndex) {
    printf("---------------\n");
    for (int i = 1; i <= lastIndex; i++) {
        printf("array[%d]=%c \n", i, array[i].data);
    }
    printf("---------------\n");
}


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
    printArray(heap.heapArr, heap.numOfData);
    // === A === 
    // 어떤 노드가 왼쪽, 오른쪽 노드 둘다가지고 있고, 그 두자식의 우선순위가 같다면, 오른쪽을 반환하게 우선순위 설정함수가 구현되어있다.
    /*
         B
        / \
       B   C
      /
     C
    */

    while (!HIsEmpty(&heap)) {
        printf("%c \n", HDelete(&heap));
        printArray(heap.heapArr, heap.numOfData);
    }
  
     // === B === 
     /*
            B
           / \
          C   C         
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