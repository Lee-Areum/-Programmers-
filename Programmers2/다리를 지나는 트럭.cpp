#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int nowWeight = 0;
	queue<int> bridge;
	int index = 0;
	int now = 0;
	while(now<truck_weights.size()){
		int n = truck_weights[now];
		if (nowWeight + n <= weight) {
			cout << "if" << endl;
			bridge.push(n);
			nowWeight += n;
			now++;
		}
		else {
			cout << "else" << endl;
			for (int i = 0; i < bridge_length - 1; i++) {
				bridge.push(0);
			}
			nowWeight -= truck_weights[index++];
		}
	}
	for (int i = 0; i < bridge_length; i++) {
		bridge.push(0);
	}
	while (!bridge.empty()) {
		cout << bridge.front() << " ";
		answer++;
		bridge.pop();
	}
	return answer;
}


//https://programmers.co.kr/learn/courses/30/lessons/42583