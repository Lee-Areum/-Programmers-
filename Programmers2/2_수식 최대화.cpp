#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
long long best = 0;
set<string> s_oper;
vector<string> express;
void calculate(string op) {
    for (int i = 1; i < express.size(); i++) {
        if (express[i].compare(op) == 0) {
            long long num = stoi(express[i - 1]);
            switch (op[0]) {
            case '+':
                num += stoi(express[i + 1]);
                break;
            case '-':
                num -= stoi(express[i + 1]);
                break;
            case'*':
                num *= stoi(express[i + 1]);
                break;
            default:
                break;
            }
            express[i - 1] = to_string(num);
            express.erase(express.begin() + i, express.begin() + i + 2);
            i -= 2;
        }
    }
}

long long solution(string expression) {
    long long answer = 0;
    string tmp = "";
    vector<string> c_express;
    for (int i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i]) != 0) {
            tmp += expression[i];
        }
        else {
            express.push_back(tmp);
            string op;
            op += expression[i];
            express.push_back(op);
            s_oper.insert(op);
            tmp = "";
        }
    }
    express.push_back(tmp);
    c_express.assign(express.begin(), express.end());
    vector<string> opers;
    for (auto i = s_oper.begin(); i != s_oper.end(); i++) {
        opers.push_back(*i);
    }
    do {
        express.assign(c_express.begin(), c_express.end());
        for (auto i = opers.begin(); i != opers.end(); i++) {
            calculate(*i);
        }
        long long num = stoi(express[0]) < 0 ? -1 * stoi(express[0]) : stoi(express[0]);
        if (num > best) {
            best = num;
        }
    } while (next_permutation(opers.begin(), opers.end()));
    answer = best;
    return answer;
}