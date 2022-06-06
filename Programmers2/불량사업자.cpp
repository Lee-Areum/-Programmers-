#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;
set<string> s;
bool visited[8] = { false };
vector<string> user_id, banned_id;
bool check(string u_id, string cmp) {
	if (u_id.size() == cmp.size()) {
		for (int k = 0; k < cmp.size(); k++) {
			if (cmp[k] == '*') {
				continue;
			}
			else if (cmp[k] != u_id[k]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void dfs(int i, string str) {
	if (i == banned_id.size()) {
		sort(str.begin(), str.end());
		s.insert(str);
		return;
	}
	string b_id = banned_id[i];
	for (int k = 0; k < user_id.size(); k++) {
		if (check(user_id[k], b_id) && !visited[k]) {
			visited[k] = true;
			dfs(i + 1, str + to_string(k));
			visited[k] = false;
		}
	}
}

int solution(vector<string> u, vector<string> b) {
	user_id.assign(u.begin(), u.end());
	banned_id.assign(b.begin(), b.end());
	dfs(0, "");
	return s.size();
}