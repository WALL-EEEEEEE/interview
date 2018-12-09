#
# bubble sort implemented by python
#
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
