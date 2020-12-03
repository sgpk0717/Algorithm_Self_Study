#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, K;
	int temp;
	int Answer=0;
	cin >> N >> K;
	
	vector<int> scores;
	
	for(int i=0;i<N;++i) {
		cin >> temp;
		scores.push_back(temp);
	}
	
	int k_num = scores[K-1];
	
	for(int i=0;i<N;++i) {
		if(!(scores[i]>=k_num && scores[i]>=1)) break;
		Answer++;			
	}
	
	cout << Answer << endl;
			
	return 0;
}
