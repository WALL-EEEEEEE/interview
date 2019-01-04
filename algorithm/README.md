# 面试算法

<!--ts-->
   * [面试算法&amp;数据结构](#面试算法数据结构)
      * [常用的排序算法](#常用的排序算法)
         * [快速排序](#快速排序)
            * [cpp实现](#cpp实现)
         * [冒泡排序](#冒泡排序)
            * [python实现](#python实现)
         * [插入排序](#插入排序)
            * [python实现](#python实现-1)
         * [归并排序](#归并排序)
            * [python实现](#python实现-2)
         * [  堆排序](#堆排序)
            * [python实现](#python实现-3)
      * [常用查找算法](#常用查找算法)
         * [顺序查找](#顺序查找)
            * [cpp实现](#cpp实现-1)
         * [二分/折半查找](#二分折半查找)
            * [cpp实现](#cpp实现-2)
         * [分块/索引查找](#分块索引查找)
            * [cpp实现](#cpp实现-3)
      * [其他算法](#其他算法)
         * [查找数组中的前M大的数](#查找数组中的前m大的数)
            * [cpp实现](#cpp实现-4)
         * [翻转数列](#翻转数列)
            * [cpp实现](#cpp实现-5)
         * [纸牌游戏](#纸牌游戏)
            * [cpp实现](#cpp实现-6)

<!-- Added by: johans, at:  -->

<!--te-->


## 常用的排序算法

### 快速排序

+ 思路

```
选定一个pivot, 移动元素使得pivot左右两边的元素，一边大于pivot, 一边小于pivot, 然后
分别对左右两边递归进行同样的操作，最后得到一个有序排列。
```

+ 复杂度

&ensp;&ensp;&ensp;&ensp;快速排序的最坏时间复杂度为: O(n) = n^2，但平均复杂度为： O(n) = nlogn



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

### 冒泡排序

+ 思路

```
模拟水中的冒泡过程, 大的水泡总是从底部不断的超过小的水泡，最终上升到水面。冒泡排序也是，从左到右,
小的数不断的从右边冒泡上升到左边，最终实现有序。
```

+ 复杂度

&ensp;&ensp;&ensp;&ensp;冒泡排序的最坏时间复杂度为: O(n) = n^2，平均复杂度为： O(n) = n^2

#### python实现

```python
def bubblesort(arr):
    for i in range(0,len(arr)):
        for k in range(0,len(arr)-i-1):
            if arr[k]>arr[k+1]:
                tmp =  arr[k]
                arr[k] = arr[k+1]
                arr[k+1] = tmp
    return arr

us = [1,2,0,-1]
print(bubblesort(us))
us1 = [6,8,0,2,1]
print(bubblesort(us1))
```

### 插入排序





+ 思路

```
插入排序是最直观和自然的排序，它是从左到右，将一个数从它为起始位置 loc ，从右向左，进行比较，如果 
array[loc-1] < array[loc] 或者 loc = 0 ，那么就将这个数插入 loc 位置，否则 loc 位置左移 ( loc = loc -1 )
继续进行比较，直到数组有序。
```

+ 算法复杂度

&ensp;&ensp;&ensp;&ensp;插入排序的最坏时间复杂度为: O(n) = n^2，平均复杂度为： O(n) = n^2

#### python实现

```python
def shift_vac(arr,vac_loc,vac):
    loc = 0
    while vac_loc > 0:
        if arr[vac_loc-1] <= vac:
            loc = vac_loc
            break
        arr[vac_loc] = arr[vac_loc-1]
        vac_loc-=1

    return loc
def insert_sort(arr):
    for i in range(0,len(arr)):
        v = arr[i] 
        loc = shift_vac(arr,i,v)
        arr[loc] = v
    return arr

us = [1,2,0,-1]
us1 = [6,8,0,2,1]
print(insert_sort(us))
print(insert_sort(us1))
```
### 归并排序

+ 思路

```
归并排序采用的是分治的思想，将一个 n 长度的数组不断的分成无数个小数组，然后对小数组进行排序，
最后将所以的有序小数组合并，最终数组有序。
```

+ 算法复杂度

&ensp;&ensp;&ensp;&ensp;归并排序的平均复杂度： O(n) = nlogn, 最坏时间复杂度为：O(n) = nlogn

+ 算法空间复杂度

&ensp;&ensp;&ensp;&ensp;归并排序的空间复杂度： O(n) = n

#### python实现

```python
# 递归实现
import random
def merge(arr,first,mid,last):
    fore_part = arr[first:mid+1]
    last_part = arr[mid+1:last+1]
    index = first 
    k = 0;
    m = 0;
    while( k <  len(fore_part)):
        while(m < len(last_part)):
            if  fore_part[k] > last_part[m]:
                arr[index] = last_part[m]
                index+=1
                m+=1
            elif fore_part[k] < last_part[m]:
                arr[index] = fore_part[k]
                index+=1
                k+=1
                break;
            else:
                arr[index] = last_part[m]
                arr[index+1] = fore_part[k]
                index+=2
                m+=1
                k+=1
        if ( m >= len(last_part)): 
                arr[index] = fore_part[k]
                index+=1
                k+=1;
    if m < len(last_part):
        for j in range(m,len(last_part)):
            arr[index] = last_part[j]
            index+=1

def merge_sort(arr,first,last):
    mid = int((first+last)/2)
    if first < last:
        merge_sort(arr,first,mid)
        merge_sort(arr,mid+1,last)
        merge(arr,first,mid,last)
    return arr

us = [1,2,0,-1]
us1 = [6,8,0,2,1]
us2 = [9,8,7,6,5,4,3,2,1,0]
print(merge_sort(us,0,len(us)-1))
print(merge_sort(us1,0,len(us1)-1))
print(merge_sort(us2,0,len(us2)-1))

```



###   堆排序

+ 思路

```
将数组转换成一个最小堆（升序排序）/最大堆（降序排序），然后挨个删除并输出堆顶元素，并继续调整堆为最小堆（升序排序）或者 
最大堆（降序排列），从而最终生成一个升序或者降序序列。
```

+ 算法复杂度

  平均复杂度为:  O(n) = nlogn，最坏情况下的算法复杂度：O(n) = nlogn;


#### python实现

```python
#
# HeapSort implemented by python
#
class BTNode:
    def __init__(self,value = None,left= None,right=None):
        self.value = value
        self.left = left
        self.right = right
    def setValue(self,value):
        self.value = value
    def setLeft(self,left):
        self.left = left
    def setRight(self,right):
        self.right = right
    def __str__(self):
        str_tree = ""
        roots = [self]
        while len(roots) > 0 :
            troots = []
            for root in roots:
                str_tree= str_tree+" "+str(root.value)
                if root.left != None:
                    troots.append(root.left)
                if root.right != None:
                    troots.append(root.right)
            roots = troots
        return str_tree

def construct_heap(arr):
    if arr == None or len(arr) <= 0:
        return None
    heap = None
    for v in arr:
        cnode = heap
        if heap != None:
            inodes = [heap]
            while len(inodes) > 0:
                tnodes = []
                for inode in inodes:
                    if inode.left == None:
                        inode.left = BTNode()
                        cnode = inode.left
                        tnodes=[]
                        break
                    elif inode.right == None:
                        inode.right = BTNode()
                        cnode = inode.right
                        tnodes = []
                        break
                    else:
                        tnodes.append(inode.left)
                        tnodes.append(inode.right)
                inodes = tnodes
            cnode.value = v
        else:
            heap = BTNode()
            heap.value = v
    return heap

def construct_minheap(arr):
    if arr == None or len(arr) <= 0:
        return None
    heap = None
    for v in arr:
        cnode = heap
        if heap != None:
            inodes = [heap]
            while len(inodes) > 0:
                tnodes = []
                for inode in inodes:
                    if inode.value > v:
                        tmp = inode.value
                        inode.value = v
                        v = tmp
                        tnodes = inodes
                        break
                    if inode.left == None:
                        inode.left = BTNode()
                        cnode = inode.left
                        tnodes=[]
                        break
                    elif inode.right == None:
                        inode.right = BTNode()
                        cnode = inode.right
                        tnodes = []
                        break
                    else:
                        tnodes.append(inode.left)
                        tnodes.append(inode.right)
                inodes = tnodes
            cnode.value = v
        else:
            heap = BTNode()
            heap.value = v
    return heap

def construct_maxheap(arr):
    if arr == None or len(arr) <= 0:
        return None
    heap = None
    for v in arr:
        cnode = heap
        if heap != None:
            inodes = [heap]
            while len(inodes) > 0:
                tnodes = []
                for inode in inodes:
                    if inode.value < v:
                        tmp = inode.value
                        inode.value = v
                        v = tmp
                        tnodes = inodes
                        break
                    if inode.left == None:
                        inode.left = BTNode()
                        cnode = inode.left
                        tnodes=[]
                        break
                    elif inode.right == None:
                        inode.right = BTNode()
                        cnode = inode.right
                        tnodes = []
                        break
                    else:
                        tnodes.append(inode.left)
                        tnodes.append(inode.right)
                inodes = tnodes
            cnode.value = v
        else:
            heap = BTNode()
            heap.value = v
    return heap

def fix_maxheap(heap,K):
    heap.value = K
    if heap != None:
        inodes = [heap]
        while len(inodes) > 0:
            tnodes = []
            for inode in inodes:
                if (inode.left != None and inode.value < inode.left.value) or (inode.right != None and inode.value < inode.right.value):
                    tmp = inode.value
                    if inode.left.value > inode.right.value:
                        inode.value = inode.left.value
                        inode.left.value = tmp
                        tnodes.append(inode.left)
                    else: 
                        inode.value = inode.right.value
                        inode.right.value = tmp
                        tnodes.append(inode.right)
            inodes = tnodes
    return heap

def fix_minheap(heap,K):
    pass

def delete_max(heap):
    max = heap.value
    ki = None
    inodes = [heap]
    #find the rightmost in bottom of heap
    while len(inodes) > 0:
        tnodes = []
        for inode in inodes:
            if inode.left != None:
               ki = inode.left.value
               tnodes.append(inode.left)
            elif inode.right != None:
               ki = inode.right.value
               tnodes.append(inode.right)
            else:
                ki = inode.value
        inodes = tnodes
    fix_maxheap(heap,ki)
    return max



def maxheap_sort(arr):
    heap =  construct_maxheap(arr)
    if heap == None or heap.value == None:
        return -1
    for i in range(0,len(arr)):
        max = delete_max(heap)
        arr[i] = max
    return arr

if __name__ == "__main__":
    arr_str = input("Please input line of number to be sorted:\n")
    arr = arr_str.split(" ")
    arr = list(map(int,arr))
    print(arr)
    maxheap_sort(arr)
    print("sorted_arr:")
    print(arr)
```
> **Note:** 
>
> 堆排序的算法主要的难点是如果构建最小堆和最大堆。

> **Note:** 堆排序算法的主要操作为：
>
> 1. 构建最大堆/最小堆 (参见：[最大堆的构建](https://github.com/duanqiaobb/interview/tree/master/datastruct#非递归实现)/[最小堆的构建](https://github.com/duanqiaobb/interview/tree/master/datastruct#非递归实现)) 
>
> 2. 调整最大堆/最小堆 (参见：[调整最大堆]()/[调整最小堆]())

## 常用查找算法

### 顺序查找

+ 思路

```
从数组的开头到结尾,顺序挨个比较查找。
```

+ 算法复杂度

&ensp;&ensp;&ensp;&ensp;平均算法复杂度为：O(n)= n; 最坏情况的算法复杂度为：O(n) = n;

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

+ 思路

```
前提： 数组必须是已经排好序的有序数组。

假设数组为升序排列，把数组一分为二，取中间点mid做比较，如果比mid大, 那么继续在[mid+1,last]中查找，反之
在[first,mid-1]中查找，对子数组继续进行上述操作,直到找到。
```

+ 算法复杂度

&ensp;&ensp;&ensp;&ensp;平均算法复杂度为： O(n) = logn；最坏情况的算法复杂度为： O(n) = logn;


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

+ 思路

```
前提： 1.块间有序 2.块内可以无序 3.索引中保存块的起始地址，和块内的最大值或者最小值
   
首先对索引进行折半查找，然后对块内进行顺序查找。

```

+ 算法复杂度

&ensp;&ensp;&ensp;&ensp;假设一个n长度的数组分为m块，每块的长度为： n/m, 那么算法的平均复杂度：
O(n) = logm+n/m, 算法最坏情况下的复杂度： O(n) = logm + n/m。

#### cpp实现

```cpp
struct block {
    int bindex;
    int blen;
    int bmax;
    int* belements;
};

int Partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int highvac = end;
    int lowvac = start;
    int direct = true; //true for right,false for left. start from left 
    while(lowvac < highvac) {
        if(direct == true) {
            if(arr[highvac] <pivot) {
                arr[lowvac] = arr[highvac];
                lowvac++;
                direct = false;
            } else {
                highvac--;
            }
        } else {
            if(arr[lowvac] > pivot) {
                arr[highvac] = arr[lowvac];
                highvac--;
                direct = true;
            } else {
                lowvac++;
            }
        }
    }
    arr[highvac] = pivot;
    return highvac;
}


int  findXMaxValue(int arr[], int xmax, int start, int end) {
    int p = 0;
    int cmax = end - start +1;
    int len  = end;
    if (xmax >= len+1) {
        return p;
    }
    while(cmax != xmax) {
       p = Partition(arr,start,end);
       cmax = len-p+1;
        if(cmax > xmax) {
            start = p+1;
        }  else if ( cmax < xmax)  {
            end = p-1;
            start = 0;
        }
    }
   return p;
}

//find the max value
int findMaxValue(int arr[], int start, int end) {
    int max = arr[start];
    int len = end - start+1;
    for(int i = 0; i < len; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int blockIndexSearch(block dest_arr[], int search, int array_size) {
    //search the block index by binarysearch at first
    int left = 0;
    int right = array_size -1;
    while(left <= right){
        int amid = (right+left)/2;
        int bmax = dest_arr[amid].bmax;
        if (search > dest_arr[amid].bmax) {
            left = amid +1;
        } else {
            //order search in block
            int* belements = dest_arr[amid].belements;
            int blen = dest_arr[amid].blen;
            int bindex = dest_arr[amid].bindex;
            for(int i = 0; i< blen; i++) {
                if(search == belements[i]) {
                    return i+bindex;
                } else {
                    i++;
                }
            }
            right = amid-1;
        } 
    }
    return -1;
}

//generate blockIndex
block* blockIndex(int dest_arr[],int block_num, int array_size) {
    static block* block_arr = new block[block_num];
    int block_size = array_size/block_num;
    int block_indexes[block_num];
    int csize = array_size;
    for( int i = 0; i < block_num-1 && csize > block_size; i++) {
        int p = findXMaxValue(dest_arr,block_size, 0, csize-1);
        csize = csize-block_size;
        //cout << "Xmax position:" << p <<  endl;
        block_indexes[i] = p;
    }
    block_indexes[block_num-1] = 0;
    printArray(block_indexes,block_num);
    //generate block-indexed array
    for(int j = block_num -1; j >= 0; j--) {
      int bindex = block_indexes[j];
      int bend = array_size;
      if (j != 0) {
          bend = block_indexes[j-1];
      } 
      int blen = bend - bindex;
      int* belements = new int[blen];
      for(int i = 0; i < blen; i++ ) {
          belements[i] = dest_arr[bindex+i];
      }
      int bmax = findMaxValue(belements,0,blen-1);
      struct block tblock = {bindex,blen,bmax, belements};
      int index = block_num-1-j;
      block_arr[index] = tblock; 
    }

    return block_arr;
}
```


## 其他算法

### 查找数组中的前M大的数

+ 思路

```
根据快速排序的Partition的思想，假定数组长度为n, 选定一个pivot,总能将数组分为 [0,k-1]和[k,n], 
其中[0,k-1]<pivot,[k+1,n] > pivot。如果 k = m, 那么算法结束。如果k > m, 对[k+1,n]继续进行切分,
每次切分k都会减少一部分, 直到k = m, 如果k < m, 对[0,k-1]继续切分出m-k个大的数， 每次切分k都会
增加一部分，直到k = m。 
```

+ 算法复杂度

&ensp;&ensp;&ensp;&ensp;平均算法复杂度为：O(n) = n，最坏情况的复杂度为：O(n) = n。



#### cpp实现

```cpp
int Partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int highvac = end;
    int lowvac = start;
    int direct = true; //true for right,false for left. start from left 
    while(lowvac < highvac) {
        if(direct == true) {
            if(arr[highvac] <pivot) {
                arr[lowvac] = arr[highvac];
                lowvac++;
                direct = false;
            } else {
                highvac--;
            }
        } else {
            if(arr[lowvac] > pivot) {
                arr[highvac] = arr[lowvac];
                highvac--;
                direct = true;
            } else {
                lowvac++;
            }
        }
    }
    arr[highvac] = pivot;
    return highvac;
}

int*  findXMaxValue(int arr[], int xmax, int start, int end) {
    int p = 0;
    static int*  maxs = new int[xmax];
    int cmax = end - start +1;
    int len  = end;
    if (xmax >= len+1) {
        return arr;
    }
    while(cmax != xmax) {
       p = Partition(arr,start,end);
       cmax = len-p+1;
        if(cmax > xmax) {
            start = p+1;
        }  else if ( cmax < xmax)  {
            end = p-1;
            start = 0;
        }
    }
    for(int j = 0; j < xmax;  j++) {
        maxs[j] = arr[p+j];
    }
    return maxs;
}
```

### 翻转数列

```
小Q定义了一种数列称为翻转数列:
给定整数n和m, 满足n能被2m整除。对于一串连续递增整数数列1, 2, 3, 4..., 每隔m个符号翻转一次, 最初符号为'-';。
例如n = 8, m = 2, 数列就是: -1, -2, +3, +4, -5, -6, +7, +8.
而n = 4, m = 1, 数列就是: -1, +2, -3, + 4.
小Q现在希望你能帮他算算前n项和为多少。

输入描述:
输入包括两个整数n和m(2 <= n <= 109, 1 <= m), 并且满足n能被2m整除。

输出描述:
输出一个整数, 表示前n项和。

输入例子1:
 8 2

输出例子1:
 8
```
+ 思路

```
1. n能被2m整除，我们可以得出, n 为2m的整数倍，
2. 根据数列的规律，2m个元素的和为m^2
所以我们可以把n个元素划分为多个2m元素组成的块，x = n/(2*m),
那么前n项的和可以看作这些块的总和：S_n = x*m^2 = n/(2*m)*m^2 = n/2 * m
```

+ 算法复杂度

&ensp;&ensp;&ensp;&ensp;算法的平均复杂度: O(n) = 1; 最坏情况下的复杂度为：O(n) = 1。

#### cpp实现

```cpp
#include <iostream>
using namespace std;
long sumn_reverse_permutation(int n, int m) {
    if ( n < 2 || n > 1000000000 || m < 1 || n % (2*m) != 0 ) {
        return -1;
    }
    long num_2m = n / (2*m);
    long sum_n = num_2m * m * m;
    return sum_n;
}
int main(int argc, char** argv) {
    int n, m;
    scanf("%d %d",&n, &m);
    long sum_n = sumn_reverse_permutation(n,m);
    cout << sum_n << endl;
} 
```

> **Note:** 注意c++的`int`类型表示的数值范围为：0~2^32次方，无法表示最后的存储结果，
> 同时如果计算的时候都是`int`类型的话，编译器不会自动将类型转换为`long`类型，需要
> 将计算时的其中一个元素定义为`long`类型，然后计算结果也存储为`long`类型。

### 纸牌游戏

```
时间限制：1秒

空间限制：32768K

牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字a_i。
牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
他们的得分等于他们抽到的纸牌数字总和。
现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。


输入描述:
输入包括两行。
第一行包括一个正整数n(1 <= n <= 10^5),表示纸牌的数量。
第二行包括n个正整数ai(1 <= a_i <= 10^9),表示每张纸牌上的数字。

输出描述:
输出一个整数, 表示游戏结束后牛牛得分减去羊羊得分等于多少。

输入例子1:
3
2 7 4

输出例子1:
5
```
+ 思路

```
1. 首先我们可以将他们抽取纸牌的顺序抽象成一个数列，由于两个采取的都是最优的策略，
所以这个数列是一个从大到小排序的有n个元素的数列.
2. 而我们需要求的是牛牛的得分减去羊羊的得分，于是我们可以把上面的数列中代表羊羊的分
数的数倒置为负数，这样我们实际要求的就是这个数列的前n项和。
比如: 2 7 4 ->(排序) 7 4 2  -> (倒置) -> 7 -4 2 -> (求前n项和) 7 + (-4) + 2 = 5
```
> **Note:** 由于效率的考虑，排序算法需要用快速排序，才能AC

+ 算法复杂度

&ensp;&ensp;&ensp;&ensp; 算法的平均复杂度：O(n) = logn + n + n-1 = n ；算法的最坏情况下的复杂度：O(n) = n^2+ n + n-1 = n^2。

#### cpp实现

```cpp
#include<iostream>
using namespace std;
int quick_sort(int arr[], int start,int end) {
    int size = end - start+1;
    if (size <= 1) {
        return -1;
    }
    int left = start;
    int right = end;
    int pivot = left;
    int x = arr[pivot];

    while( left != right ) {
        while(arr[right] <= x && left < right) {
            right--;
        }
        while(arr[left]>=  x && left < right) {
            left++;
        }
        if(arr[left]< arr[right]) {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }

    arr[pivot] = arr[right];
    arr[right] = x ;
    quick_sort(arr,start, right-1);
    quick_sort(arr,right+1,end);
    return 0;


}
int shift_symbols(int arr[], int size) {
    if (size < 1) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        if (i % 2 != 0) {
            arr[i] = -arr[i];
        }
    }
    return 0;
}

int sum(int arr[], int size)  {
    int sum = 0;
    if (size < 1) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        sum+= arr[i];
    }
    return sum;
}
int playing_cards(int cards_num, int card_numbers[]) {
    if ( cards_num < 1 || cards_num > 100000) {
        return -1;
    }
    //sort the card_nums in asc order, quick sort
    quick_sort(card_numbers,0, cards_num-1);
    shift_symbols(card_numbers,cards_num);
    int s = sum(card_numbers,cards_num);
    return s;
}

int main(int argc, char** argv) {
    int card_num;
    cin >> card_num;
    int* card_numbers = (int *)malloc(card_num*sizeof(int));
    cin.ignore();
    for (int i = 0; i < card_num; i++) {
        int tmp;
        cin >> tmp;
        card_numbers[i] = tmp;
    }
    cout << playing_cards(card_num,card_numbers) << endl;
}

```
