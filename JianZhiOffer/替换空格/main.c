//
//  main.c
//  test
//
//  Created by mac on 2018/1/1.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ReplaceSpace(char *str, int length) {
    if (str == NULL) return NULL;
    char *p = str;
    int size = 0;
    int spaceNum = 0;
    while (*p != '\0') {
        if (*p == ' ')  spaceNum++;
        size++;
        p++;
    }
    if (spaceNum == 0) return NULL;
    int newLength = size + 2 * spaceNum;
    if (newLength > length) return NULL;
    char *newString = (char *)malloc(sizeof(char) * (newLength + 1));
    char *end = newString + newLength;
    char *old = str + size;
    while (old >= str) {
        if (*old == ' ') {
            *end-- = '0';
            *end-- = '2';
            *end-- = '%';
        } else {
            *end-- = *old;
        }
        old--;
    }
    return newString;
}

char *replaceSpace(char *str,int length) {
    if (str == NULL) return NULL;
    int spaceCount = 0;
    int originCount = 0;
    for (int i = 0; str[i]!='\0'; i++) {
        originCount ++;
        if (str[i] == ' ') spaceCount++;
    }
    int newLength = originCount + spaceCount * 2;
    if(newLength+1>length)return NULL;
    
    char *newStr = (char *)malloc(sizeof(char) *(newLength + 1));
    char *old = str + originCount;
    char *end = newStr + newLength;
    while (old >= str) {
        if (*old == ' ') {
            *end--='0';
            *end--='2';
            *end--='%';
        }else {
            *end--=*old;
        }
        --old;
    }
    return newStr;
}

int main(int argc, const char * argv[]) {
    char *str = "Hello world";
    int length = 100;
    printf("%s\n", replaceSpace(str, length));
}
