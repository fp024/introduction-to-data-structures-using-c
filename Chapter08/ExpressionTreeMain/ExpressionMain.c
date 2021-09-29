/**
 * ExpressionMain.c
 */

#include <stdio.h>
#include "ExpressionTree.h"

int main(void) {
    char exp[] = "12+7*";
    BTreeNode* eTree = MakeExpTree(exp);

    printf("전위 표기법의 수식: ");
    ShowPrefixTypeExp(eTree); // * + 1 2 7
    printf("\n");

    printf("중위 표기법의 수식: ");
    ShowInfixTypeExp(eTree); // 1 + 2 * 7
    printf("\n");

    printf("후위 표기법의 수식: ");
    ShowPostfixTypeExp(eTree); // 1 2 + 7 *
    printf("\n");

    printf("연산의 결과: %d\n", EvaluateExpTree(eTree));

    // 문제 8 확인
    char expEx08[] = "327*+";
    BTreeNode* eTreeEx08 = MakeExpTree(expEx08);

    printf("문제8번 결과 확인 - 괄호 포함된 중위 표기법의 수식: ");
    ShowInfixTypeExp(eTreeEx08); //  ( 3 + ( 2 * 7  ) )
    printf("\n");

    return 0;
}