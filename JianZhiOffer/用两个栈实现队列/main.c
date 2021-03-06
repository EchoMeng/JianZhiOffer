//
//  main.c
//  用两个栈实现队列
//
//  Created by mac on 2018/1/1.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//使用两个栈结构：一个用来保存数据，另一个用来保存“最小值”数据，每次有数据压栈的时候，与这个栈顶数据比较，如果压栈的数据更小，将这个数据也压入这个栈中，否则再将这个栈顶数据压入栈一次
typedef struct stack {
    int data[100];
    int accessoryData[100]; //accessory附件，附加
    int top;
} Stack;

void push(Stack *stack, int num) {
    if (!stack) {
        return;
    }
    int top = stack->top; //指向栈顶
    
    stack->data[top] = num; //先让数据入栈，然后再比较出是否最小
    
    if (top == 0) {
        stack->accessoryData[top] = num;
    } else if (top >= 100) {
        return;
    } else {
        if (num < stack->accessoryData[top - 1]) {
            stack->accessoryData[top] = num;
        } else {
            stack->accessoryData[top] = stack->accessoryData[top-1];
        }
    }
    ++stack->top;
}

int pop(Stack *stack) {
    if (!stack || stack->top == 0) {
        return 0;
    }
    return stack->data[stack->top - 1];
}

int min(Stack *stack) {
    if (!stack || stack->top == 0) {
        return 0;
    }
    return stack->accessoryData[stack->top - 1];
}

int main(int argc, const char * argv[]) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = 0;
    push(s, 3);
    push(s, 4);
    push(s, 2);
    push(s, 1);
    
    pop(s);
    pop(s);
    
    push(s, 0);
    printf("%d\n",min(s));
    free(s);
    
    return 0;
}
