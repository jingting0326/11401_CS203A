
**定義**: 一種遵循 **後進先出 (Last-In-First-Out, LIFO)** 原則的線性資料結構。
元素只能從同一端進行新增與移除。

### ADT: Stack


* **物件**: 一個包含零個或多個元素的有限有序列表。
* **函式**:
    * Stack CreateS(maxStackSize): 建立一個指定最大容量的空stack。
    * Boolean IsFull(stack, maxStackSize): 如果stack內元素數量等於最大容量，回傳 true。
    * Boolean IsEmpty(stack): 如果stack為空，回傳 true。
    * Stack Push(stack): 將項目插入stack頂端 (若未滿)。
    * Stack Pop(stack): 移除並回傳stack頂端的項目 (若非空)。

### 實作 1: 基於Array


**所需變數**:
* stack[MAX_SIZE]: 實際儲存資料的陣列 。
* top: 目前頂端元素的整數索引 (初始值為 -1)
* MAX_SIZE: 最大容量 。

**Operations**:
```c
// Push 
檢查 top < MAX_SIZE-1
stack[++top] = value;  // top 先加 1，再存入數值

// Pop 
檢查 top >= 0
value = stack[top--];  // 先取出數值，top 再減 1

// Peek
return stack[top];
```
### 實作 2:基於Linked List

**所需變數**:
* Node* top: 指向頭節點的指標，即stack頂端 。
  
**Operations**:
  ```c
// Push
建立新節點
newNode->next = top;
top = newNode;

// Pop
檢查 top != NULL
top = top->next;
```
### 比較

| 特性 | Stack |Queue|
| :--- | :--- | :--- |
| **存取模式** |LIFO | FIFO|
| **I/O 方向** |所有操作皆發生在頂端| 輸入在rear，輸出在front | 

### Array vs. Linked List 實作比較
| 結構與面向 | Array 實作 |Linked List 實作|
| :--- | :--- | :--- |
| **Stack 變數** |top, MAX_SIZE, 陣列儲存空間 |top 指標|
| **Queue 變數** |front, rear, MAX_SIZE, 陣列, (有時需要 count)| front 與 rear 指標 | 
| **記憶體管理** |預先配置 (Pre-allocated)，若未滿可能浪費空間；resizing 有成本|每個節點動態配置 (Dynamic allocation)，有指標的額外記憶體開銷| 
| **Overflow** |必須檢查索引| 只有當 Heap 記憶體耗盡時才會發生 | 
| **Performance** |$O(1)$ push/pop/enqueue/dequeue| $O(1)$ push/pop/enqueue/dequeue| 

