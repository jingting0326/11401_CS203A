# Assignment IV: Hash Function Design & Observation

**姓名：** [廖婧婷]
**學號：** [1111426]

## 1. 開發歷史

* **2025/11/12 22:20:** 建立專案結構並加入範本檔案
* **2025/11/12 22:20:** 完成 hash_fn.cpp中的整數
---

## 2. Hash Function 設計理念
### A. 整數 Hash
最基礎的 Division Method
    * **公式:** `index = key % m`
    * **理由:** 實作簡單且對於 m 是質數時，分佈效果不錯
    * **負數處理:** 確保即使 key 是負數，回傳的 index 也絕對會在 0 到 m-1 的範圍內。
    * **負數處理公式:** index = (index + m) % m 例如(-5 + 10) % 10 = 5 % 10 = 5)

## 3. 測試結果與觀察 

## 4. 總結分析 