#include <stdio.h>
#include "CommonUtils.h"

/**
 * 내 코드와 저자님 코드의 테스트를 규격화하기 위해 함수 포인터를 사용해보자!
 */
typedef void SortFunc(int arr[], int length);

/**
 * 삽입 정렬
 *
 * 저자님이 진행한 내용하고 코드가 약간 다른 데,
 * 동작의 개념은 같은 것 같다.
 *
 * @param arr       정렬할 배열
 * @param length    정렬할 배열의 길이
 */
void MyInsertionSort(int arr[], int length) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = i + 1; j > 0; j--) {
      if (arr[j] < arr[j - 1]) { // 자리를 찾는 조건, 직전 값과 비교해서 앞이 작다면 자리를 교환한다.
        swap(arr, j, j - 1);
      } else { // 직전 값이 크거나 같다면 이동없이 끝낸다.
        break;
      }
      printArraySimple(arr, length);
    }
  }
}


/**
 * 저자님의 삽입 정렬
 *
 * @param arr  정렬할 배열
 * @param n    정렬할 배열의 길이
 */
void InsertionSort(int arr[], int n) {
  int i, j;
  int insData;

  for (i = 1; i < n; i++) {
    insData = arr[i];

    for (j = i - 1; j >= 0; j--) {
      if (arr[j] > insData) {
        arr[j + 1] = arr[j];
      } else {
        break;
      }
      // 책에 오탈자가 있었다. arr[j + 1] = insData; 이 되면
      // 정상적인 삽입위치가 아니라 교환이 일어난 위치에
      // 다시 삽입해서 정렬이 올바르게되지 않는다.
      arr[j] = insData;
      printArraySimple(arr, n);
    }
  }
}

void testCode(SortFunc sortFunc) {
  int numbers[] = {5, 3, 2, 4, 1};
  int length = sizeof(numbers) / sizeof(int);
  printf("일반 배열 삽입 정렬\n");
  sortFunc(numbers, length);
  printf("=> ");
  printArraySimple(numbers, length);
  printf("\n");

  int sortedNumbers[] = {1, 2, 3, 4, 5};
  length = sizeof(sortedNumbers) / sizeof(int);
  printf("정렬된 배열 삽입 정렬\n");
  sortFunc(sortedNumbers, length); // 정렬된 배열은 데이터 교환이 한번도 일어나지 않는다. 정렬된 배열의 정렬 진행 경우에만 O(n)이 아닌지?
  printf("=> ");
  printArraySimple(sortedNumbers, length);
}


int main() {
  testCode(MyInsertionSort);
  printf("\n====================\n");
  testCode(InsertionSort);
  return 0;
}
