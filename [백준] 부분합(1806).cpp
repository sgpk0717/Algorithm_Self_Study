#include <iostream>
#include <vector> 

using namespace std;

int N, S;
vector<int> numbers;

int main(void)
{
	int min_len = 1000001;
	
	cin >> N >> S;
	numbers.resize(N);
	for(int i=0;i<N;++i)
		cin >> numbers[i];
	
	int left = 0;
	int right = 0;
	int sum = 0;
	
	while(right < N) {
		sum += numbers[right];
		
		while(sum >= S && left <= right) {
			int len = right-left+1;
			if(len < min_len) min_len = len;
			sum -= numbers[left++];	
		}
		right++;
	}
	
	if(min_len==1000001) cout << 0 << endl;
	else cout << min_len << endl;
	
	return 0;
}
