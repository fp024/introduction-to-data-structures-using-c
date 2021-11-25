//
// 공통 사용자 정의 함수 유틸리티 라이브러리
//
#include <stdio.h>
#include "CommonUtils.h"

void printArray(int array[], int length) {
  for (int i = 0; i < length; i++) {
    printf("array[%d]= %d\n", i, array[i]);
  }
}

void printArraySimple(int array[], int length) {
  for (int i = 0; i < length; i++) {
    if (i == length - 1) {
      printf("%d\n", array[i]);
      break;
    }
    printf("%d, ", array[i]);
  }
}

void swap(int array[], int aIndex, int bIndex) {
  int temp = array[aIndex];
  array[aIndex] = array[bIndex];
  array[bIndex] = temp;
}
