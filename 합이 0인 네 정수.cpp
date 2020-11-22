#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> numbers(4);
vector<vector<long long>> added_numbers(2);

int N;

int main(void)
{
	long long Answer=0;
	int tmp;	
	int left, right;
	cin >> N;
	
	
	for(int i=0;i<4;++i) {
		numbers[i].resize(N);
	}
		
	for(int i=0;i<2;++i) {
		added_numbers[i].resize(N*N);
	}
	
	for(int i=0;i<N;++i)
		for(int j=0;j<4;++j)
			cin >> numbers[j][i];
	
	for(int j=0;j<N;++j) 
		for(int k=0;k<N;++k) 
			added_numbers[0][j*N+k] = numbers[0][j] + numbers[1][k];
	for(int j=0;j<N;++j) 
		for(int k=0;k<N;++k) 
			added_numbers[1][j*N+k] = numbers[2][j] + numbers[3][k];
	
	for(int i=0;i<2;++i)
		sort(added_numbers[i].begin(),added_numbers[i].end());

	long long sum, target_left, target_right, cnt_left, cnt_right;
	left=0, right=N*N-1;
	
	while(left<N*N && right>=0) {
		sum = added_numbers[0][left] + added_numbers[1][right];
		if(sum==0) {
			target_left = added_numbers[0][left];
			target_right = added_numbers[1][right];
			cnt_left=0, cnt_right=0;
			while(added_numbers[0][left]==target_left) {
				cnt_left++;
				left++;	
				if(left>=N*N) break;
			}
			
			while(added_numbers[1][right]==target_right) {
				cnt_right++;
				right--;
				if(right<0) break;
			}
			Answer+=cnt_left*cnt_right;
		}
		else if(sum<0) {
			left++;			
		}
		else {
			right--;	
		}
	}
	
	cout << Answer << endl;
	
	
	return 0;
}
