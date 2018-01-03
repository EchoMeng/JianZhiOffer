//
//  main.c
//  数值的整数次方
//
//  Created by mac on 2018/1/2.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
double Power(double base, int exponent) {
    if (base == 0 && exponent == 0) {
        return 0.0;
    }
    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return base;
    }
    
    double result = Power(base, exponent >> 1);
    result *= result;
    if (exponent & 0x1) {
        result *= base;
    }
    return result;
}

int main(int argc, char *argv[]) {
    printf("%f\n",Power(2.5, 3));
    return 0;
}
