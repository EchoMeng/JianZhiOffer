//
//  main.c
//  快速排序
//
//  Created by mac on 2018/1/3.
//

#include <stdio.h>
//经常会见到的几种排序方法：
//1、冒泡排序：依次比较相邻的两个元素
//2、选择排序：在剩余元素中找到最大的一个，放在序列末尾
//3、插入排序（二分插入排序，希尔排序）：未排序数据插入已排序序列。希尔排序是分组的插入排序
//4、归并排序
//5、堆排序：近似完全二叉树的排序
//6、快速排序：将一个元素作为基准，将比他大的放在左侧，比他小的放在右侧

void quickSort(int *data, int count) {
    if (count < 2) {
        return;
    }
    
    int left = 0;
    int right = count - 1;
    int temp = 0;
    while (left < right) {//将data[0]取出，比他大放在右侧，小的放左侧
        while (data[right] >= data[0] && left < right) {
            --right;
        }
        while (data[left] <= data[0] && left < right) {
            ++left;
        }
        
        if (left < right) {
            temp = data[left];
            data[left] = data[right];
            data[right] = temp;
        }
    }
    
    temp = data[0];
    data[0] = data[left];
    data[left] = temp;
    
    quickSort(data, left);
    quickSort(data + left + 1, count - left - 1);
}

int main(int argc, char *argv[]) {
    int count = 8;
    int data[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    quickSort(data, count);
    for (int i = 0; i < count; ++i) {
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}
