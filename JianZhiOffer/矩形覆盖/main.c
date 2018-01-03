//
//  main.c
//  矩形覆盖
//
//  Created by mac on 2018/1/2.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
//仍然是递归，f(n) = f(n - 1) + f(n - 2) f(1) = 1 f(2) = 2;

int RecoverWayCount(int n) {
    int num = 0;
    if (n == 1) {
        num = 1;
        return num;
    }
    if (n == 2) {
        num = 2;
        return num;
    }
    int temp = 0;
    int f1 = 0;
    num = 1;
    for (int i = 1; i < n; i++) {
        temp = f1;
        f1 = num;
        num += temp;
    }
    return num;
}

int main(int argc, char *argv[]) {
    printf("%d\n", RecoverWayCount(10));
    return 0;
}
