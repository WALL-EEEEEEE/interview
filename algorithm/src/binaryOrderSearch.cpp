#include<stdio.h>
int binaryOrderSearch(int dest_arr[], int search, int array_size) {
    //assume dest_arr is ascend sorted.
    int alen = array_size;
    int amid =  alen/2;
    int left = 0;
    int right = alen-1;
    while(right-left > 0) {
        if (dest_arr[amid] < search) {
            left = amid+1;
            amid = (left+ right) /2;
        } else if (dest_arr[amid] > search) {
            right = amid-1;
            amid = (left+right)/2;
        } else {
            return amid;
        }
    }
    return -1;
}

int main(int argc, char** args) {
    int test_arr[] = { 1,2,3,5,6 };
    //test for searching 3
    int dest_key = binaryOrderSearch(test_arr, 3,sizeof(test_arr)/sizeof(*test_arr));
    printf("Search for 3: %d\n", dest_key);
    //test for searching 4
    dest_key = binaryOrderSearch(test_arr,4,sizeof(test_arr)/sizeof(*test_arr));
    printf("Search for 4: %d\n", dest_key);
    //test for searching 5
    dest_key = binaryOrderSearch(test_arr,5,sizeof(test_arr)/sizeof(*test_arr));
    printf("Search for 5: %d\n", dest_key);

}
