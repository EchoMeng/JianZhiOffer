//
//  main.c
//  test
//
//  Created by mac on 2018/1/1.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

bool Find(int rows, int colomns, int matrix[rows][colomns], int target) {
    for (int i = rows; i > 0; i--) {
        for (int j = 0; j < colomns; j++) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target){
                continue;
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int matrix[3][3] = {
        1,2,3,
        4,5,6,
        7,8,9
    };
    int rows = 3;
    int colomns = 3;
    printf("%s\n",Find(rows, colomns, matrix, 12)? "true":"false");
}
