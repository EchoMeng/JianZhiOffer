//
//  main.c
//  斐波那契数列
//
//  Created by mac on 2018/1/1.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
//斐波那契数列：前两个数字之和
//递归的问题：
//1.递归是函数调用函数，函数的调用消耗时间和内存，每一次调用函数，都需要在内存栈中分配空间以保存参数/返回地址以及临时变量，而且往栈压入数据和弹出数据也需要时间。
//2.递归还有可能引起栈溢出，每个进程的栈容量是有限的，当递归的层级太多时，就会超出栈的容量。

long long FibnacciInRecursion(unsigned int n) {//递归方法：简单，但是会导致大量重复计算
    if (n <= 0) {
        return 0;
    }
    
    if (n == 1) {
        return 1;
    }
    return FibnacciInRecursion(n - 2) + FibnacciInRecursion(n - 1);
}

long long FibonacciInLoop(unsigned int n) { //非递归方法，按顺序逐个计算
    long long f1 = 0;
    if (n <= 0) {
        return f1;
    }
    
    long long f2 = 1;
    if (n == 1) {
        return f2;
    }
    
    long long temp = 0;
    for (unsigned int i = 1; i < n; ++i) {
        temp = f2;
        f2 += f1;
        f1 = temp;
    }
    return f2;
}

int main(int argc, const char *argv[]) {
    unsigned int n = 12;
    int re = (int)FibnacciInRecursion(n);
    int lp = (int)FibonacciInLoop(n);
    printf("%d--------%d\n",re, lp);
    return 0;
}
