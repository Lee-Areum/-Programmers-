#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> make_list(string str) {
    vector<string> list; 
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] -= 32;
    }
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i + 1] >= 'a' && str[i + 1] <= 'z') {
            str[i + 1] -= 32;
        }
        if (isalpha(str[i]) != 0 && isalpha(str[i + 1]) != 0) {
            list.push_back(str.substr(i,2));
        }
    }
    return list;
}

int solution(string str1, string str2) {
    int answer = 0;
    int f, s, count;
    f = s = count = 0;
    vector<string> str_first = make_list(str1);
    vector<string> str_second = make_list(str2);
    int mother = 0;
    sort(str_first.begin(), str_first.end());
    sort(str_second.begin(), str_second.end());

    while (f < str_first.size() && s < str_second.size()) {
        if (str_first[f].compare(str_second[s]) == 0) {
            mother++;
            count++;
            f++;
            s++;
        }
        else if (str_first[f].compare(str_second[s]) > 0) {
            mother++;
            s++;
        }
        else {
            mother++;
            f++;
        }
    }
    while (f < str_first.size()) {
        mother++;
        f++;
    }
    while (s < str_second.size()) {
        mother++;
        s++;
    }
    if (mother == 0 && count == 0) return 65536;
    return (count/(float)mother)*65536;
}