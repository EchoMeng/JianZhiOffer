//
//  main.c
//  二叉树的镜像
//
//  Created by mac on 2018/1/3.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;

void MirrorBinaryTree (BinaryTreeNode *tree) {
    if (!tree) {
        return;
    }
    MirrorBinaryTree(tree->leftChild);
    MirrorBinaryTree(tree->rightChild);
    
    BinaryTreeNode *node = tree->leftChild;
    tree->leftChild = tree->rightChild;
    tree->rightChild = node;
}

void preLiteralTree(BinaryTreeNode *tree) {
    if (!tree) {
        return;
    }
    printf("%d ",tree->data);
    preLiteralTree(tree->leftChild);
    preLiteralTree(tree->rightChild);
}

void midLiteralTree(BinaryTreeNode *tree) {
    if (!tree) {
        return;
    }
    preLiteralTree(tree->leftChild);
    printf("%d ",tree->data);
    preLiteralTree(tree->rightChild);
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
    tree->data = 0;
    tree->rightChild = NULL;
    
    BinaryTreeNode *node1 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node1->data = 1;
    node1->rightChild = NULL;
    tree->leftChild = node1;
    
    BinaryTreeNode *node2 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node2->data = 2;
    node2->rightChild = NULL;
    node1->leftChild = node2;
    
    BinaryTreeNode *node3 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node3->data = 3;
    node3->leftChild = NULL;
    node3->rightChild = NULL;
    node2->leftChild = node3;
    
    return tree;
}

int main(int argc, char *argv[]) {
    BinaryTreeNode *tree1 = createExampleTree1();
    BinaryTreeNode *tree2 = createExampleTree2();
    MirrorBinaryTree(tree1);
    MirrorBinaryTree(tree2);
    midLiteralTree(tree1);
    printf("\n");
    destoryTree(tree1);
    midLiteralTree(tree2);
    printf("\n");
    destoryTree(tree2);
    return 0;
}

