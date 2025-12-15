**定義:** Heap 是一個滿足 Heap-Order Property 的 完全二元樹 
* 和完全二元樹類似
* **結構:** 是一個完全二元樹
* **填滿規則:** 每一層都是填滿的，除了最後一層可能例外；且最後一層的節點是從左到右填入
* **儲存優勢:** Heap 可以有效率地儲存在 Array中，且不會有空隙

## Max Heap
* Parent >= Children
* 最大元素 永遠位於 Root

## Min Heap
* Parent <= Children
* 最小元素 永遠位於 Root

## Priority Concept
* 順序代表 Priority
* Key  被用來代表 Priority
* Max heap 中，最大的 Key ;Min heap 中，最小的 Key

## Time Complexity

| Operation | Description | Time |
| :--- | :--- | :--- |
| insert(x) | 新增元素並恢復 Heap 順序 | $O(\log n)$ |
| extract_root() |移除最大 (或最小) 元素| $O(\log n)$|
| peek_root() | 存取最大 (或最小) 元素 | $O(1)$ |
|build_heap(array) | 將陣列轉換為 Heap | $O(n)$ |
| heapify(i) | 在節點 i 恢復 Heap 性質 | $O(\log n)$ |

## Implementation Logic
### Insertion Example: Max Heap
1.將新節點放在 Array 的最後一個位置

2.調整 

3.將新節點與其 Parent 比較 

4.如果順序錯誤 (例如在 Max Heap 中，子 > 父)，則 Swap 

5.重複此步驟往上檢查，直到滿足 Heap 

### Extract Root Example: Max Heap
1.移除: 取出 Root


2.替補: 將 Array 中 最後一個元素 移動到 Root 的位置 。

3.調整 

4.找尋替補節點的子節點。

5.與 Max Heap 或 Min Heap 的子比較。

6.若順序錯誤則交換。

7.重複往下直到恢復 Heap 性質。

