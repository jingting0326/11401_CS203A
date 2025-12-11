## Singly Linked List
c
```c
struct SNode {
    int data;
    struct SNode *next;
};

```
C++
```Cpp
class SNode {
public:
    int data;
    SNode* next;
    SNode(int val): data(val), next(nullptr) {}
};
```
## Doubly Linked List
c
```c
struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};
```
C++
```cpp
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val): data(val), prev(nullptr), next(nullptr) {}
};
```
## Circular Linked List
c
```c
struct CNode {
    int data;
    struct CNode *next;
};
```
C++
```cpp
class CNode {
public:
    int data;
    CNode* next;
    CNode(int val): data(val), next(nullptr) {}
};
```
## Swap Value
### 只交換 Node 中的資料，不改變 Pointer 結構。
c
```c
void selectionSortValue(Node* head) {
    for (Node* i = head; i && i->next; i = i->next) {
        Node* minNode = i;
        // Find minimum in the remaining list
        for (Node* j = i->next; j; j = j->next) {
            if (j->val < minNode->val)
                minNode = j;
        }
        
        // Swap values
        if (minNode != i) {
            int t = i->val;
            i->val = minNode->val;
            minNode->val = t;
        }
    }
}
```
## Swap Pointer
### 改變 Pointer 指向來重新排列 Node
c
```c
Node* selectionSortPointer(Node* head) {
    if (!head) return head;
    
    Node dummy = {0, head}; // Dummy node simplifies head manipulation
    Node* sortedTail = &dummy;
    
    while (sortedTail->next) {
        Node* minPrev = sortedTail;
        // Find minimum node's predecessor
        for (Node* p = sortedTail->next; p && p->next; p = p->next) {
            if (p->next->val < minPrev->next->val)
                minPrev = p;
        }
        
        Node* minNode = minPrev->next;
        
        // Detach minNode
        minPrev->next = minNode->next;
        
        // Insert after sortedTail
        minNode->next = sortedTail->next;
        sortedTail->next = minNode;
        
        sortedTail = sortedTail->next;
    }
    return dummy.next;
}
```
## Time Complexity
| Operation | Array  | Linked List | Note |
| :--- | :--- | :--- | :--- |
| **Access** | $O(1)$ | $O(n)$ | Linked List 必須從頭遍歷 |
| **Search** | $O(n)$ | $O(n)$ |兩者在未排序時皆需遍歷 |
| **Insert at front** | $O(n)$ | $O(1)$ | Array 需 Shift 元素；List 僅需改 Head |
| **Insert at middle** | $O(n)$ | $O(n)$ | 兩者皆需先 Search 位置|
| **Insert at end** | $O(1)$  | $O(n)$ / $O(1)$ |List 若有 Tail pointer 則為 $O(1)$|
| **Delete** | $O(n)$ | $O(n)$ / $O(1)$ |若已知 Node pointer，List 刪除為 $O(1)$ |
