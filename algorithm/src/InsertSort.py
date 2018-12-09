# 
# InsertSort algorithm  implemented by python
#
#
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

