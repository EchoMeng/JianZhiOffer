//
//  main.c
//  调整数组顺序使奇数在偶数前面
//
//  Created by mac on 2018/1/2.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>

void ReOrderArray(int *data, int count) {
    if (!data || count < 2) {
        return;
    }
    int i = 0;
    int j = count - 1;
    int temp = 0;
    while (j > i) {
        while (j > i && !(data[j] & 0x1)) { //(data[j] & 0x1)表示为奇数。很简单，偶数转换为二进制后，最后一位是0；奇数转化为二进制后最后一位是1.用位与运算鉴定最后一位是1还是0
            --j;//偶数，--j。从后往前遍历，一旦遇到奇数，就结束这个循环
        }
        while (j > i && (data[i] & 0x1)) {
            ++i;//奇数，--i。从前往后遍历，一旦遇到偶数，就结束这个循环
        }
        
        if (j > i) {//这里将前两个循环中遇到的偶数/奇数换位
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
}

void sortOddBeforeEven(int *data, int count) {
    int i = 0;
    int j = count - 1;
    int temp = 0;
    while (i < j) {
        while (i < j && (data[i] & 0x1)) {//前面为奇数
            i++;
        }
        while (i < j && !(data[j] & 0x1)) {
            j--;
        }
        if (i < j) {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
}

int main(int argc, char *argv[]) {
    int data[8] = {2, 3, 4, 5, 8, 10, 11, 13};
    int count = 8;
//    ReOrderArray(data, count);
    sortOddBeforeEven(data, count);
    for (int i = 0; i < count; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}


