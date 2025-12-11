## Tree
**定義:** 樹是 non-linear hierarchical 的資料結構，由邊連接節點組成。每個節點可以有零個或多個子節點 (父子關係)。樹結構中沒有cycles
**key:**
| key | 定義 |
| :--- | :--- | 
|**Root**|樹最頂層的節點|
|**Parent/Child**|有分支指向其他節點的為父節點，被指向的為子節點|
|**Leaf**|沒有子節點的節點|
|**Sibling**|擁有相同父節點的節點|
|**Edge**|兩個節點之間的連接|
|**Depth / Height**|深度 = 距離根節點的距離；高度 = 通往葉節點的最長路徑|
|**Fan-out**|一個節點擁有的子節點數量|

## Binary Tree
**定義:** 每個節點 最多有兩個子節點 (0, 1 或 2)。子節點被明確區分為 左子節點 與 右子節點 。
**ADT: Binary Tree:**
* **物件:** 一個有限的節點集合，可能為空，或者由一個根節點、左子樹與右子樹組成。
* **函式:**
  * BinaryTree Create(): 建立一個空的二元樹
  * Boolean IsEmpty(bt): 如果為空則回傳 true
  * BinaryTree MakeBT(bt1, item, bt2): 回傳一個以 item 為根、bt1 為左子樹、bt2 為右子樹的二元樹
  * BinaryTree Lchild(bt): 回傳左子樹
  * BinaryTree Rchild(bt): 回傳右子樹
  * Element Data(bt): 回傳根節點的資料

**節點實作 (Linked List 表示法):**
```c
struct TreeNode {
    int data;
    struct TreeNode *left;  // 指向左子節點的指標
    struct TreeNode *right; // 指向右子節點的指標
};
```
### Tree Traversal
**DFT:**
深度優先遍歷

|順序 |Visit Sequence|描述|
| :--- | :--- | :--- | 
|**Preorder**|Root → Left → Right|常用於複製樹結構|
|**Inorder**|Left → Root → Right|用於 BST 的排序輸出|
|**Postorder**|Left → Right → Root|常用於刪除節點或釋放記憶體|

**BFT:** 廣度優先遍歷
* Level-Order Traversal : 逐層拜訪節點
* 實作上通常使用 Queue

## Binary Search Tree
**定義:** 一種具有 排序屬性 的二元樹：
* 左子節點的值 < 父節點的值
* 右子節點的值 > 父節點的值

**Complexity & Balancing:**

| key | 定義 |時間複雜度|
| :--- | :--- |:--- | 
|**Balanced**|$高度維持在 $O(\log n)$|$O(\log n)$|
|**Unbalanced**|$退化成類似 Linked List$|$O(n)$|

## AVL tree,紅黑樹等等
* [**筆記作業**](./tree.pdf)
