//
//  main.c
//  跳台阶
//
//  Created by mac on 2018/1/1.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
//递归：类似于斐波那契数列
long long JumpWayCount(unsigned int n) {
    int f1 = 0;
    if (n <= 0) {
        return f1;
    }
    
    int f2 = 1;
    if (n ==1) {
        return f2;
    }
    int temp = 0;
    for (int i = 1; i < n; ++i) {
        temp = f2;
        f2 += f1;
        f1 = temp;
    }
    return f2;
}

int main(int argc, char *argv[]) {
    printf("%lld\n", JumpWayCount(12));
    return 0;
}
