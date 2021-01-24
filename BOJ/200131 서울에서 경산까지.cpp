#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> maxMoney(101, vector<int>(100001, 0));
vector<int> walkTime(101, 0);
vector<int> walkMoney(101, 0);
vector<int> bikeTime(101, 0);
vector<int> bikeMoney(101, 0);
int N, K;

int main(void) {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> walkTime[i] >> walkMoney[i] >> bikeTime[i] >> bikeMoney[i];
	}
	maxMoney[1][walkTime[1]] = walkMoney[1];
	maxMoney[1][bikeTime[1]] = max(maxMoney[1][bikeTime[1]], bikeMoney[1]);
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (maxMoney[i - 1][j] == 0) continue;
			if (j + walkTime[i] <= K) {
				maxMoney[i][j + walkTime[i]] = max(maxMoney[i][j + walkTime[i]], maxMoney[i - 1][j] + walkMoney[i]);
			}
			if (j + bikeTime[i] <= K) {
				maxMoney[i][j + bikeTime[i]] = max(maxMoney[i][j + bikeTime[i]], maxMoney[i - 1][j] + bikeMoney[i]);
			}
		}
	}
	int answer = -1;
	for (int i = 0; i <= K; i++) {
		answer = max(answer, maxMoney[N][i]);
	}
	cout << answer;
	return 0;
}