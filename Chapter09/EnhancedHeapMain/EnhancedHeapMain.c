﻿/**
 * EnhancedHeapMain.c
 */
#include <stdio.h>
#include "EnhancedHeap.h"

 /**
  * Heap에 전달할 사용자 정의 우선순위 비교 함수
  */
int DataPriorityComp(HData d1, HData d2) {
    return d2 - d1;  // 아스키 코드로 작은 정수가 우선순위가 높으므로.. 이렇게 된다.
}

int main(void) {
    Heap heap;
    HeapInit(&heap, DataPriorityComp); // 힙의 초기화

    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
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

    HInsert(&heap, 'A');
    /*
           A
          / \
         C   B
    */

    HInsert(&heap, 'B');
    /*
           A
          / \
         B   B
        /
       C
    */

    HInsert(&heap, 'C');
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