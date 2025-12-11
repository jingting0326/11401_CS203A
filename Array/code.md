根據課程簡報整理的code

## 靜態array

### 宣告
```c
// 1D array with five elements
int array[5];
```

```c
// 2D array with 3 rows and 4 columns
int array2d[3][4];
```

```c
// 3D array with 2 block each 3 rows and 4 columns
int array3d[2][3][4];
```

### 初始化數值

```c
//模擬原亂碼
int array[5]={10,20,50,30,80};
//初始化為1-5
for(int i=0;i<5;i++){
    array[i]=i+1;
}
```

### 取出data

```c
//取出第3個
printf("%d",array[2]);
```
```c
//取出row1,col2
printf("%d",array2d[1][2]);
```

```c
printf("%d",array3d[2][3][4]);
```

## 動態array

### 宣告
```c
// malloc()
int *array;
int n = 10;
array = (int *) malloc(n * sizeof(int));
```

### 初始化

和靜態array相同

### 取出data

和靜態array相同

### ⚠️重要⚠️ resize

```c
n = n * 2;
int *temp = (int *) realloc(array, n * sizeof(int));
for (int i = n / 2; i < n; i++) {
    array[i] = i + 1;
```
### Time Complexity
| Operation | Complexity | Notes |
| :--- | :--- | :--- |
| **Access** | $O(1)$ | $Direct index lookup$ | 
| **Update** | $O(1)$ | $Replace at index$ |
| **Insert** | $O(n)$ | $Requires shifting elements$ | 
| **Delete** | $O(n)$ | $Requires shifting elements$ | 
| **Traverse** | $O(n)$ | $Visit all elements$ |
| **Search** | $O(n)/O(log n)$  | $Linear for unsorted, binary for sorted$ | 
