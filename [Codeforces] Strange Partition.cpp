#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> numbers;

int main(void)
{
	int t, n, x;
	int max_sum;
	int min_sum;
	cin >> t;
	
	for(int tc=0;tc<t;++tc) {
		cin >> n >> x;
		numbers.clear();
		numbers.resize(n);
		max_sum = 0;
		min_sum = 0;
		
		for(int i=0;i<n;++i)
			cin >> numbers[i];
			
		for(int i=0;i<numbers.size();++i) {
			max_sum += ceil((double)numbers[i]/x);
			min_sum += numbers[i];	
		}
		min_sum = ceil((double)min_sum/x);
		
		cout << min_sum << ' ' << max_sum << endl;	
	}
	
	return 0;
}
