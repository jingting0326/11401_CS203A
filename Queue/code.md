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
