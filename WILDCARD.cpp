#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int cache[101][101];
string W, S;

bool match(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1)
		return ret;

	while (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s])) {
		w++; s++;
	}

	if (w == W.size()) {
		return ret = (s == S.size());
	}

	if (W[w] == '*') {
		for (int skip = 0; skip + s <= S.size(); skip++) {
			if (match(w + 1, skip + s)) {
				return ret = 1;
			}
		}
	}
	return ret = 0;
}

int main() {
	int c;
	cin >> c;
	vector<string> answer;
	while (c--) {
		vector<string> temp;
		cin >> W;
		int fileNum;
		cin >> fileNum;
		for (int i = 0; i < fileNum; i++) {
			memset(cache, -1, sizeof(cache));
			cin >> S;
			if (match(0, 0))
				temp.push_back(S);
		}
		sort(temp.begin(), temp.end());
		for (int i = 0; i < temp.size(); i++)
			answer.push_back(temp[i]);
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	return 0;
}
