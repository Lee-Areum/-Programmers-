#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
vector<vector<int>> candiates;

bool check(vector<vector<string>> relation, vector<int> comb) {
	for (int i = 0; i < candiates.size(); i++) {
		int can, com;
		can = com = 0;
		while (can < candiates[i].size() && com < comb.size()) {
			if (candiates[i][can] == comb[com]) {
				can++; com++;
			}
			else {
				com++;
			}
		}
		if (can == candiates[i].size()) {
			return false;
		}
	}
	set<vector<string>> sets;

	for (int i = 0; i < relation.size(); i++) {
		int k = 0;

		vector<string> search;
		for (int k = 0; k < comb.size(); k++) {
			search.push_back(relation[i][comb[k]]);
		}
		auto index = sets.find(search);
		if (index != sets.end()) {
			while (k < comb.size() && relation[i][comb[k]] == (*index)[k]) {
				k++;
			}
			if (k >= comb.size()) {
				return false;
			}
		}
		vector<string> tmp;
		for (int k = 0; k < comb.size(); k++) {
			tmp.push_back(relation[i][comb[k]]);
		}
		sets.insert(tmp);
	}
	return true;
}

int solution(vector<vector<string>> relation) {
	int answer = 0;

	for (int r = 1; r <= relation[0].size(); r++) {
		vector<int> tmp;
		for (int i = 0; i < relation[0].size() - r; i++) {
			tmp.push_back(0);
		}
		for (int i = 0; i < r; i++) {
			tmp.push_back(1);
		}
		do {
			vector<int> comb;
			for (int i = 0; i < tmp.size(); i++) {
				if (tmp[i] == 1) {
					comb.push_back(i);
				}
			}
			if (check(relation, comb)) {
				candiates.push_back(comb);
				answer++;
			}
		} while (next_permutation(tmp.begin(), tmp.end()));
	}
	return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/42890