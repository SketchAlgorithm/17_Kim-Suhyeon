//시간초과 뜸...8ㅅ8
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int size;
	cin >> size;
	vector<int> seq(size);
	// 수열 입력
	for (int i = 0; i < size; i++) {
		cin >> seq[i];
	}

	// 수열 내 비교 후 지울 수열 지우기
	for (int i = 0; i < seq.size()-1; i++) {
		if (seq[i] >= seq[i + 1]) {
			seq.erase(seq.begin() + (i + 1));
			i--;
		}
	}

	cout << seq.size() << endl;
	for (int i = 0; i < seq.size(); i++)
		cout << seq[i] << " ";

	return 0;
}
