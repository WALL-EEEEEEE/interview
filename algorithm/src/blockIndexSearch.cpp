#include<iostream>

using namespace std;
template <class Type>
void printArray(Type arr[], int size) {
    int len = size;
    int *p = arr;
    for (int i = 0; i < len; i++) {
        cout << arr[i]<< "\t";
    }
    cout << endl;
}

struct block {
    int bindex;
    int blen;
    int bmax;
    int* belements;
};

void printBlockArray(block * blockarr, int size) {
    int len = size;
    cout << "Block Array:[ " << endl; 
    for (int i = 0; i < size; i++ ) {
        cout << blockarr[i].bindex << "=> array(len="<< blockarr[i].blen << ", max=" << blockarr[i].bmax << ") {";
        for (int j = 0; j < blockarr[i].blen; j++) {
            cout << blockarr[i].belements[j]<< ",";
        }
        cout << "}"<<endl;
    }
    cout <<"]" << endl;

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


int  findXMaxValue(int arr[], int xmax, int start, int end) {
    int p = 0;
    int cmax = end - start +1;
    int len  = end;
    if (xmax >= len+1) {
        return p;
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
   return p;
}

//find the max value
int findMaxValue(int arr[], int start, int end) {
    int max = arr[start];
    int len = end - start+1;
    for(int i = 0; i < len; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

//quick sort


int blockIndexSearch(block dest_arr[], int search, int array_size) {
    //search the block index by binarysearch at first
    int left = 0;
    int right = array_size -1;
    while(left <= right){
        int amid = (right+left)/2;
        int bmax = dest_arr[amid].bmax;
        if (search > dest_arr[amid].bmax) {
            left = amid +1;
        } else {
            //order search in block
            int* belements = dest_arr[amid].belements;
            int blen = dest_arr[amid].blen;
            int bindex = dest_arr[amid].bindex;
            for(int i = 0; i< blen; i++) {
                if(search == belements[i]) {
                    return i+bindex;
                } else {
                    i++;
                }
            }
            right = amid-1;
        } 
    }
    return -1;
}

//generate blockIndex
block* blockIndex(int dest_arr[],int block_num, int array_size) {
    static block* block_arr = new block[block_num];
    int block_size = array_size/block_num;
    int block_indexes[block_num];
    int csize = array_size;
    for( int i = 0; i < block_num-1 && csize > block_size; i++) {
        int p = findXMaxValue(dest_arr,block_size, 0, csize-1);
        csize = csize-block_size;
        //cout << "Xmax position:" << p <<  endl;
        block_indexes[i] = p;
    }
    block_indexes[block_num-1] = 0;
    printArray(block_indexes,block_num);
    //generate block-indexed array
    for(int j = block_num -1; j >= 0; j--) {
      int bindex = block_indexes[j];
      int bend = array_size;
      if (j != 0) {
          bend = block_indexes[j-1];
      } 
      int blen = bend - bindex;
      int* belements = new int[blen];
      for(int i = 0; i < blen; i++ ) {
          belements[i] = dest_arr[bindex+i];
      }
      int bmax = findMaxValue(belements,0,blen-1);
      struct block tblock = {bindex,blen,bmax, belements};
      int index = block_num-1-j;
      block_arr[index] = tblock; 
    }

    return block_arr;
}

int main(int argc, char** argv) {
    int test_arr[] = {6,0,3, 1, 2, 5,1,1,1,0};
    int len = sizeof(test_arr)/sizeof(*test_arr);
    cout << "Original array:" << endl;
    printArray(test_arr,len);
    int block_num = 3; // the number of block;
    block* block_arr = blockIndex(test_arr,block_num,len);
    printBlockArray(block_arr,block_num);
    printArray(test_arr,len);
    int search = 6;
    int index = blockIndexSearch(block_arr,search,block_num);
    cout << "Found in: " << index << endl;
}
