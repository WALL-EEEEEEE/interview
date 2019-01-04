# ADT: heap implemented by recursive
import os
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

def fix_maxheap(heap, K):
    if heap.left is not None:
        fix_maxheap(heap.left, heap.left.value)
        if heap.left.value > K:
            heap.value = heap.left.value
            heap.left.value = K
            fix_maxheap(heap.left, K)
    elif heap.right is not None:
        fix_maxheap(heap.right, heap.right.value)
        if heap.right.value > K:
            heap.value = heap.right.value
            heap.right.value = K
            fix_maxheap(heap.right, K)
    else:
        heap.value = K
    return heap

def fix_minheap(heap, K):
    if heap.left != None:
        fix_minheap(heap.left, heap.left.value)
        if heap.left.value < K:
            heap.value = heap.left.value
            heap.left.value = K
            fix_minheap(heap.left, K)
    elif heap.right is not None:
        fix_minheap(heap.right, heap.right.value)
        if heap.right.value < K:
            heap.value = heap.right.value
            heap.right.value = K
            fix_minheap(heap.right, K)
    else:
        heap.value = K
    return heap

def construct_maxheap_recursive(arr):
    """construct a maxheap in recursively way"""
    if len(arr) > 0:
        v = arr.pop()
        heap = BTNode(v)
    else:
        return None
    heap.left = construct_maxheap_recursive(arr)
    heap.right = construct_maxheap_recursive(arr)
    fix_maxheap(heap, heap.value)
    return heap

def construct_minheap_recursive(arr):
    """construt a minheap in recursive way"""
    if len(arr) > 0:
        v = arr.pop()
        heap = BTNode(v)
    else:
        return None
    heap.left = construct_minheap_recursive(arr)
    heap.right = construct_minheap_recursive(arr)
    fix_minheap(heap, heap.value)
    return heap


def deleteMin(heap):
    v = heap.value
    k = 0;
    # find the right most element
    tnode = heap
    while heap.right != None:
        heap = heap.right
    l = heap.value
    heap = None
    fix_minheap(heap, K)
    return v


def minheap_sort(heap, arr):
    if heap == None:
        return None
    v = deleteMin(heap)
    arr.append(v)
    if heap != None:
        minheap_sort(heap, arr)

if __name__ == '__main__':
    arr = [3, 2, 1, 5 ,3, 4, 6, 100,-100]
    tarr = arr[0:len(arr)]
    print(arr)
    print("Construct maxheap recursively:")
    max_heap = construct_maxheap_recursive(arr)
    min_heap = construct_minheap_recursive(tarr)
    print("max_heap:")
    print(max_heap)
    print("min_heap:")
    print(min_heap)
    print("minheap_sort:")
    minsorted_arr = []
    minheap_sort(min_heap, minsorted_arr)
    print(minsorted_arr)
 
