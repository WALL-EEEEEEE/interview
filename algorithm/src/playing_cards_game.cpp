/**
[编程题] 纸牌游戏
时间限制：1秒

空间限制：32768K

牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字a_i。
牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
他们的得分等于他们抽到的纸牌数字总和。
现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。


输入描述:
输入包括两行。
第一行包括一个正整数n(1 <= n <= 10^5),表示纸牌的数量。
第二行包括n个正整数ai(1 <= a_i <= 10^9),表示每张纸牌上的数字。

输出描述:
输出一个整数, 表示游戏结束后牛牛得分减去羊羊得分等于多少。

输入例子1:
3
2 7 4

输出例子1:
5
**/
#include<iostream>
using namespace std;
int quick_sort(int arr[], int start,int end) {
    int size = end - start+1;
    if (size <= 1) {
        return -1;
    }
    int left = start;
    int right = end;
    int pivot = left;
    int x = arr[pivot];

    while( left != right ) {
        while(arr[right] <= x && left < right) {
            right--;
        }
        while(arr[left]>=  x && left < right) {
            left++;
        }
        if(arr[left]< arr[right]) {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }

    arr[pivot] = arr[right];
    arr[right] = x ;
    quick_sort(arr,start, right-1);
    quick_sort(arr,right+1,end);
    return 0;


}
int shift_symbols(int arr[], int size) {
    if (size < 1) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        if (i % 2 != 0) {
            arr[i] = -arr[i];
        }
    }
    return 0;
}

int sum(int arr[], int size)  {
    int sum = 0;
    if (size < 1) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        sum+= arr[i];
    }
    return sum;
}
int playing_cards(int cards_num, int card_numbers[]) {
    if ( cards_num < 1 || cards_num > 100000) {
        return -1;
    }
    //sort the card_nums in asc order, quick sort
    quick_sort(card_numbers,0, cards_num-1);
    shift_symbols(card_numbers,cards_num);
    int s = sum(card_numbers,cards_num);
    return s;
}

int main(int argc, char** argv) {
    int card_num;
    cin >> card_num;
    int* card_numbers = (int *)malloc(card_num*sizeof(int));
    cin.ignore();
    for (int i = 0; i < card_num; i++) {
        int tmp;
        cin >> tmp;
        card_numbers[i] = tmp;
    }
    cout << playing_cards(card_num,card_numbers) << endl;
}

