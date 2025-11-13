#include <string>
#include <stdio.h>
/**
 * @brief   計算一個整數 key 的 hash 索引
 * @details 使用 Division Method
 * @param   key   要進行hash的整數
 * @param   m     表格大小
 * @return  int   計算出的 Hash 索引 
 */
int myHashInt(int key, int m) {
    if (m <= 0) {
        printf("Error\n");
        return -1;
    }
    int index = key % m;

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
int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
   if (m <= 0) {
        printf("Error\n");
        return -1;
    }
    for (char c : str) {
        hash += c;
    }
    
    return static_cast<int>(hash % m);  // basic division method
}
