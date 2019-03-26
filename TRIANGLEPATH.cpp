#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<vector<int>> triangle;
vector<vector<int>> cache;
vector<int> answer;

int getSum(int col, int row) {
	if (col > n-1) return 0;
	int& ret = cache[col][row];
	if (ret != -1) return ret;
	if (col == n-1) return ret = triangle[col][row];
	return ret = triangle[col][row] + max(getSum(col + 1, row), getSum(col + 1, row + 1));
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		triangle = vector<vector<int>>(n, vector<int>(n, -1));
		cache = vector<vector<int>>(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> triangle[i][j];
			}
		}
		answer.push_back(getSum(0,0));
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	return 0;
}
