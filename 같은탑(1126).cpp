#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int N;
int Answer;
vector<int> heights;
vector< vector<int> > result;

int dynamic_programming(int n, int diff) {
	printf("====================dp시작=====================\n");
	printf("n: %d, diff: %d\n", n, diff); 
	if(diff > 250000) {
		printf("diff가 250000보다 크므로 -999999리턴!\n"); 
		return -999999;
	}
	
	if(N == n) {
		printf("n == N임.\n"); 
		if(diff == 0) {
			printf("diff가 0임. 0을 리턴.\n"); 
			return 0;
		}	
		else {
			printf("diff가 0이아님. -999999를 리턴.\n"); 
			return -999999;
		}
	}
	printf("result[%d][%d]값: %d\n",n,diff,result[n][diff]); 
	if(result[n][diff] != -1) {
		printf("result[%d][%d]가 -1이 아니므로 그대로 %d을 리턴.\n",n,diff,result[n][diff]); 
		return result[n][diff];
	}
	
	result[n][diff] = dynamic_programming(n+1, diff);
	printf("첫번째 호출이후 result[%d][%d]값: %d\n",n,diff,result[n][diff]); 
	
	result[n][diff] = max(result[n][diff], dynamic_programming(n+1, diff+heights[n]));
	printf("두번째 호출이후 result[%d][%d]값: %d\n",n,diff,result[n][diff]); 
	
	if(heights[n] > diff) {
		printf("heights[%d]가 %d보다 큼.(%d > %d)\n",n,diff,heights[n],diff); 
		result[n][diff] = max(result[n][diff], diff+dynamic_programming(n+1, heights[n]-diff));
		printf("result[%d][%d]= %d 가 됨.\n",n,diff,result[n][diff]); 
	} else {
		printf("%d가 heights[%d]보다 크거나 같음.(%d >= %d)\n",diff,n,diff,heights[n]); 
		result[n][diff] = max(result[n][diff], heights[n]+dynamic_programming(n+1, diff-heights[n]));
		printf("result[%d][%d]= %d 가 됨.\n",n,diff,result[n][diff]);
	}
	
	printf("그래서 결국 result[%d][%d]= %d 를 리턴.\n", n,diff,result[n][diff]);
	return result[n][diff];
}

int main(void)
{
	ifstream ifs("1126_2.txt");
	ifs >> N;
	heights.resize(N+1);
	result.resize(N+1, vector<int>(250001,-1));
	
	for(int i=0;i<N;++i) {
		ifs >> heights[i];
	}
	
	Answer = dynamic_programming(0,0);
	if(Answer <= 0)
		Answer=-1;
		
	cout << Answer << endl;
	
	return 0;
}
