#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool arange(string n1, string n2) {
    return n1.size() < n2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> list;
    stringstream ss(s.substr(1, s.size() - 2));
    string tmp;
    getline(ss, tmp, '}');
    list.push_back(tmp.substr(1, tmp.size() - 1));
    while (getline(ss, tmp, '}')) {
        list.push_back(tmp.substr(2, tmp.size() - 1));
    }
    sort(list.begin(), list.end(), arange);
    for (string str : list) {
        stringstream ss(str);
        string tmp;
        while (getline(ss, tmp, ',')) {
            if (find(answer.begin(), answer.end(), stoi(tmp)) == answer.end()) {
                answer.push_back(stoi(tmp));
            }
        }
    }
    return answer;
}