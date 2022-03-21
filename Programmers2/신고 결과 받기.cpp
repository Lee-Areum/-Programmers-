#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> reported_num;
    unordered_map<string, unordered_set<string>> report_list;
    for (string str : report) {
        stringstream ss(str);
        string first,second;
        ss.str(str);
        ss >> first;
        ss >> second;
        if (report_list[first].find(second) == report_list[first].end()) {
            reported_num[second]++;
            report_list[first].insert(second);
        }
    }
    for (string name : id_list) {
        int count = 0;
        for (string reportName : report_list[name]) {
            if (reported_num[reportName] >= k) count++;
        }
        answer.push_back(count);
    }

    return answer;
}