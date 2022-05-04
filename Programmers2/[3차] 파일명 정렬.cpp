#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string s1, string s2) {
    string tmp1, tmp2;
    int n1, n2, i, k;
    for (i = 0; i < s1.size() && !isdigit(s1[i]); i++) {
        tmp1.push_back(tolower(s1[i]));
    }
    for (k = 0; k < s2.size() && !isdigit(s2[k]); k++) {
        tmp2.push_back(tolower(s2[k]));
    }
    if (tmp1.compare(tmp2) != 0) {
        return tmp1 < tmp2;
    }
    int n = 0;
    tmp1.clear(); tmp2.clear();
    for (; i < s1.size() && isdigit(s1[i]); i++, n++) {
        if (n == 5) break;
        tmp1.push_back(s1[i]);
    }
    for (n = 0; k < s2.size() && isdigit(s2[k]); k++, n++) {
        if (n == 5) break;
        tmp2.push_back(s2[k]);
    }
    n1 = stoi(tmp1); n2 = stoi(tmp2);
    if (n1 != n2) {
        return n1 < n2;
    }
    else {
        return false;
    }
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compare);
    return files;
}