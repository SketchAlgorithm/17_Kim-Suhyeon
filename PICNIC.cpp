#include<iostream>
#include<string.h>

using namespace std;

bool* is_couple;
bool** are_friends;
int f_num, c_num;
int noc = 0; //경우의 수(정답)

//'남은 사람들 중',  '짝 고르기!!' -> 반복(재귀)
void letsGo() {
	//짝 고를 사람 누구?
	int who = -1;

	for (int i = 0; i < f_num; i++) {
		if (!is_couple[i]) {
			who = i;
			break;
		}
	}

	//다 파트너 있음? -> 종료
	if (who == -1) {
		noc++;
		return;
	}

	//파트너랑 나랑 친구임?
	//친구이면 나랑 짝
	//친구 아니면 다음 사람이랑 비교하게
	for (int p_num = who + 1; p_num < f_num; p_num++) {
		if (!is_couple[p_num] && are_friends[who][p_num]) {
			is_couple[who] = is_couple[p_num] = true;
			letsGo();
			is_couple[who] = is_couple[p_num] = false;
		}
	}
}

int main() {
	cout << "테스트 상수 입력 : ";
	int test;
	cin >> test;

	while (test--) {

		cout << "사람 수, 친구 쌍의 수 : ";
		cin >> f_num >> c_num;

		//짝인지, 친구 쌍인지 아닌지 판별 배열
		is_couple = new bool[f_num];
		are_friends = new bool*[f_num];

		memset(is_couple, 0, f_num);
		
		for (int i = 0; i < f_num; i++) {
			are_friends[i] = new bool[f_num];
			memset(are_friends[i], 0, f_num);	//0으로 초기화
		}

		//친구 쌍 입력
		cout << "친구 쌍 입력 : ";
		for (int k = 0; k < c_num; k++) {
			int f_1, f_2;
			//친구인 애들 입력 (f_1, f_2)
			cin >> f_1 >> f_2;
			are_friends[f_1][f_2] = true;
			are_friends[f_2][f_1] = true;
		}

		letsGo();

		cout << "경우의 수 : " << noc << endl << endl;

		//동적할당 해제
		noc = 0;
		delete[] is_couple;
		for (int i = 0; i < f_num; i++) {
			delete[] are_friends[i];
		}
		delete[] are_friends;
	}
	return 0;
}
