#include <stdio.h>
#include<iostream>
using namespace std;

template <class Type>
void printArray(Type arr[], int size) {
    int len = size;
    for (int i = 0; i < len; i++) {
        cout << arr[i]<< "\t";
    }
    cout << endl;
}
void quicksort(int a[],int left, int right)
{
    int i,j,t,temp;
    if (left > right) 
        return;
    temp = a[left];
    i = left;
    j = right;
    while(i != j) 
    {
        while(a[j] >= temp && i < j) {
            j--;
        }
        while(a[i] <= temp && i < j) {
            i++;
        }
        if (i < j) 
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    a[left] = a[i];
    a[i] = temp;
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
}
int main()
{
    int test_arr[] = {6,0,3,1,2,5,1,1,1};
    int len = sizeof(test_arr)/sizeof(*test_arr);
    printArray(test_arr,len);
    quicksort(test_arr,0,len-1);
    printArray(test_arr,len);
}
