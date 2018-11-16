#include<stdio.h>
int orderSearch(int dest_arr[],int  dest, int arr_size) {

    int arr_len = arr_size;
    for(int i = 0; i <= arr_len; i++) {
        if (dest_arr[i] == dest) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char ** argvs) {
    int arr[] = { 3,6,2,4,1 };
    //test search for 3
    int dest_key = orderSearch(arr, 3,sizeof(arr)/sizeof(*arr));
    printf("find key: %d\n",dest_key);
    //test search for 1
    dest_key = orderSearch(arr,4,sizeof(arr)/sizeof(*arr));
    printf("find key: %d\n", dest_key);
}
