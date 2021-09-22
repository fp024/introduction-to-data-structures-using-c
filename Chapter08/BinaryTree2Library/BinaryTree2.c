/**
 * BinaryTree2.c
 *
 * BinaryTree.c 에서
 * 트리 순회 기능 추가
 */
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"


BTreeNode* MakeBTreeNode(void) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


BTData GetData(BTreeNode* bt) {
    return bt->data;
}


void SetData(BTreeNode* bt, BTData data) {
    bt->data = data;
}


BTreeNode* GetLeftSubTree(BTreeNode* bt) {
    return bt->left;
}


BTreeNode* GetRightSubTree(BTreeNode* bt) {
    return bt->right;
}


void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
    // 이부분은 바로 생각 못했다. 순회를 해서 줄줄이 free를 해야하는데, 저자님이 이후 내용에서 하신다고 한다.
    if (main->left != NULL) {
        free(main->left);
    }

    main->left = sub;
}


void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
    if (main->right != NULL) {
        free(main->right);
    }

    main->right = sub;
}



void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
    if (bt == NULL) {
        return;
    }
    action(GetData(bt));
    PreorderTraverse(GetLeftSubTree(bt), action);
    PreorderTraverse(GetRightSubTree(bt), action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
    if (bt == NULL) {
        return;
    }
    InorderTraverse(GetLeftSubTree(bt), action);
    action(GetData(bt));
    InorderTraverse(GetRightSubTree(bt), action);

}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
    if (bt == NULL) {
        return;
    }
    PostorderTraverse(GetLeftSubTree(bt), action);
    PostorderTraverse(GetRightSubTree(bt), action);
    action(GetData(bt));
}



void DeleteTree(BTreeNode** btAddress) {
    /*
        외부 사용처에서 BTreeNode* 로 넘겼을 때, 
        그 사용처의 BTreeNode* 변수 자체를 NULL로 바꾸기 위해선 
        그 변수의 주소를 받아와서 초기화해줄 수 밖에 없다.

        전달 변수가 포인터변수라 또 주소를 얻게되어 2차원 포인터가 되어버렸다.
     */

    if (btAddress == NULL) {
        return;
    }

    BTreeNode* bt = *btAddress;

    if (bt == NULL) {
        return;
    }

    DeleteTree(&(bt->left));
    DeleteTree(&(bt->right));

    free(bt);
    *btAddress = NULL; // free 이후 NULL로 초기화

}
