#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> wine;
vector<int> cache;

int getTotal(int n) {
	if (n == 0) return 0;
	if (n == 1) return cache[1] = wine[1]; //와인 한잔인 경우
	if (n == 2) return cache[2] = wine[1] + wine[2]; //와인 두잔인 경우
	if (cache[n] != 0) return cache[n];

	return cache[n] = max(getTotal(n-1), max(wine[n] + getTotal(n - 2), wine[n] + wine[n - 1] + getTotal(n - 3)));
}

int main() {
	cin >> n;
	wine = vector<int>(n + 1, 0);
	cache = vector<int>(n + 1, 0);
	for (int i = 1; i < n + 1; i++)
		cin >> wine[i];
	cout << getTotal(n) << endl;
	return 0;
}
