# 面试算法&数据结构


## 常用的排序算法

### 快速排序
&ensp;&ensp;&ensp;&ensp;快速排序的最坏时间复杂度为 `O(n^2)` ,但平均复杂度为： `O(nlog_2n)`

#### cpp实现

1.
```cpp
template <class Type>
void Swap(Type *a, Type *b) {
    Type tmp = *a;
    *a = *b;
    *b = tmp; 
}

template <class Type>
int Partition(Type arr[], int p , int r) {
    int i = p, j = r;
    Type x = arr[p];
    while(true) {
        while(arr[j]> x && i < j)  {
            j--;
        }
        while(arr[i]<= x && i < j ) {
            i++;
        } 
        if (i == j) break;
        Swap(&arr[i],&arr[j]);
    }
    Swap(&arr[p], &arr[j]);
    return j;
}

template<class Type>
void QuickSort(Type arr[], int p, int r) {
    if (p < r) {
        int q = Partition(arr,p,r);
        QuickSort(arr,p,q-1);
        QuickSort(arr,q+1,r);
    }
}

```

2.
```cpp
void quicksort(int a[],int left, int right)
{
    int i,j,t,temp;
    if (left > right) 
        return;
    temp = a[left];
    i = left;
    j = right;
    while(i != j) 
    {
        while(a[j] >= temp && i < j) {
            j--;
        }
        while(a[i] <= temp && i < j) {
            i++;
        }
        if (i < j) 
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    a[left] = a[i];
    a[i] = temp;
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
}
```

3. 
```cpp
template <class Type>
int Partition(Type arr[], int p , int r) {
    int pivot = arr[p];
    int highvac = r;
    int lowvac = p;
    bool direct = true; //true for right, false for left 
    while(highvac > lowvac) {
        if (direct == true) {
            if(arr[highvac] <= pivot) {
                arr[lowvac] = arr[highvac];
                lowvac++;
                direct = false;
            } else {
                highvac--;
            } 
        } else {
            if(arr[lowvac]> pivot ) {
                arr[highvac] = arr[lowvac];
                highvac--;
                direct = true;
            }else {
                lowvac++;
            }
        }
    }
    arr[highvac] = pivot;
    return highvac;
}

template<class Type>
void QuickSort(Type arr[], int p, int r) {
    if (p < r) {
        int q = Partition(arr,p,r);
        QuickSort(arr,p,q-1);
        QuickSort(arr,q+1,r);
    }
}
```

## 常用查找算法

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
        amid = (left+ right) /2;
        if (dest_arr[amid] < search) {
            left = amid+1;
        } else if (dest_arr[amid] > search) {
            right = amid-1;
        } else {
            return amid;
        }
    }
    return -1;
}
```  


### 分块/索引查找
