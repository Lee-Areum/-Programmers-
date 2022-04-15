#include <string>
#include <set>
#include <unordered_map>
#include <cmath>
#include <iostream>
using namespace std;

typedef struct Load {
	pair<int, int> start;
	pair<int, int> end;

	bool operator < (const Load& other)const {
		if (start == other.start) {
			return end < other.end;
		}
		return start < other.start;
	}
}Load;

int solution(string dirs) {
	int answer = 0;
	set<Load> visited;
	unordered_map<char, pair<int, int>> m = { {'U',{1,0}},{'D',{-1,0}},{'R',{0,1}},{'L',{0,-1}} };
	pair<int, int> now = { 0,0 };
	for (char s : dirs) {
		cout << s << " | ";
		int h, w;
		h = now.first + m.find(s)->second.first;
		w = now.second + m.find(s)->second.second;
		if (abs(h) < 6 && abs(w) < 6) {
			cout << " in {" << h << "," << w << "}";
			cout << min(now, { h,w }).first << ", " << min(now, { h,w }).second;
			cout << " | " << max(now, { h,w }).first << ", " << max(now, { h,w }).second << endl;

			if (visited.find({ now,{h,w} }) == visited.end() && visited.find({ {h,w}, now }) == visited.end()) {
				cout << " no find : ";
				answer++;
				visited.insert({ now,{h,w} });
				visited.insert({ {h,w}, now });
			}
			now = { h,w };
		}
	}

	return answer;
}