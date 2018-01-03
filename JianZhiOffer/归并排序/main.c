//
//  main.c
//  归并排序
//
//  Created by mac on 2018/1/3.
//

#include <stdio.h>
//非递归(迭代)实现的归并排序首先进行是两两归并，然后四四归并，然后是八八归并，一直下去直到归并了整个数组。
//归并排序算法主要依赖归并(Merge)操作。归并操作指的是将两个已经排序的序列合并成一个序列的操作，归并操作步骤如下：
//1、申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
//2、设定两个指针，最初位置分别为两个已经排序序列的起始位置
//3、比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
//4、重复步骤3直到某一指针到达序列尾
//5、将另一序列剩下的所有元素直接复制到合并序列尾
void mSort(int *data, int count) {
    int tempArray[count];
    int middle = count / 2;
    int i = 0, j = middle, k = 0;
    while ((i < middle) && (j < count)) {
        if (data[i] > data[j]) {
            tempArray[k++] = data[j++];
        } else {
            tempArray[k++] = data[i++];
        }
    }
    
    if (i < middle) {
        while (i < middle) {
            tempArray[k++] = data[i++];
        }
    }
    if (j < count) {
        while (j < count) {
            tempArray[k++] = data[j++];
        }
    }
    
    for (int q = 0; q < count; ++q) {
        data[q] = tempArray[q];
    }
}

void mergSort(int *data, int count) {
    if (!data || count <= 1) {
        return;
    }
    
    int mid = count / 2;
    if (mid > 0) {
        mergSort(data, mid);
        mergSort(data + mid, count - mid);
        mSort(data, count);
    }
}

int main(int argc, char *argv[]) {
    int data[8] = {11, 5, 6, 7, 3, 2, 9, 0};
    int count = 8;
    mergSort(data, count);
    for (int i = 0; i < count; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
