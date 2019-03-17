#include<iostream>
#include<vector>

using namespace std;

int tPlace[1000001];

int main() {
	int B, C;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> tPlace[i];
	}
	cin >> B >> C;
	long long cnt = num;
	for (int i = 0; i < num; i++) {
		tPlace[i] -= B;
		if (tPlace[i] > 0) {
			if (tPlace[i] % C == 0)
				cnt += tPlace[i] / C;
			else
				cnt += tPlace[i] / C + 1;
		}
	}
	cout << cnt << endl;
	return 0;
}
