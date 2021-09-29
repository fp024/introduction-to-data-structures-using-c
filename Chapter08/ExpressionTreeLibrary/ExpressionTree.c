/**
 * ExpressionTree.c
 */
#include <stdio.h>
#include <ctype.h> // isdight()
#include <stdlib.h>
#include <string.h> // strlen()
#include "ListBaseStack.h"
#include "BinaryTree2.h"


BTreeNode* MakeExpTree(char exp[]) {
    Stack stack;
    BTreeNode* pnode;

    size_t expLen = strlen(exp);
    int i;

    StackInit(&stack);

    for (i = 0; i < expLen; i++) {
        pnode = MakeBTreeNode();

        if (isdigit(exp[i])) { // 피연산자 이면...
            SetData(pnode, exp[i] - '0');  // 문자를 정수로 바꿔서 저장, 지금 구현하려는 수식트리는 양수만 처리하고 한자리만 가능하다.
        }
        else { // 연산자이면

            // 피연산자를 스택에 넣을 때, 왼쪽->오른쪽 순으로 넣었으므로
            // 스택에서 꺼낼때 오른쪽 -> 왼쪽 순으로 서브트리를 구성한다.
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));

            SetData(pnode, exp[i]);  // 연산자는 문자 그대로 노드에 넣는다.
        }

        // 피연산자, 연산자 노드들을 스택에 넣는다.
        SPush(&stack, pnode);
    }

    // 스택의 맨위는 수식트리의 최상위 루트노드를 반환하게 됨
    return SPop(&stack);
}



int EvaluateExpTree(BTreeNode* bt) { // bt는 루트가 연산자인 노드다
    int op1, op2;

    // 단말노드라면 ...
    if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) {
        return GetData(bt);
    }

    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));

    switch (GetData(bt)) {
    case '+':
        return op1 + op2;
    case '-':
        return op1 + op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }

    return 0;
}


void ShowNodeData(int data) {
    if (0 <= data && data <= 9) {
        printf("%d ", data);
    }
    else {
        printf("%c ", data);
    }
}


void ShowPrefixTypeExp(BTreeNode* bt) {
    PreorderTraverse(bt, ShowNodeData);
}


/**
 * 문제 08
 * 중위 표기법에 소괄호 넣기  관련 함수 수정
 */
void InorderTraverseForEx08(BTreeNode* bt, VisitFuncPtr action) {
    if (bt == NULL) {
        return;
    }

    // 현재 방문노드가 연산자 노드일때만 괄호 열고 닫게 하는 식으로 했다.
    if (GetLeftSubTree(bt) != NULL || GetRightSubTree(bt) != NULL) {
        printf("( ");
    }

    InorderTraverseForEx08(GetLeftSubTree(bt), action);
    action(GetData(bt));
    InorderTraverseForEx08(GetRightSubTree(bt), action);

    if (GetLeftSubTree(bt) != NULL || GetRightSubTree(bt) != NULL) {
        printf(" )");
    }
}


void ShowInfixTypeExp(BTreeNode* bt) {
    InorderTraverseForEx08(bt, ShowNodeData);
}


void ShowPostfixTypeExp(BTreeNode* bt) {
    PostorderTraverse(bt, ShowNodeData);
}
