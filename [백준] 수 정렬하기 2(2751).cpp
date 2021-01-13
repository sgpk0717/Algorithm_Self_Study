#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool numbers[2000001];

int main(void)
{
	int tmp;
	cin >> N;
	
	for(int i=0;i<N;++i) {
		cin >> tmp;
		numbers[tmp+1000000] = true;
	}
	
	for(int i=0;i<2000001;++i) {
		if(numbers[i]==true)
			cout << i-1000000 << '\n';
	}
	
	
	return 0;
}
