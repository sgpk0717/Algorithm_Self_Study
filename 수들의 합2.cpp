#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> numbers;

int main(void)
{
	cin >> N >> M;
	numbers.resize(N);
	for(int i=0;i<N;++i)
		cin >> numbers[i];
	
	int Answer=0;
	int left_pointer = 0;
	int right_pointer = 0;
	int sum=0;
	
	while(right_pointer<N) {
		sum += numbers[right_pointer];
		if(sum == M) 
			++Answer;
		
		while(sum >= M && left_pointer<right_pointer) {
			sum -= numbers[left_pointer];
			++left_pointer;
			if(sum == M) 
				++Answer;
			
		}
		++right_pointer;
	}
	
	cout << Answer << endl;
	return 0;
}
