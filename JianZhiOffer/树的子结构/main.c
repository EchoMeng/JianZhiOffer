//
//  main.c
//  树的子结构
//
//  Created by mac on 2018/1/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//输入两个二叉树A,B，判断A是不是B的子结构

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;

bool isTwoBinaryTreeEqual(BinaryTreeNode *tree1, BinaryTreeNode *tree2) {
    if (!tree2) {
        return true;
    }
    if (!tree1) {
        return false;
    }
    
    if (tree1->data == tree2->data) {
        return (isTwoBinaryTreeEqual(tree1->leftChild, tree2->leftChild)) && (isTwoBinaryTreeEqual(tree1->rightChild, tree2->rightChild));
    } else {
        return false;
    }
}

bool isSubTres(BinaryTreeNode *tree1, BinaryTreeNode *tree2) {
    if (!tree1 || !tree2) {
        return false;
    }
    bool result = false;
    if (tree1->data == tree2->data) {
        result = isTwoBinaryTreeEqual(tree1, tree2);
    }
    if (!result) {
        result = isSubTres(tree1->leftChild, tree2);
    }
    if (!result) {
        result = isSubTres(tree1->rightChild, tree2->rightChild);
    }
    return result;
}

void destoryTree(BinaryTreeNode *tree) {
    if (!tree) { return; }
    
    destoryTree(tree->leftChild);
    destoryTree(tree->rightChild);
    free(tree);
}

BinaryTreeNode *createExampleTree1() {
    BinaryTreeNode *tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree->data = 0;
    
    BinaryTreeNode *node1 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node1->data = 1;
    tree->leftChild = node1;
    
    BinaryTreeNode *node2 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node2->data = 2;
    tree->rightChild = node2;
    
    BinaryTreeNode *node3 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node3->data = 3;
    node3->leftChild = NULL;
    node3->rightChild = NULL;
    node1->leftChild = node3;
    
    BinaryTreeNode *node4 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node4->data = 4;
    node4->leftChild = NULL;
    node4->rightChild = NULL;
    node1->rightChild = node4;
    
    BinaryTreeNode *node5 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node5->data = 5;
    node5->leftChild = NULL;
    node5->rightChild = NULL;
    node2->leftChild = node5;
    
    BinaryTreeNode *node6 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node6->data = 6;
    node6->leftChild = NULL;
    node6->rightChild = NULL;
    node2->rightChild = node6;
    
    return tree;
}

BinaryTreeNode *createExampleTree2() {
    BinaryTreeNode *tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    tree->data = 2;
    
    BinaryTreeNode *node5 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node5->data = 5;
    node5->leftChild = NULL;
    node5->rightChild = NULL;
    tree->leftChild = node5;
    
    BinaryTreeNode *node6 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node6->data = 6;
    node6->leftChild = NULL;
    node6->rightChild = NULL;
    tree->rightChild = node6;
    
    return tree;
}


int main(int argc, char *argv[]) {
    BinaryTreeNode *tree1 = createExampleTree1();
    BinaryTreeNode *tree2 = createExampleTree2();
    printf("%s\n",isSubTres(tree1, tree2)?"True" : "False");
    destoryTree(tree1);
    destoryTree(tree2);
    return 0;
}
