#include <iostream>
#include <vector>

using namespace std;

int N;
long long M;
vector<vector<long long>> haybales;

int find_max_spiciness_index(int s, int e) {
	if(s>e) return e;
	long long max_val=0, max_idx=-1;
	int i;
	for(i=s;i<=e;++i) {
		if(haybales[i][1]>max_val) {
			max_val = haybales[i][1];
			max_idx = i;	
		}
	}
	
	return max_idx;
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	haybales.resize(N,vector<long long>(2));
	
	for(int i=0;i<N;++i)
		for(int j=0;j<2;++j)
			cin >> haybales[i][j];
			
	int left=0,right=0;
	long long sum=0;
	long long min_spiciness=1000000001;
	int partial_maximum_spiciness_index=0;
	
	while(right!=N) {
		sum += haybales[right][0];		// sum에다가 새로운놈 추가 
		if(haybales[right][1] > haybales[partial_maximum_spiciness_index][1]) 	// 새로추가한놈이 기존꺼보다 크면 
			partial_maximum_spiciness_index = right;	// 맥스를 교체함
		if(sum >= M) {		// 조건 만족시 
			if(min_spiciness > haybales[partial_maximum_spiciness_index][1]) 
				min_spiciness = haybales[partial_maximum_spiciness_index][1];
			while(left <= right && sum >= M) {
				if(left == partial_maximum_spiciness_index) {
					partial_maximum_spiciness_index = find_max_spiciness_index(left+1,right);
					if(min_spiciness > haybales[partial_maximum_spiciness_index][1]) {
						min_spiciness = haybales[partial_maximum_spiciness_index][1];
					}
				}
				sum -= haybales[left][0];	
				left += 1;
			}
		}
		right+=1;
	}
	
	cout << min_spiciness << endl;
	return 0;
}
