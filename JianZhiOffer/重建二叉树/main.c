//
//  main.c
//  二维数组中的查找
//
//  Created by mac on 2018/1/1.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//二叉搜索树的左子树的值都小于或者等于根节点，右子树的值都大于或者等于根节点。

//二叉树的特例：
//1.堆：堆分为最大堆和最小堆。在最大堆中根节点的值最大，最小堆中根节点的值最小。
//2.红黑树：树中的节点分为红黑两种，并通过规则确保从根节点到叶节点的最长路径不超过最短路径的两倍。

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;

BinaryTreeNode *createBinaryTreeCore(int *preorder, int *midorder, int count) {
    if (!preorder || !midorder || count <= 0) { return NULL; }
    
    int c = 0;
    for (int i = 0; i < count; ++i) {
        if (midorder[i] == preorder[0]) { //preorder[0]为root结点，先序遍历的第一个结点。对于中序遍历，root是位于中间的，遍历到这个位置就break，是想要区分root左/右？最终c的大小是左节点总数
            break;
        } else {
            ++c;
        }
    }
    
    BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode)); //使用malloc方法分配内存
    //早期的C实现无法用结构直接当作参数在函数间传递，只能用指向结构的指针在函数间进行传递->
    node->data = preorder[0];
    node->leftChild = createBinaryTreeCore(preorder + 1, midorder, c);//中序遍历二叉树，是从最左边的第一个结点开始遍历的
    node->rightChild = createBinaryTreeCore(preorder + c + 1, midorder + c + 1, count - c - 1);
    
    return node;
}

void preLog(BinaryTreeNode *tree) {
    if (!tree) { return; }
    printf("%d ",tree->data);
    preLog(tree->leftChild);
    preLog(tree->rightChild);
}

void midLog(BinaryTreeNode *tree) {
    if (!tree) { return; }
    midLog(tree->leftChild);
    printf("%d ",tree->data);
    midLog(tree->rightChild);
}

void sufLog(BinaryTreeNode *tree) {
    if (!tree) { return; }
    sufLog(tree->leftChild);
    sufLog(tree->rightChild);
    printf("%d ",tree->data);
}

void destoryTree(BinaryTreeNode *tree) {
    if (!tree) { return; }
    destoryTree(tree->leftChild);
    destoryTree(tree->rightChild);
    free(tree);
}

int main(int argc, const char * argv[]) {
    int preorder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int midorder[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    int c = 8;
    
    BinaryTreeNode *tree = createBinaryTreeCore(preorder, midorder, c);
    preLog(tree);
    printf("\n");
    
    midLog(tree);
    printf("\n");
    
    sufLog(tree);
    printf("\n");
    
    destoryTree(tree);
    return 0;
}

