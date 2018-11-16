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
    return -1;
}
```

### 二分/折半查找

#### cpp实现

```cpp
int binaryOrderSearch(int dest_arr[], int search, int array_size) {
    //assume dest_arr is ascend sorted.
    int alen = array_size;
    int amid =  alen/2;
    int left = 0;
    int right = alen-1;
    while(right-left > 0) {
        if (dest_arr[amid] < search) {
            left = amid+1;
            amid = (left+ right) /2;
        } else if (dest_arr[amid] > search) {
            right = amid-1;
            amid = (left+right)/2;
        } else {
            return amid;
        }
    }
    return -1;
}
```  


### 分块/索引查找
