#include <stdio.h>
/*
方法: 使用 Division Method。
公式: index = key % m
*/

/**
 * @brief   計算一個整數 key 的 hash 索引
 * @details 使用 Division Method
 * @param   key   要進行hash的整數
 * @param   m     表格大小 
 * @return  int   計算出的 Hash 索引
 * 如果 m <= 0，回傳 -1 表示錯誤
 */
int myHashInt(int key, int m) {
    //避免m<0
   if (m <= 0) {
        printf("Error\n");
        return -1;
    }
    //Division Method
    int index = key % m;
    //避免負數
    if (index < 0) {
        index = (index + m) % m;
    }

    return index;
}
/**
 * @brief   計算一個字串 key 的 hash 索引
 * @details 使用 Summation Method
 * @param   key   要進行hash的字串
 * @param   m     表格大小
 * @return  int   計算出的 Hash 索引
 * 如果 m <= 0 或 key 為 NULL，回傳 -1
 */
int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    //避免m<0
    if (m <= 0) {
        printf("Error\n");
        return -1;
    }
    //避免空字串
    if (str == NULL) {
        printf("Error\n");
        return -1;
    }
    int i=0;
    //將字元ASCII加總
    while(str[i]!='\0'){
        hash+=str[i];
        i++;
    }
    //Division Method
    int index=(int)(hash % m);
    //避免負數
    if(index<0){
        index=(index+m)%m;
    }
    return (index); 
}
