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



int EvaluateExpTree(BTreeNode* bt) {
    // TODO:
    return -1;
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


void ShowInfixTypeExp(BTreeNode* bt) {
    InorderTraverse(bt, ShowNodeData);
}


void ShowPostfixTypeExp(BTreeNode* bt) {
    PostorderTraverse(bt, ShowNodeData);
}
