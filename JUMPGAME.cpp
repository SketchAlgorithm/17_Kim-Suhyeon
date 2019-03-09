#include<iostream>
#include<vector>
#include<string>
#include<cstring> //for memset()

using namespace std;

int board[100][100];
int n;
int cache[100][100];

bool jump(int x, int y) {
	//범위 초과
	if (x >= n || y >= n) return 0;
	if (x == n - 1 && y == n - 1) return 1;
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	
	int jumpSize = board[y][x];
	return ret = jump(x + jumpSize, y) || jump(x, y + jumpSize);
}

int main() {
	int c;
	cin >> c;
	vector<string> answer;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		memset(cache, -1, sizeof(cache));
		if (jump(0, 0))
			answer.push_back("YES");
		else
			answer.push_back("NO");
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	return 0;
}
