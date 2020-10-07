#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector< vector<int> > powers;
vector<int> team_A;
vector<int> team_B;
int N;
int Answer=99999999;

void DFS(int n, int cnt_a, int cnt_b) {
	if(cnt_a>(N/2) || cnt_b>(N/2)) return;
	if(n==N) {
//		cout << "=======================" << endl;
//		cout << "team_A: ";
//		for(int i=0;i<N/2;++i) {
//			cout << team_A[i] << ' ';	
//		}
//		cout << endl;
//		cout << "team_B: ";
//		for(int i=0;i<N/2;++i) {
//			cout << team_B[i] << ' ';	
//		}
//		cout << endl;
//		cout << "=======================" << endl;
		int sum_A=0;
		int sum_B=0;
		for(int i=0;i<N/2;++i) {
			for(int j=0;j<N/2;++j) {
				sum_A+=powers[team_A[i]][team_A[j]];
//				printf("powers[%d][%d] = %d\n",team_A[i],team_A[j],powers[team_A[i]][team_A[j]]);
			}
		}
		for(int i=0;i<N/2;++i) {
			for(int j=0;j<N/2;++j) {
				sum_B+=powers[team_B[i]][team_B[j]];
//				printf("powers[%d][%d] = %d\n",team_B[i],team_B[j],powers[team_B[i]][team_B[j]]);
			}
		}
				
//		cout << "sum_A: " << sum_A << ", sum_B: " << sum_B << endl;
		if(Answer > abs(sum_A-sum_B)) Answer = abs(sum_A-sum_B);
		return;
	}
	
	team_A.push_back(n);
	DFS(n+1,cnt_a+1,cnt_b);
	team_A.pop_back();
	
	team_B.push_back(n);
	DFS(n+1,cnt_a,cnt_b+1);
	team_B.pop_back();
}

int main(void)
{
	cin >> N;
	
	powers.resize(N,vector<int>(N));
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			cin >> powers[i][j];		
		}
	}
	
	DFS(0,0,0);
	
	cout << Answer << endl;
	
	return 0;
}
