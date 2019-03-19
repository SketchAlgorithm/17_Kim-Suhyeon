#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cache[50][50];
vector<int> number;
vector<int> answer;

int gameStart(int left, int right) {
	//숫자 없음
	if (left > right) return 0;

	int &ret = cache[left][right];
	if (ret != -100000) return ret;

	//일단 가져온다
	ret = max(number[left] - gameStart(left + 1, right), number[right] - gameStart(left, right - 1));

	//지운다
	if (right - left > 0) {
		//왼쪽 지우는 경우
		ret = max(ret, -gameStart(left + 2, right));
		//오른쪽 지우는 경우
		ret = max(ret, -gameStart(left, right - 2));
	}
	return ret;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		for (int i = 0; i < 50; i++) 
			for (int j = 0; j < 50; j++)
				cache[i][j] = -100000;
		number.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			number.push_back(num);
		}
		answer.push_back(gameStart(0, n-1));
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;

	return 0;
}
