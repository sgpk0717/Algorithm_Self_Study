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
	printf("====================dp����=====================\n");
	printf("n: %d, diff: %d\n", n, diff); 
	if(diff > 250000) {
		printf("diff�� 250000���� ũ�Ƿ� -999999����!\n"); 
		return -999999;
	}
	
	if(N == n) {
		printf("n == N��.\n"); 
		if(diff == 0) {
			printf("diff�� 0��. 0�� ����.\n"); 
			return 0;
		}	
		else {
			printf("diff�� 0�̾ƴ�. -999999�� ����.\n"); 
			return -999999;
		}
	}
	printf("result[%d][%d]��: %d\n",n,diff,result[n][diff]); 
	if(result[n][diff] != -1) {
		printf("result[%d][%d]�� -1�� �ƴϹǷ� �״�� %d�� ����.\n",n,diff,result[n][diff]); 
		return result[n][diff];
	}
	
	result[n][diff] = dynamic_programming(n+1, diff);
	printf("ù��° ȣ������ result[%d][%d]��: %d\n",n,diff,result[n][diff]); 
	
	result[n][diff] = max(result[n][diff], dynamic_programming(n+1, diff+heights[n]));
	printf("�ι�° ȣ������ result[%d][%d]��: %d\n",n,diff,result[n][diff]); 
	
	if(heights[n] > diff) {
		printf("heights[%d]�� %d���� ŭ.(%d > %d)\n",n,diff,heights[n],diff); 
		result[n][diff] = max(result[n][diff], diff+dynamic_programming(n+1, heights[n]-diff));
		printf("result[%d][%d]= %d �� ��.\n",n,diff,result[n][diff]); 
	} else {
		printf("%d�� heights[%d]���� ũ�ų� ����.(%d >= %d)\n",diff,n,diff,heights[n]); 
		result[n][diff] = max(result[n][diff], heights[n]+dynamic_programming(n+1, diff-heights[n]));
		printf("result[%d][%d]= %d �� ��.\n",n,diff,result[n][diff]);
	}
	
	printf("�׷��� �ᱹ result[%d][%d]= %d �� ����.\n", n,diff,result[n][diff]);
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
