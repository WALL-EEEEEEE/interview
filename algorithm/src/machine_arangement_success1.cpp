#include <iostream>
#include <algorithm>
using namespace std;
 
struct node{
    int time;
    int level;
}machine[100001],task[100001];
 
bool cmp(node a, node b){
    if(a.time == b.time)
        return a.level > b.level;
    return a.time > b.time;
}
 
int main()
{
   int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>machine[i].time>>machine[i].level;
    }
    for(int i=0;i<m;++i){
        cin>>task[i].time>>task[i].level;
    }
    sort(machine, machine+n, cmp);
    sort(task, task+m, cmp);
    int numarr[101] = {0}, count = 0;
    long long result = 0;
    for(int i=0,j=0;i<m;++i){
        while(j<n && machine[j].time>=task[i].time){
            ++numarr[machine[j].level];
            j++;
        }
        for(int k=task[i].level;k<=100;++k){
            if(numarr[k]){
                --numarr[k];
                ++count;
                result += (200*task[i].time + 3*task[i].level);
                break;
            }
        }
    }
    cout<<count<<" "<<result<<endl;
   return 0;
}
