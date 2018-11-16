# 面试算法&数据结构

## 常用顺序查找算法

### 顺序查找

#### cpp实现
```cpp
int orderSearch(int dest_arr[],int  dest) {

    int arr_len = sizeof(dest_arr)/sizeof(*dest_arr);
    for(int i = 0; i <= arr_len; i++) {
        if (dest_arr[i] == dest) {
            return i;
        }
    }
}
```

### 二分/折半查找

### 分块/索引查找
