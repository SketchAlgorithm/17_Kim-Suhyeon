#include<iostream>
#include<string>

using namespace std;

string isEquivalent(string str) {
	//길이가 홀수면 그대로 출력
	if (str.size() % 2 != 0)
		return str;

	string str1 = isEquivalent(str.substr(0, str.size() / 2 ));
	string str2 = isEquivalent(str.substr(str.size() / 2, str.size() / 2 ));

	if (str1 <= str2)
		return str1 + str2;
	else
		return str2 + str1;

}

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	if (isEquivalent(str1) == isEquivalent(str2))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	return 0;
}
