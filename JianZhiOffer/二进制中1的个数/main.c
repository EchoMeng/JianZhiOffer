//
//  main.c
//  二进制中1的个数
//
//  Created by mac on 2018/1/1.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
int NumberOf1(int n) {
    int num = 0;
    while (n) {
        num++;
        n &= (n - 1); //&是位与运算符 n = n & (n - 1),可以让二进制数字中的1减少一个
    }
    return num;
}

int NumberOf1Binary (int n) {
    int flag = 1;
    int count = 0;
    while (flag) {
        if (n & flag) {
            count++;
        }
        flag <<= 1;
    }
    return count;
}

int main(int argc, char *argv[]) {
    printf("%d\n----%d",NumberOf1(10),NumberOf1(10));
    return 0;
}
