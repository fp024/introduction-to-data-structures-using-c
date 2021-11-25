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
        printf("%d", array[i]);
        if(i < length - 1) {
            printf(", ");
        }
    }
    printf("\n");
}