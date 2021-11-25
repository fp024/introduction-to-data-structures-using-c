#include "CommonUtils.h"

// 내가 한 내용도 저자님과 비슷한데,
// 다른점이 비교를 진행해나가면서 바로 데이터 스왑을 했다.
// 저자님은 가장 큰 값의 인덱스를 임시 변수에 넣고 외곽 for문 종료 직전에
// 교환하는 식으로 하셨다.
/*
void SelectionSort(int arr[], int length) {
  for (int i = 0; i < (length - 1); i++) {
    for (int j = i + 1; j < length; j++) {
      if (arr[i] > arr[j]) {
        swap(arr, i, j);
      }
    }
    printArraySimple(arr, length);
  }
}
*/

/*
  책의 maxIdx라는 변수명이 혼선을 유발하는 것 같다.
  값자체로는 제일 작은 값의 인덱스여서, minIdx가 나아보이는데, 일단 바꿨다.
 */
void SelectionSort(int arr[], int length) {
  for (int i = 0; i < (length - 1); i++) {
    int minIdx = i;

    for (int j = i + 1; j < length; j++) {
      if (arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }
    swap(arr, i, minIdx);
    printArraySimple(arr, length);
  }
}


int main() {
  int numbers[] = {3, 2, 4, 1};
  int length = sizeof(numbers) / sizeof(int);

  SelectionSort(numbers, length);

  return 0;
}
