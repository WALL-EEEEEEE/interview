#include<iostream>

using namespace std;

template <class Type>
void Swap(Type *a, Type *b) {
    Type tmp = *a;
    *a = *b;
    *b = tmp; 
}

template <class Type>
int Partition(Type arr[], int p , int r) {
    int i = p, j = r;
    Type x = arr[p];
    while(true) {
        while(arr[j]> x && i < j)  {
            j--;
        }
        while(arr[i]<= x && i < j ) {
            i++;
        } 
        if (i == j) break;
        Swap(&arr[i],&arr[j]);
    }
    Swap(&arr[p], &arr[j]);
    return j;
}

template<class Type>
void QuickSort(Type arr[], int p, int r) {
    if (p < r) {
        int q = Partition(arr,p,r);
        QuickSort(arr,p,q-1);
        QuickSort(arr,q+1,r);
    }
}

int main(int argc, char** argv) {
    int test_arr[] = {6,0,3, 1, 2, 5,1,1,1,0};
    int len = sizeof(test_arr)/sizeof(*test_arr);
    cout << "Original Array:" << endl;
    printArray(test_arr,len);
    QuickSort(test_arr,0,len-1);
    printArray(test_arr,len);
}
