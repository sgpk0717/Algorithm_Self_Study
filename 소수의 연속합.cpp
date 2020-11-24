#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> primes;

bool get_primes(int n) {
	for(int x=0;x<primes.size();++x) {
		if(primes[x] > sqrt(n)+1) return true;
		if(n%primes[x]==0) return false;
	}
	return true;
}

int main(void)
{
	int N, answer=0;
	cin >> N;
	
	for(int i=2;i<=N;++i)
		if(get_primes(i))
			primes.push_back(i);
			
//	for(int i=0;i<primes.size();++i)
//		cout << primes[i] << ' ';
//	cout << endl;

	int left=0, right=0, sum=0;
	while(right!=primes.size()) {
		sum += primes[right];
		
		if(sum == N) {
			answer += 1;
		}
		else if(sum > N) {
			while (sum >= N && left <= right) {
				sum -= primes[left];	
				if(sum == N) answer += 1;
				left += 1;
			}
		}
		right += 1;
	}
	
	cout << answer << endl;
	return 0;
}
