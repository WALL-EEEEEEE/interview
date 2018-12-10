#
# MergeSort implemented by python
#
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

