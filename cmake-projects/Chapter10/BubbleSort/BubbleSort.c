#include "CommonUtils.h"
#include <stdio.h>

int main() {
    int numbers[] = {3, 2, 4, 1};
    int length = sizeof(numbers) / sizeof(int);

    // TODO
    printf("한글\n");

    printArray(numbers, length);
    return 0;
}
