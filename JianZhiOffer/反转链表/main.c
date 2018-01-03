//
//  main.c
//  反转链表
//
//  Created by mac on 2018/1/3.
//

#include <stdio.h>
#include <stdlib.h>
//方法有多种https://lzhenhong.github.io/2016/10/16/Reverse-Linked-List/
typedef struct node {
    int data;
    struct node *next;
}ListNode;

void reverseList(ListNode *head) {
    if (!head || !head->next || !head->next->next) {
        return;
    }
    ListNode *preNode = head->next;
    ListNode *midNode = preNode->next;
    ListNode *lastNode = midNode->next;
    preNode->next = NULL;
    while (lastNode) {
        midNode->next = preNode;
        preNode = midNode;
        midNode = lastNode;
        lastNode = lastNode->next;
    }
    midNode->next = preNode;
    head->next = midNode;
}

ListNode *createExampleList() {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
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

void destoryList(ListNode *head) {
    if (!head) {
        return;
    }
    ListNode *p = head;
    ListNode *q = head->next;
    while (p->next) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

int main(int argc, char *argv[]) {
    ListNode *head = createExampleList();
    reverseList(head);
    ListNode *n = head->next;
    while (n) {
        printf("%d ",n->data);
        n = n->next;
    }
    printf("\n");
    destoryList(head);
    return 0;
}
