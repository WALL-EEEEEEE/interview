# ADT: Heap
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

if __name__ == "__main__":
    arr = [3, 2, 1, 3, 4]
    print("Construct heap norecursively:")
    max_heap = construct_maxheap(arr)
    min_heap = construct_minheap(arr)
    print("max_heap:")
    print(max_heap)
    print("min_heap:")
    print(min_heap)
