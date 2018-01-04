//
//  main.c
//  顺时针打印矩阵
//
//  Created by mac on 2018/1/4.
//

#include <stdio.h>
#include <stdlib.h>
//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数
typedef struct stack {
    int data[100];
    int accessoryData[100];
    int top;
} Stack;

void push(Stack *stack, int num) {
    if (!stack) {
        return;
    }
    int top = stack->top;
    stack->data[top] = num;
    if (top == 0) {
        stack->accessoryData[top] = num;
    } else if (top >= 100) {
        return;
    } else {
        if (num < stack->accessoryData[top - 1]) {
            stack->accessoryData[top] = num;
        } else {
            stack->accessoryData[top] = stack->accessoryData[top - 1];
        }
    }
    ++stack->top;
}

int pop(Stack *stack) {
    if (!stack || stack->top == 0) {
        return 0;
    }
    return stack->data[stack->top--];
}

int min(Stack *stack) {
    if (!stack || stack->top == 0) {
        return 0;
    }
    return stack->accessoryData[stack->top - 1];
}

int main(int argc, char *argv[]) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = 0;
    push(s, 3);
    push(s, 4);
    push(s, 1);
    push(s, 2);
    
    pop(s);
    pop(s);
    
    push(s, 7);
    printf("%d\n",min(s));
    free(s);
    return 0;
}
