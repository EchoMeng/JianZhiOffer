//
//  main.c
//  链表中倒数第k个结点
//
//  Created by mac on 2018/1/3.
//

#include <stdio.h>
#include <stdlib.h>
//输入一个链表，输出链表中倒数第k个结点
//相关题目可使用相似的方法：
//1、找到链表的中间结点；
//2、检测单向链表中是否存在环。

typedef struct node {
    int data;
    struct node *next;
} ListNode;

ListNode *tailKthNode(ListNode *head, int k) {//head头结点，在第一个结点之前，next专门用于存放链表第一结点的指针，data存放结点总数
    if (!head || k <=0 || k > head->data) {
        return NULL;
    }
    ListNode *headNode = head->next;
    ListNode *tailNode = head->next;
    
    for (int i = k - 1; i > 0; --i) {
        headNode = headNode->next;
    }//使headNode最终指向第k个结点，也就是说headNode和tailNode之间的距离为k
    
    while (headNode->next) {//headNode和tailNode同时向后移动，一直移动到headNode指向最后一个结点，那么tailNode就会自然指向倒数第k个结点
        headNode = headNode->next;
        tailNode = tailNode->next;
    }
    return tailNode;
}


ListNode *createExampleList() {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    head->data = 0;
    ListNode *p = head;
    for (int i = 0; i < 10; ++i) {
        ListNode *n = (ListNode *)malloc(sizeof(ListNode));
        n->data = i;
        n->next = NULL;
        p->next = n;
        p = n;
        ++head->data;
    }
    return head;
}

int main(int argc, char *argv[]) {
    ListNode *head = createExampleList();
    printf("%d\n",tailKthNode(head, 7)->data);
    return 0;
}
