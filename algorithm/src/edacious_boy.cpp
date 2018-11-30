/**
[编程题] 贪吃的小Q
时间限制：1秒

空间限制：32768K

小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，但是他又不想在父母回来之前的某一天没有巧克力吃，请问他第一天最多能吃多少块巧克力

输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，表示父母出差的天数N(N<=50000)和巧克力的数量M(N<=M<=100000)。

输出描述:
输出一个数表示小Q第一天最多能吃多少块巧克力。

输入例子1:
3 7

输出例子1:
4
**/
#include<cmath>
#include<iostream>

using namespace std;
int maxChocolate(int tripdays, int chocolate_nums) {
    if (tripdays > 50000 || chocolate_nums < tripdays || chocolate_nums > 100000) {
        return -1;
    }
    int max_num = 0;
    //caculate max sum of geometric sequence, common ratio of which is 2 less than or equal to chocolate
    int n = log2(chocolate_nums+1);
    //check if it match the tripdays 
    while(chocolate_nums-pow(2,n)+1+pow(2,n-1)+n-tripdays < 0) {
        n--;
    }
    if(n > tripdays) {
        n = tripdays;
    }
    max_num = pow(2,n-1);
    int available_days = n+chocolate_nums-pow(2,n)+1-tripdays;
    int incre_base = 0;
    int reverse_base = 0;
    int imple_num = 0;
    int base_change = 0;
    if (available_days!=0) {
        incre_base = available_days/abs(available_days);
        reverse_base = -incre_base;
    }
    while(available_days+imple_num*reverse_base != 0) {
        base_change++;
        int m = log2(base_change);
        int tmp_imple_num = 0;
        if(incre_base > 0) {
            tmp_imple_num = n;
        }
        int count = 0;
        while(count < n && count <= m) {
            if (incre_base < 0) {
                tmp_imple_num+= base_change/pow(2,count);
            } else {
                tmp_imple_num += (base_change-1)/pow(2,count);
            }
            count++;
        }
        imple_num = tmp_imple_num;
        if (imple_num > abs(available_days)) {
            if (incre_base > 0 ) {
                base_change--;
            }
            break;
        }
     
    }
    return max_num+base_change*(-reverse_base);
}

int main(int argc, char** argv) {
    int n,m;
    cin >> n >> m;
    cout << maxChocolate(n,m) << endl;
}
