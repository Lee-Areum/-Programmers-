#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    int index = 1;
    for (char c = 'A'; c <= 'Z'; c++) {
        string tmp; tmp += c;
        m.insert({ tmp,index++ });
    }
    for (int i = 0; i < msg.size(); i++) {
        string search; search += msg[i];
        while (i < (msg.size() - 1) && m.find(search + msg[i + 1]) != m.end()) {
            search += msg[++i];
        }
        answer.push_back(m.find(search)->second);
        if (i < (msg.size() - 1)) {
            m.insert({ search + msg[i + 1],index++ });
        }
    }
    return answer;
}