//
//  main.c
//  合并两个排序的链表
//
//  Created by mac on 2018/1/3.
//

#include <stdio.h>
#include <stdlib.h>
//输入两个单调递增的链表，输出两个链表合成后的链表，要求合成后的链表满足单调不减规则

typedef struct node {
    int data;
    struct node *next;
} ListNode;

ListNode *mergeListNode(ListNode *head1, ListNode *head2) {
    if (!head1) {
        return head2;
    } else if (!head2) {
        return head1;
    }
    
    ListNode *newHead = (ListNode *)malloc(sizeof(ListNode));
    newHead->data = head1->data + head2->data;
    
    ListNode *p = head1->next;
    ListNode *q = head2->next;
    ListNode *k = newHead;
    
    while (p && q) {
        if (p->data > q->data) {
            k->next = q;
            q = q->next;
        } else {
            k->next = p;
            p = p->next;
        }
        k = k->next;
    }
    
    if (p && !q) {
        k->next = p;
    } else if (!p && q) {
        k->next = q;
    }
    return newHead;
}

ListNode *createExampleNode1() {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = 0;
    head->next = NULL;
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

ListNode *createExampleNode2() {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = 0;
    head->next = NULL;
    ListNode *p = head;
    for (int i = 0; i < 15; ++i) {
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
    while (q) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

int main(int argc, char *argv[]) {
    ListNode *head1 = createExampleNode1();
    ListNode *head2 = createExampleNode2();
    ListNode *newHead = mergeListNode(head1, head2);
    ListNode *p = newHead->next;
    while (p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    //    destoryList(head1);
    //    destoryList(head2);
    free(head1);
    free(head2);
    //这里使用destroy会报错，为什么呢？malloc: *** error for object 0x1018554a0: pointer being freed was not allocated
    destoryList(newHead);
    
    return 0;
}
