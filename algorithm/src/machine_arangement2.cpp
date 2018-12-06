#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct cmp_revenue{
    bool operator()(const vector<int>& lhs, const vector<int>& rhs) const {
        /**
        int lhs_re = 200*lhs[0]+3*lhs[1];
        int rhs_re = 200*rhs[0]+3*lhs[1];
        **/
        return lhs > rhs;
    }
} cmp_revenue;


struct machine_stat {
    int time;
    int level;
    int tcount;
};



vector<long long> machine_arrangement(vector<vector<int>> machines, vector<vector<int>> tasks, int machine_number, int task_number) {

    long long  total_revenue = 0;
    int count = 0;
    vector<long long> results = {0,0};
    vector<machine_stat> machine_stats; 
    struct cmp_size {
        bool operator()(const machine_stat& lhs, const machine_stat& rhs) const {
            return lhs.tcount < rhs.tcount;
        }
    }cmp_size;


    for(auto machine :machines) {
        int count = 0 ;
        for(auto it = tasks.begin(); it != tasks.cend() ; it++){
            if(machine[0] >= (*it)[0] && machine[1] >= (*it)[1]) {
                count++;
            }
        }
        if(count > 0) {
            machine_stat mstat = {machine[0],machine[1],count};
            machine_stats.push_back(mstat);
        }
    }
    sort(machine_stats.begin(), machine_stats.end(),cmp_size);
    for(auto t: tasks) {
        for(auto it = machine_stats.begin(); it != machine_stats.end(); ) {
            if (t[0] <= (*it).time && t[1] <= (*it).level)  {
                total_revenue+= 200*t[0]+3*t[1];
                count++;
                it = machine_stats.erase(it);
                break;
            } else {
                ++it;
            }
        }
    }
    results[0] = count;
    results[1] = total_revenue;
    return results;
}

int main(int argc, char** argv) {
    int machine_number;
    int task_number;
    vector<vector<int>> machines;
    vector<vector<int>> tasks;
    cin >> machine_number;
    cin >> task_number;
    for(int i = 0; i < machine_number; i++) {
        int time = 0, level =0;
        cin.ignore();
        cin >> time;
        cin >> level;
        vector<int> desc{time, level};
        machines.push_back(desc);
    }

    for(int j = 0; j < task_number; j++) {
        int time = 0, level =0;
        cin.ignore();
        cin >> time;
        cin >> level;
        vector<int> desc {time, level};
        tasks.push_back(desc);
    }
    sort(tasks.begin(),tasks.end(),cmp_revenue);
    vector<long long> result = machine_arrangement(machines,tasks,machine_number,task_number);
    cout << result[0] << " " << result[1] << endl;
}

