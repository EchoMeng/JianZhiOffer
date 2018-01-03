//
//  main.c
//  从上至下遍历二叉树
//
//  Created by mac on 2018/1/3.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
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
    return queue->data[queue->head++];
}

void destoryTree(BinaryTreeNode *tree) {
    
}

