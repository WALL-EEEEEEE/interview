# 面试数据结构

<!--ts-->
   * [面试数据结构](#面试数据结构)
      * [堆（左完全二叉树）](#堆左完全二叉树)
         * [定义](#定义)
         * [实现](#实现)
            * [递归实现](#递归实现)
               * [python实现](#python实现)
            * [非递归实现](#非递归实现)
               * [python实现](#python实现-1)

<!-- Added by: johans, at:  -->

<!--te-->

## 堆（左完全二叉树）

### 定义

``` basic
如果一个二叉树 T 具有如下几个性质，我们就可以将它称作堆：

1. 二叉树 T 至少是一个深度为 h -1的完全二叉树。
2. 二叉树 T 的所有叶子都在深度为 h 或 h-1 的节点上。
3. 二叉树 T 所有到达深度为 h 的叶子结点的路径都在到达深度为 h-1 的叶子结点的路径的左边。
4. 二叉树 T 的节点的值大于（最大堆）/小于（最小堆）或等于节点的任意子节点的值
```

### 实现

&ensp;&ensp; 从堆的定义来看，我们可以用二叉树来实现堆。二叉树的数据结构，定义如下：

```python
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
```

然后我们可以通过定义的`二叉树` 数据结构来构建一个`堆`数据结构，而构建过程，我们可以采用 `递归` 和 `非递归` 两种方式来实现。

#### 递归实现

##### python实现

```python

```

#### 非递归实现

`堆`构建的非递归实现，这里我们可以通过`层次遍历`二叉树来生成一个`堆`结构

##### python实现

1. 构建最小堆

   ```python
   # 构建一个最小堆
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
   ```

2. 构建最大堆

3. ```python
   # 构建一个最大堆
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
   ```

