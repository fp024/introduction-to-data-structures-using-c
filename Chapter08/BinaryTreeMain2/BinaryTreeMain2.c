/**
 * BinaryTreeMain2.c
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "BinaryTree2.h"

void ShowIntData(int data);

int main(void) {
    BTreeNode* bt1 = MakeBTreeNode();
    BTreeNode* bt2 = MakeBTreeNode();
    BTreeNode* bt3 = MakeBTreeNode();
    BTreeNode* bt4 = MakeBTreeNode();
    BTreeNode* bt5 = MakeBTreeNode();
    BTreeNode* bt6 = MakeBTreeNode();


    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeRightSubTree(bt3, bt6);


    /*
       p317~318 에서 만들고자 하는 트리 모양

               bt1
             /    \
          bt2      bt3
          /  \       \
       bt4   bt5     bt6

    */

    // 1 -> 2 -> 4 -> 5 -> 3 -> 6
    PreorderTraverse(bt1, ShowIntData);
    printf("\n");

    // 4 -> 2 -> 5 -> 1 -> 3 -> 6
    InorderTraverse(bt1, ShowIntData);
    printf("\n");

    // 4 -> 5 -> 2 -> 6 -> 3 -> 1   (이부분 해깔렸다. 최종 루트를하기전에 right를 끝부터 탐색하게 되네... )
    PostorderTraverse(bt1, ShowIntData);
    printf("\n");


    // 문제 08-1 - 이진트리 노드의 재귀적 소멸
    DeleteTree(&bt1);

    printf("=== 후위 순위로 노드 삭제 이후 출력 ===");
    PostorderTraverse(bt1, ShowIntData);
    printf("\n");

    // Delete 함수에서 free() 처리 및 NULL초기화까지 진행한다.
    assert(bt1 == NULL);

    return 0;
}


void ShowIntData(int data) {
    printf("%d ", data);
}
