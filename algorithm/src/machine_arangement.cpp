/**
 *[编程题] 安排机器
 时间限制：1秒

 空间限制：32768K

 小Q的公司最近接到m个任务, 第i个任务需要xi的时间去完成, 难度等级为yi。
 小Q拥有n台机器, 每台机器最长工作时间zi, 机器等级wi。
 对于一个任务,它只能交由一台机器来完成, 如果安排给它的机器的最长工作时间小于任务需要的时间, 则不能完成,如果完成这个任务将获得200 * xi + 3 * yi收益。

 对于一台机器,它一天只能完成一个任务, 如果它的机器等级小于安排给它的任务难度等级, 则不能完成。

 小Q想在今天尽可能的去完成任务, 即完成的任务数量最大。如果有多种安排方案,小Q还想找到收益最大的那个方案。小Q需要你来帮助他计算一下。


 输入描述:
 输入包括N + M + 1行,
 输入的第一行为两个正整数n和m(1 <= n, m <= 100000), 表示机器的数量和任务的数量。
 接下来n行,每行两个整数zi和wi(0 < zi < 1000, 0 <= wi <= 100), 表示每台机器的最大工作时间和机器等级。
 接下来的m行,每行两个整数xi和yi(0 < xi < 1000, 0 <= yi<= 100), 表示每个任务需要的完成时间和任务的难度等级。

 输出描述:
 输出两个整数, 分别表示最大能完成的任务数量和获取的收益。

 输入例子1:
 1 2
 100 3
 100 2
 100 1

 输出例子1:
 1 20006
 *
 *
 *
 *
 */
#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> machine_arrangement(vector<vector<int>> machines, vector<vector<int>> tasks, int machine_number, int task_number) {
    int tasks_count = 0;
    int total_revenue = 0;
    map<vector<int>,vector<vector<int>>> avail_tasks;
    map<vector<int>,vector<int>> optimal_tasks;
    //filter tasks by each machine
    for(auto machine :machines) {
        int max_revenue = 0;
        auto task_id = tasks.begin();
        auto max_task_id = tasks.begin(); 

        vector<vector<int>> tmp_tasks;
        for(auto it = task_id; it != tasks.cend() ; it++){
            if(machine[0] >= (*it)[0] && machine[1] >= (*it)[1]) {
                int cur_revenue = 200*(*it)[0] + 3*(*it)[1];
                if(cur_revenue>max_revenue) {
                    max_revenue = cur_revenue;
                    max_task_id = it;
                }
                tmp_tasks.push_back(*it);
            }
            cout << "tasks size:" << tasks.size() << endl;
        }
        avail_tasks[machine] = tmp_tasks;
        if (max_revenue!=0) {
            tasks_count++;
            total_revenue+=max_revenue;
            optimal_tasks[machine] = *max_task_id;
            tasks.erase(max_task_id);
        }
    }
    for(auto machine :optimal_tasks) {
        vector<int> m = machine.first;
        vector<int> ts = machine.second;
        cout << "machine :("  << m[0] << ","<< m[1] << ")" << endl;
        cout << "{" << endl;
        cout << "optimal_task: " << ts[0] << "," << ts[1] << endl;
        cout << "}" << endl;
    }


    vector<int> result{tasks_count,total_revenue};

    return result;
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
    vector<int> result = machine_arrangement(machines,tasks,machine_number,task_number);
    cout << result[0] << " " << result[1] << endl;
    /**
    cout << "machine_number: " << machine_number << endl;
    cout << "task_number:" << machine_number << endl;
    cout << "machines:" << endl;
    for(auto i: machines) {
        cout << "time:" << i[0] << ",level:" << i[1]  << endl;
    }
    cout << "tasks:" << endl;
    for (auto j: tasks) {
        cout << "time:" << j[0] << ",level:" << j[1] << endl;
    }
    **/

}

