/**
 [编程题] 小Q的歌单

 时间限制：1秒

 空间限制：32768K

 小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，现在小Q想用这些歌组成一个总长度正好为K的歌单，每首歌最多只能在歌单中出现一次，在不考虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。

 输入描述:
 每个输入包含一个测试用例。
 每个测试用例的第一行包含一个整数，表示歌单的总长度K(1<=K<=1000)。
 接下来的一行包含四个正整数，分别表示歌的第一种长度A(A<=10)和数量X(X<=100)以及歌的第二种长度B(B<=10)和数量Y(Y<=100)。保证A不等于B。

 输出描述:
 输出一个整数,表示组成歌单的方法取模。因为答案可能会很大,输出对1000000007取模的结果。

 输入例子1:
 5
 2 3 3 3

 输出例子1:
 9
 */

/**
 * Caculate the combination numbers
 */
#include<iostream>
#include<cmath>
#include<numeric>
using namespace std;

#define M 1000000007;
#define Max 2000000014;
int gcd(int a, int b) {
    while(b!= 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long combine(int number, int select) {
    if (number < 0 || select < 0 || select > number) {
        return 0;
    }
    //simplify caculate
    if(select > number/2 ) {
        select = number-select;
    }
    int nfactors[select];
    int nselect[select];
    //init the nfactors
    for(int i = 0; i < select; i++) {
        nfactors[i] = number-i;
        nselect[i] = select -i;
    }
    for (int i = 0; i< select; i++) {
        for(int j = 0; j < select; j++) {
            int d = gcd(nselect[i],nfactors[j]);
            if(d > 1) {
                nselect[i] = nselect[i]/d;
                nfactors[j] = nfactors[j]/d;
                if (nselect[i]<=1) break;
            }
        }
    }
    long long c = 1;
    for(int i = 0; i < select;i++) {
        c = c*nfactors[i]%M;
    }
    return c;
}
int combine_klist(int llen, int llen_first, int lnum_first, int llen_second, int lnum_second, int(*results)[2]) {
    int start,num_start,end;
    int count = 0;
    if(llen_first > llen_second) {
        start = llen_first;
        end = llen_second;
    } else {
        start = llen_second;
        end = llen_first;
    }
    if (start == 0) {
        return 0;
    }
    num_start = llen/start;
    if (end != 0) {
        for(int i = num_start; i >= 0 ; i--){
            if ((llen-i*start)%end == 0) {
                int num_end = (llen - i*start)/end;
                int pairs[2];
                if(llen_first > llen_second) {
                    pairs[0] = i;
                    pairs[1] = num_end;
                } else {
                    pairs[0] = num_end;
                    pairs[1] = i;
                }
                (*results)[0] = pairs[0];
                (*results)[1] = pairs[1];
                count++; 
                results++;
            }
        }
    } else {
            if(llen%start == 0) {
                count++;
                (*results)[0] = num_start;
                (*results)[1] = 0;
            }
    }
    return count;
}

long qmusic_list(int llen, int llen_first, int lnum_first, int llen_second, int lnum_second) {
    //restrain conditions
    if (llen <  1 || llen > 1000 || llen_first > 10 || llen_first < 0 || lnum_first > 100 || llen_second > 10 || llen_second < 0 || lnum_second > 100 || llen_first == llen_second ) {
        return 0;
    }
    int start = llen_first;
    if (llen_first <= llen_second ) {
        start = llen_second;
    }
    if (start == 0 ) {
        return 0;
    }
    int max_poss = llen/start+1; 

    int (*combines_k)[2]  = (int (*)[2])malloc(sizeof(int[max_poss][2]));
    long num_kinds = 0;
    int combines_count = combine_klist(llen,llen_first, lnum_first, llen_second,lnum_second,combines_k);
    for(int i= 0; i < combines_count; i++) {
        int* pairs  = combines_k[i];
        if(pairs[0] <= lnum_first && pairs[1] <= lnum_second) {
           num_kinds+=combine(lnum_first,pairs[0])*combine(lnum_second,pairs[1]);
        }
    }
    // caculate the combination of <llen> list with elements between <llen_first> and  <llen_second> lists. 
    //free the memory
    free(combines_k);
    return num_kinds%M;
}
int main(int argc, char** argv) {
    int k;
    int lfirst;
    int nfirst;
    int lsecond;
    int nsecond;
    cin >> k;
    cin.ignore();
    cin >> lfirst;
    cin >> nfirst;
    cin >> lsecond;
    cin >> nsecond;
    cout << qmusic_list(k,lfirst,nfirst,lsecond,nsecond) << endl;
}
