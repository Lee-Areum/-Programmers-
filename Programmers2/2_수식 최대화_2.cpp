#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
long long best = 0;
vector<char> c_operation; //수식
vector<long long> c_express; //복제품
long long calculate(char op, long long n1, long long n2) {
    long long num = n1;
    switch (op) {
    case '+':
        num += n2;
        break;
    case '-':
        num -= n2;
        break;
    case'*':
        num *= n2;
        break;
    default:
        break;
    }
    return num;
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> express; //숫자
    vector<char> operation; //수식
    set<char> s_oper;
    vector<char> opers;
    string tmp = "";
    for (int i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i]) != 0) {
            tmp += expression[i];
        }
        else {
            express.push_back(stoi(tmp));
            operation.push_back(expression[i]);
            s_oper.insert(expression[i]);
            tmp = "";
        }
    }
    express.push_back(stoi(tmp));
    c_express.assign(express.begin(), express.end());
    c_operation.assign(operation.begin(), operation.end());

    for (auto i = s_oper.begin(); i != s_oper.end(); i++) {
        opers.push_back(*i);
    }
    do {
        express.assign(c_express.begin(), c_express.end());
        operation.assign(c_operation.begin(), c_operation.end());
        for (auto it = opers.begin(); it != opers.end(); it++) {
            for (int i = 0; i < operation.size(); i++) {
                if (operation[i] == (*it)) {
                    long long num = calculate(*it, express[i], express[i + 1]);
                    express[i + 1] = num;
                    express.erase(express.begin() + i);
                    operation.erase(operation.begin() + i);
                    i--;
                }
            }
        }
        long long num = express[0] < 0 ? -1 * express[0] : express[0];
        if (num > best) {
            best = num;
        }
    } while (next_permutation(opers.begin(), opers.end()));
    answer = best;
    return answer;
}