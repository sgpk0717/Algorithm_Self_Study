#include <iostream>

using namespace std;

int min_tries[1000001];
int N;
int main(void)
{
	cin >> N;
	
	for(int i=0;i<1000001;++i)
		min_tries[i]=10000;
	
	min_tries[0] = 0;
	min_tries[1] = 0;
	for(int i=2;i<N+1;++i) {
		min_tries[i] = min_tries[i-1]+1;
		if(i%2==0)
			min_tries[i]=min(min_tries[i],min_tries[i/2]+1);
		if(i%3==0)
			min_tries[i]=min(min_tries[i],min_tries[i/3]+1);
	}
	
	printf("%d\n",min_tries[N]);
	
	return 0;
}
