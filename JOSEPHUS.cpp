#include<iostream>
#include<vector>

using namespace std;

vector<bool> is_dead;
int N, K;
int deadNum;
bool flag;
vector<int> answer;
int answer_n = 0;

void startDead(int next) {
	//살아남은 사람이 두명이면 종료
	if (deadNum == N - 2) {
		int n=0;
		for (int i = 0; i < N; i++) {
			if (!is_dead[i]) {
				answer[answer_n++] = i + 1;
				n++;
			}
			if (n == 2) {
				flag = true;
				return;
			}
		}
	}

	//한칸씩 나아가면서 죽었는지 확인
	//안죽었으면 kNum++
	//kNum이 K에 해당되는 순간 죽지 않았으면 죽이기
	//배열 마지막까지 확인 했다면 다시 처음 배열로
	int kNum=0;
	for (int i = next; i < N; i++) {
		if (!is_dead[i]) {
			kNum++;
			if (kNum == K) {
				is_dead[i] = true;
				deadNum++;
				startDead(i);
				if (flag)
					return;
			}
		}
		// 배열 마지막까지 확인 했는데 안죽었으면
		if (i == N-1 && kNum != K) {
			for (int n = 0; n < N; n++) {
				if (!is_dead[n]) {
					i = n-1;
					break;
				}
			}
		}
	}
}

//"남아있는 사람들 중" "다음 죽을 타자 고르기" "두 명이 남으면 종료"
int main() {
	int test;
	cin >> test;
	answer = vector<int>(test * 2);

	while (test--) {
		//사람 수, 자살할 순서 입력
		deadNum = 1;
		flag = false;
		cin >> N >> K;
		is_dead = vector<bool>(N, false); //죽었는지 살았는지 배열
		is_dead[0] = true;

		startDead(0);

	}
	
	for (int i = 0; i < answer.size(); i += 2) {
		cout << answer[i] << " " << answer[i + 1] << endl;
	}
	
	return 0;
}
