//
//  main.c
//  从上至下遍历二叉树
//
//  Created by mac on 2018/1/3.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//从上至下遍历二叉树，即二叉树的层序遍历。
//思路：使用一个队列，首先将二叉树的根节点入队，然后打印根结点的值，接着判断根结点
//是否有左右孩子，如果有，将左右孩子入队。如此循环直到队列为空。

//定义节点
typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
} BinaryTreeNode;
//定义队列

typedef struct {
    BinaryTreeNode *data[100];
    int head;
    int tail;
} BinaryTreeNodeQueue;

void enQueue(BinaryTreeNodeQueue *queue, BinaryTreeNode *node) {
    if (!queue || queue->tail >= 100 || !node) { return; }
    queue->data[queue->tail++] = node; //这里是把data中的每一个数据依次放进队列里
}

BinaryTreeNode *outQueue(BinaryTreeNodeQueue *queue) {
    if (!queue || queue->head >= queue->tail) {
        return NULL;
    }
    return queue->data[queue->head++];//这里是在从头到尾遍历队列中的每一个数据
}

bool isQueueEmpty(BinaryTreeNodeQueue *queue) {
    if (!queue) {
        return  true;
    }
    return !(queue->head < queue->tail && queue->tail < 100);
}

void preLiteralTree(BinaryTreeNode *tree) {
    if (!tree) {
        return;
    }
    printf("%d", tree->data);
    preLiteralTree(tree->leftChild);
    preLiteralTree(tree->rightChild);
}

void destoryTree(BinaryTreeNode *tree) {
    if (!tree) {
        return;
    }
    
    destoryTree(tree->leftChild);
    destoryTree(tree->rightChild);
    free(tree);
}

BinaryTreeNode *createExampleTree1() {
    BinaryTreeNode *tree =(BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
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

void literalBinaryTreeFromTop(BinaryTreeNode *tree) {
    BinaryTreeNodeQueue *queue = (BinaryTreeNodeQueue *)malloc(sizeof(BinaryTreeNodeQueue));
    queue->head = 0;
    queue->tail = 0;
    enQueue(queue, tree);
    BinaryTreeNode *node = NULL;
    while (!isQueueEmpty(queue)) {
        node = outQueue(queue);
        printf("%d", node->data);
        !node->leftChild? :enQueue(queue, node->leftChild);
        !node->rightChild? :enQueue(queue, node->rightChild);
    }
    printf("\n");
    free(queue);
}


int main(int argc, char *argv[]) {
    BinaryTreeNode *tree = createExampleTree1();
    literalBinaryTreeFromTop(tree);
    destoryTree(tree);
    return 0;
}

