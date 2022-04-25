#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;
unordered_map<string, int> input_time;
map<string, int> times;

int cal(vector<int>& fees, int time) {
    int used_time = time - fees[0];
    int money = fees[1];
    if (used_time > 0) {
        money += ceil(used_time / (double)fees[2]) * fees[3];
    }
    return money;
}

int gettime(string str) {
    int time = stoi(str.substr(0, 2)) * 60;
    time += stoi(str.substr(3, 2));
    return time;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for (string str : records) {
        stringstream ss(str); string tmp;
        getline(ss, tmp, ' ');
        int time = gettime(tmp);
        getline(ss, tmp, ' ');
        string number = tmp;
        getline(ss, tmp, ' ');
        if (tmp.compare("IN") == 0) {
            input_time.insert({ number, time });
        }
        else {
            times[number] += (time - input_time.find(number)->second);
            input_time.erase(number);
        }
    }
    for (auto it : input_time) {
        times[it.first] += (1439 - input_time.find(it.first)->second);
    }
    for (auto tmp : times) {
        answer.push_back(cal(fees, tmp.second));
    }
    return answer;
}