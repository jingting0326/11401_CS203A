**定義**: 一種遵循 **先進先出 (First-In-First-Out, FIFO)** 原則的線性資料結構。
元素從一端（rear）加入，並從另一端（front）移除 。

### ADT: Queue
* **物件:** 一個包含零個或多個元素的有限有序列表。
* **函式:**
  * Queue CreateQ(maxQueueSize): 建立一個指定最大容量的空queue。
  * Boolean IsFullQ(queue, maxQueueSize): 若滿回傳 true。
  * Boolean IsEmptyQ(queue): 若空回傳 true。
  * Queue AddQ(queue): 將項目插入queue尾端 (Enqueue)。
  * Queue DeleteQ(queue): 移除並回傳queue前端的項目 (Dequeue)。
 
### 實作 1: 基於Array
**所需變數**:
  * queue[MAX_SIZE]: 實際儲存資料的陣列。
  * front: 第一個元素的索引。
  * rear: 最後一個元素的索引。

**Operations**:
```c
// Enqueue 
rear = (rear + 1) % MAX_SIZE;
queue[rear] = value;

// Dequeue 
front = (front + 1) % MAX_SIZE;
value = queue[front];
```
### 實作 2: 基於Linked List
**所需變數**:
  * Node* front: 指向第一個節點。
  * Node* rear: 指向最後一個節點。

**Operations**:
```c
// Enqueue
// 建立新節點 (create new node)
rear->next = newNode;
rear = newNode;

// Dequeue
// 檢查 front != NULL
front = front->next;
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
