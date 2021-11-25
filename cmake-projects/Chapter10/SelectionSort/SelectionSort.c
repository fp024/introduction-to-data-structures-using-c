#include "CommonUtils.h"

// 버블 소트를 진행하려다 선택정렬이 되어버렸다. ㅠㅠ
int main() {
    int numbers[] = {3, 2, 4, 1};
    int length = sizeof(numbers) / sizeof(int);

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
        printArraySimple(numbers, length);
    }

    printArray(numbers, length);
    return 0;
}
