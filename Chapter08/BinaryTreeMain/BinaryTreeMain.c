#include <stdio.h>
#include "BinaryTree.h"

/**
 * 중위순회 함수
 */
void InorderTraverse(BTreeNode* bt) {
    if (bt == NULL) {
        return;
    }

    InorderTraverse(GetLeftSubTree(bt));
    printf("%d\n", GetData(bt));
    InorderTraverse(GetRightSubTree(bt));
}



/**
 * 전위순회 함수
 */
void PreorderTraverse(BTreeNode* bt) {
    if (bt == NULL) {
        return;
    }

    printf("%d\n", GetData(bt));
    PreorderTraverse(GetLeftSubTree(bt));  
    PreorderTraverse(GetRightSubTree(bt));
}


/**
 * 후위순회 함수
 */
void PostorderTraverse(BTreeNode* bt) {
    if (bt == NULL) {
        return;
    }
    
    PostorderTraverse(GetLeftSubTree(bt));
    PostorderTraverse(GetRightSubTree(bt));
    printf("%d\n", GetData(bt));
}



int main() {
    BTreeNode* bt1 = MakeBTreeNode();   // 노드 bt1 생성
    BTreeNode* bt2 = MakeBTreeNode();   // 노드 bt2 생성
    BTreeNode* bt3 = MakeBTreeNode();   // 노드 bt3 생성
    BTreeNode* bt4 = MakeBTreeNode();   // 노드 bt4 생성

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);

    /*
       p308에서 만들고자 하는 트리 모양

               bt1
             /    \
          bt2      bt3
          /
         bt4
    */

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);


    // bt1의 왼쪽 자식 노드의 데이터 출력
    printf("%d\n", GetData(GetLeftSubTree(bt1)));

    // bt1의 왼쪽 자식노드의 왼쪽 자식노드의 데이터 출력
    printf("%d\n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));


    // 중위순회로 순회 4 -> 2 -> 1 -> 3
    printf("=== 루트에서 중위 순회 ===\n");
    InorderTraverse(bt1);

    printf("=== 루트에서 전위 순회 ===\n"); // 1 -> 2 -> 4 -> 3
    PreorderTraverse(bt1);


    printf("=== 루트에서 후위 순회 ===\n"); // 4 -> 2 -> 3 -> 1
    PostorderTraverse(bt1);

    return 0;
}