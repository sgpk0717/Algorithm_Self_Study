#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
ll Answer;
vector<ll> heights;

void print_heights(void) {
	for(ll i=0;i<heights.size();++i)
		cout << heights[i] << ' ';
	cout << endl;
}

int find_min_index(ll start, ll end) {
	ll min_index = start;
	ll min_value = heights[start];
	
	for(ll i=start+1;i<=end;++i)
		if(heights[i] < min_value) {
			min_index = i;
			min_value = heights[i];
		}
			
	return min_index;	
}

void init_tree(ll start, ll end) {
//	cout << "============================" << endl;
//	printf("start: %d, end: %d\n", start, end);
	ll mindex, area;
	/* ��ĭ¥�� ������ */ 
	if(start==end) {
//		printf("start��end�� ����.\n"); 
		mindex = start;
		area = heights[mindex];
//		printf("mindex: %d\n",mindex);
//		printf("area: %d\n", area);
		if(area>Answer) Answer = area;
		return;								// ���̻� ���ɰ��� �״�� ����  
	}
	
//	printf("start��end�� �ٸ�.\n");
	mindex = find_min_index(start,end);	// �־��� ���������� �ּ��� �ε����� ã��. 
//	printf("mindex: %d\n",mindex);
	area = (end-start+1)*heights[mindex];
//	printf("area: %d\n", area);
	if(area>Answer) Answer = area;
	
	if(mindex != start) {	// �ּ� �ε����� ������ ���� ������ �ƴϸ� 
		init_tree(start, mindex-1);	// ����  
	}
	
	if(mindex != end) {	// �ּ� �ε����� ������ ���� �������� �ƴϸ�  
		init_tree(mindex+1,end); // ����  
	}

}

int main(void)
{
	int N;
	int height;
//	ifstream ifs("6549_3.txt");
	
	while(scanf("%lld",&N)) {
		//cout << "N: " << N << endl; 
		if(N == 0) break;
		Answer=0;
		heights.clear();
		heights.resize(N);
		
		for(int i=0;i<N;++i) {
			scanf("%lld",&heights[i]);
		}	
//		cout << "=====================================" << endl;
//		print_heights();
//		cout << "=====================================" << endl;
		init_tree(0, N-1);
		
		printf("%lld\n", Answer);
	}

	return 0;	
}
