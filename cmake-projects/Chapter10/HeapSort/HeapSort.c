//
// 힙 정렬
//
// 가장 우선 순위가 높은 것을 작은 수로 정의했으므로
// Heap에다 데이터를 넣고 루트부터 삭제(데이터 꺼내기) 하면 오름차순 정렬이 된다.
//
#include <stdio.h>
#include "EnhancedHeap.h"
#include "CommonUtils.h"

typedef void HeapSortFunc(HData arr[], HData length, PriorityComp pc);

int PriComp(HData n1, HData n2) {
  return n2 - n1;
  // 내림차순 정렬을 하려면 return n1 - n2;
}

void HeapSort(HData arr[], HData length, PriorityComp pc) {
  Heap heap;

  HeapInit(&heap, pc);

  for (int i = 0; i < length; i++) {
    HInsert(&heap, arr[i]);
  }

  int i = 0;
  while (!HIsEmpty(&heap)) {
    arr[i] = HDelete(&heap);
    i++;
  }
}


void testHeapSort(HeapSortFunc sortFunc) {
  HData arr[] = {3, 4, 2, 1};
  int length = sizeof(arr) / sizeof(HData);
  printf("정렬 전: ");
  printArraySimple(arr, length);

  sortFunc(arr, length, PriComp);

  printf("정렬 후: ");
  printArraySimple(arr, length);
}


int main(void) {
  testHeapSort(HeapSort);
  return 0;
}