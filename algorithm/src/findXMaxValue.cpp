#include<iostream>

using namespace std;
template <class Type>
void printArray(Type arr[],int start, int end) {
    int len = end;
    for (int i = start; i <= len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int Partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int highvac = end;
    int lowvac = start;
    int direct = true; //true for right,false for left. start from left 
    while(lowvac < highvac) {
        if(direct == true) {
            if(arr[highvac] <pivot) {
                arr[lowvac] = arr[highvac];
                lowvac++;
                direct = false;
            } else {
                highvac--;
            }
        } else {
            if(arr[lowvac] > pivot) {
                arr[highvac] = arr[lowvac];
                highvac--;
                direct = true;
            } else {
                lowvac++;
            }
        }
    }
    arr[highvac] = pivot;
    return highvac;
}



int*  findXMaxValue(int arr[], int xmax, int start, int end) {
    int p = 0;
    static int*  maxs = new int[xmax];
    int cmax = end - start +1;
    int len  = end;
    if (xmax >= len+1) {
        return arr;
    }
    while(cmax != xmax) {
       p = Partition(arr,start,end);
       cmax = len-p+1;
        if(cmax > xmax) {
            start = p+1;
        }  else if ( cmax < xmax)  {
            end = p-1;
            start = 0;
        }
    }
    for(int j = 0; j < xmax;  j++) {
        maxs[j] = arr[p+j];
    }
    return maxs;
}

int main(int argc, char** argv) {
    int test_arr[] = {1,2,3,1};
    cout << "Original array:"  << endl;
    printArray(test_arr,0,sizeof(test_arr)/sizeof(*test_arr)-1);
    cout << "---------------------------------------------------------------------------" << endl;
    int max_num =  5;
    int* maxs;
    maxs  = findXMaxValue(test_arr,max_num,0,sizeof(test_arr)/sizeof(*test_arr)-1);
    cout << "After array:" << endl;
    printArray(test_arr,0,sizeof(test_arr)/sizeof(*test_arr)-1);
    cout << "Xmax value:" << endl;
    printArray(maxs,0,max_num-1);
}
