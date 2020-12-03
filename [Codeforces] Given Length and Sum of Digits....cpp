#include <iostream>
#include <vector>

using namespace std;
int Answer;
int m, s;
vector<int> number;

bool promising(int idx, int partial_sum) {
	
	if(partial_sum>s) return false;
	
	int remain_idx = m-1-idx;
	
	if(remain_idx*9 + partial_sum < s) return false;
	
	return true;
}

void print_number(void) {
	for(int i=0;i<number.size();++i) {	
		cout << number[i];
	}
	cout << endl;	
}

void DFS(int idx, int sum) {
	if(idx == m) {
		if(sum == s	) {
//			cout << "찾았다! : "; 
//			print_number();
			Answer++;
			return;	
		}
	}
	
	
	for(int i=0;i<10;++i) {
		number[idx] = i;
		if(promising(idx,sum+i)) {
//			printf("%d, %d는 유망함.\n",idx,sum+i);
//			cout << "idx: " << idx << ", sum: " << sum+i << ", num: ";
//			print_number(); 
			DFS(idx+1, sum+i);	
		}
	}
}

int main(void)
{
	cin >> m >> s;
	number.resize(m,-1);
	for(int i=1;i<=9;++i) {
		number[0] = i;
		DFS(1, i);		
	}
	
	cout << Answer << endl;
	
	return 0;
}
