#include<stdio.h>
int orderSearch(int dest_arr[],int  dest) {

    int arr_len = sizeof(dest_arr)/sizeof(*dest_arr);
    for(int i = 0; i <= arr_len; i++) {
        if (dest_arr[i] == dest) {
            return i;
        }
    }
}

int main(int argc, char ** argvs) {
    int arr[] = { 3,6,2,4,1 };
    //test search for 3
    int dest_key = orderSearch(arr, 3);
    printf("find key: %d\n",dest_key);
    //test search for 1
    dest_key = orderSearch(arr,4);
    printf("find key: %d\n", dest_key);
}
