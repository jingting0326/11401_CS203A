**定義:** 圖形 G = (V, E) 由以下組成
* V: 一組 Vertices 或 Nodes 的集合
* E: 一組連接 Nodes 的 Edges 的集合
## key

| key | 定義 |
| :--- | :--- |
| Undirected Graph |Edges 沒有方向性|
|Directed Graph |Edges 具有方向性|
|Weighted Graph |邊帶有權重/成本 例如：地圖|
|Degree|連接該 Nodes 的 Edges 的數量|
|In-degree|指向該 Nodes 的 Edges 的數量|
|Out-degree|從該 Nodes 出發的 Edges|
|Subgraph|圖 G' 的 Nodes 和 Edges 皆屬於圖 G 的子集|
|Connected Graph|每個 Nodes 都是可到達的|
|Cyclic/Acyclic| 是否包含 Loop|

## Graph Representations
### Adjacency Matrix
* 使用 V * V 的二維陣列 matrix[i][j]
* 優點: O(1) 查詢 Edges 是否存在
* 缺點: 空間複雜度 O(V^2)，對於稀疏圖來說很浪費空間
* 適用: 稠密圖

### Adjacency List
* 使用 Array 儲存 List，每個 Nodes 只儲存其鄰居
* 優點: 空間複雜度 O(V+E)，節省空間
* 缺點: 查詢邊是否存在需 O(deg(u))
* 適用: 稀疏圖(大多數真實世界的圖)

## Graph Traversal
* 與樹的遍歷類似，但必須處理 Cycles
* **DFS:** 遞迴、深入探索、Preorder Traversal、Stack 或 Recursion
* **BFS:** 逐層探索、佇列基礎、Level-order Traversal、Queue

## Graph vs. Tree
|  | Tree | Graph |
| :--- | :--- | :--- |
|連通性|總是|可能沒有|
|Cycles|無|有|
|方向性|無|有|
|父子關係|有|無|
| Traversal|不需要|需要 visited[] 以避免無窮迴圈|

## Adjacency Matrix vs. Adjacency List

|  |Adjacency Matrix| Adjacency List |
| :--- | :--- | :--- |
|Check Edge|O(1)|O(deg(u))|
|取得所有鄰居|O(V)|O(deg(u))|
|新增 Edge |O(1)|O(1)|
|刪除 Edge |O(1)|O(deg(u))|
| Traversal|$O(V^2)$|O(V+E)|
|空間利用|$O(V^2)$|O(V+E)|

## ADT
*Create(): 建立空圖
* InsertVertex(graph, v): 新增 Nodes
* InsertEdge(graph, v1, v2): 新增 Edge
* DeleteVertex(graph, v): 刪除 Nodes 及其連接的 Edge
* DeleteEdge(graph, v1, v2): 刪除 Edge
* IsEmpty(graph): 檢查是否為空
* Adjacent(graph, v): 回傳與 v 相鄰的所有 Nodes 列表









  
