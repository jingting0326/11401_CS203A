# Hash Function
## 整數 Key
最常見的方法，使用餘數運算將 Key 對應到 Table Index 。
```c
int hash_division(int key, int m) {
    // m 建議使用質數 (例如 1009, 10007) 以減少碰撞
    return key % m; 
}
```
## 字串 Key
將字串轉換為整數 Index，使用加權總和避免碰撞 (如 "tab" 與 "bat") 。
```c
int hash_string(char *s, int m) {
    long hash = 0;
    int p = 31; // 質數基底
    int p_pow = 1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        hash = (hash + (s[i] * p_pow)) % m;
        p_pow = (p_pow * p) % m;
    }
    return (int)hash;
}
```
# 碰撞處理:Separate Chaining
## 定義結構
```c
// 定義 Node (Key-Value Pair)
typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

// 定義 Hash Table (Array of Pointers)
#define M 10 // Table Size
Node *hashTable[M];
```
## 初始化
```c
// 將所有 bucket 初始化為 NULL
for (int i = 0; i < M; i++) {
    hashTable[i] = NULL;
}
```
## 插入資料
```c
void insert(int key, int value) {
    int index = key % M; // Hash Function
    
    // 建立新節點
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    
    // 處理碰撞：加入head (O(1))
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}
```
## 搜尋資料
```c
int search(int key) {
    int index = key % M;
    Node *current = hashTable[index];
    
    while (current != NULL) {
        if (current->key == key) {
            return current->value; // 找到並回傳
        }
        current = current->next;
    }
    return -1; // Not Found
}
```
# 碰撞處理：Open Addressing

## 定義結構
```c
typedef struct {
    int key;
    int value;
    int is_occupied; // 標記是否被佔用
} Bucket;

Bucket openAddrTable[M]; // 全部都在 Array 內實作
```
## 插入資料
```c
void insert_linear(int key, int value) {
    int index = key % M;
    int start_index = index;
    
    // Probing: 找空位
    while (openAddrTable[index].is_occupied) {
        // 如果 Key 已經存在，則更新 Value
        if (openAddrTable[index].key == key) break;
        
        index = (index + 1) % M; // Linear Probing
        
        // 如果繞了一圈回到原點，表示已滿
        if (index == start_index) return; 
    }
    
    // 放入資料
    openAddrTable[index].key = key;
    openAddrTable[index].value = value;
    openAddrTable[index].is_occupied = 1;
}
```
# Time Complexity 

## 1. Separate Chaining


| Operation | Best | Average | Worst |
| :--- | :--- | :--- | :--- |
| **Search** | $O(1)$ | $O(1 + \alpha)$ | $O(n)$ |
| **Insert** | $O(1)$ | $O(1)$ | $O(n)$ |
| **Delete** | $O(1)$ | $O(1)$ | $O(n)$ |



---

## 2. Open Addressing


| Operation | Average ($\alpha \le 0.7$) | Worst |
| :--- | :--- | :--- |
| **Search** | $O(1)$ | $O(n)$ |
| **Insert** | $O(1)$ | $O(n)$ |
| **Delete** | $O(1)$ | $O(n)$ |
