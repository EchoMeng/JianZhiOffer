//
//  main.c
//  旋转数组的最小数字
//
//  Created by mac on 2018/1/1.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
//两种特殊情况：
//1.没有旋转的数组
//2.{1, 1, 1, 0, 1}这样的数组，开头/中间/结尾都相同，这样的数组用顺序查找

//二分法查找的思想
int minimumNumberInRotationArray(int *data, int count) {
    if (!data || !count) {
        return 0;
    }
    
    int min = 0;
    int max = count - 1;
    int mid = min;
    
    while (data[min] >= data[max]) {//原本为递增数列，经过旋转之后不再递增，当第一个被最后一个大的时候
        if (max - min == 1) {
            mid = max;
            break;
        } //这里是说数组中一共只有两个数字，那么输出较小，跳出循环即可
        
        mid = (min + max) / 2;
        
        if (data[min] == data[mid] && data[mid] == data[max]) {//这里指向特殊情况2，顺序查找
            int minimum = data[0];//用minimum存储最小的数字，输出即可
            for (int i = 1; i < count; ++i) {
                if (data[i] < minimum) {
                    minimum = data[i];
                }
            }
            return minimum;
        }
        
        if (data[mid] >= data[min]) {
            min = mid;
        } else if (data[mid] < data[max]) {
            max = mid;
        }//最终想要使mid指向数组中最小的数字
    }
    return data[mid];
}

int main(int argc, const char * argv[]) {
    int data[5] = {1, 1, 1, 0, 1};
//    int data[5] = {3, 4, 5, 1, 2};
//    int data[5] = {1, 2, 3, 4, 5};
//    int data[1] = {2};
    int count = 5;
    printf("%d\n", minimumNumberInRotationArray(data, count));
    return 0;
}
