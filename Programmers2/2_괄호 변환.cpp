#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool check_complete(string str) {
    stack<char> st;
    for (char c : str) {
        if (c == '(') {
            st.push('(');
        }
        else {
            if (st.empty()) return false;
            else st.pop();
        }
    }
    if (!st.empty()) return false;
    return true;
}

string roof(string str) {
    string u, v;
    int index, open;
    if (str.empty()) return str; //1
    for (index = 0, open = 0; index < str.length(); index++) { //2
        if (str[index] == '(') {
            open++;
        }
        else {
            open--;
        }
        if (index != 0 && open == 0) {
            u = str.substr(0, index + 1);
            v = str.substr(index + 1);
            break;
        }
    }
    if (check_complete(u)) { //3
        return u + roof(v);
    }
    else { //4
        string tmp = "(" + roof(v) + ")";
        string rev = u.substr(1, u.length() - 2);
        for (int i = 0; i < rev.size(); i++) {
            rev[i] = (rev[i] == '(') ? ')' : '(';
        }
        return tmp + rev;
    }
}

string solution(string p) {
    if (check_complete(p)) return p;
    return roof(p);
}