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

        
