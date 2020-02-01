#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;
ll Answer;
ll N;
vector<ll> heights;

void print_heights(void) {
	for(int i=0;i<heights.size();++i)
		cout << heights[i] << ' ';
	cout << endl;
}

void print_stack(stack<ll> st) {
	stack<ll> temp = st;
	
	cout << "--------���� ���û�Ȳ--------" << endl; 
	while(!temp.empty()) {
		printf("<%d>:%d\n", temp.top(), heights[temp.top()]);
		temp.pop();	
	}
	cout << "-----------------------------" << endl;
}

void processing(void) {
	stack<ll> st;
	ll top, area;
	for(ll i=0;i<N;++i) {
//		cout << endl << "--------------------------------------- for�� ����---------------------------------------" << endl; 
		if(st.empty()) {	// ������ ������� 
//			cout << "\"0\"" << endl;
//			printf("������ �� %d�� �������\n", i); 
			st.push(i);
//			print_stack(st);
			continue;
		}
		top = st.top();
		if(heights[top] < heights[i]) {		// ž���ִ°ź��� ���ε����°� ũ�� 
//			cout << "\"1\"" << endl;
//			printf("top(%d:%d)�� i��°(%d:%d)���� �۱⶧���� %d�� Ǫ��.\n", top,heights[top],i,heights[i],i);
			st.push(i);
//			print_stack(st);
			continue;
		}
		if(heights[top] == heights[i]) {	// ������ �׳� continue 
//			cout << "\"2\"" << endl;
//			printf("top(%d:%d)�� i��°(%d:%d)�� ���� ������ �׳� �н�.\n", top,heights[top],i,heights[i]);
			continue;
		} 
//		cout << "\"3\"" << endl;
//		cout << "========================while�� ����===========================" << endl; 
	 	while(!st.empty()) {
	 		top = st.top();
	 		if(heights[top]<=heights[i]) {
//				printf("top(%d:%d)�� i��°(%d:%d)���� �۰ų� �����Ƿ�  �׳� �н�.\n", top,heights[top],i,heights[i]);
				break;
			}
			
			st.pop();
			ll width;
			if(!st.empty()) {
				width = i-st.top()-1;
			}
			else { 
				width = i; 
			}	
//			printf("top: %d, height: %d, width: %d\n",top,heights[top],width);
	 		area = (long long)width * (long long)heights[top];
	 		if(area > Answer) {
//				printf("area(%d) �� Answer(%d)���� Ŀ�� ���� �ٲ�. %d ==> %d\n",area,Answer,Answer,area); 
				Answer = area;
			}
//			printf("%d�� stack���� �̾Ƴ�.\n", top); 
//	 		print_stack(st);
	 	}
//	 	cout << "==========================while ��=============================" << endl; 
// 		cout << "���� ����." << endl;
 		st.push(i);
// 		print_stack(st);

	}
	
	
	while(!st.empty()) {
//		cout << "�� �Ⱥ�����." << endl;
//		print_stack(st);
		ll top_index = st.top();
		ll height = heights[top_index];
		
		st.pop();
		ll width;
		if(!st.empty()) {
			width = N-st.top()-1;
		}
		else { 
			width = N; 
		}	
//		printf("top_index: %d, height: %d, width: %d\n",top_index,height,width);
		ll area = (long long)height * (long long)width;
//		printf("area: %d\n",area);
		if(area>Answer) {
//			printf("Answer: %d ==> %d\n", Answer, area);
			Answer = area;
		}
	}
}

int main(void)
{
	ifstream ifs("6549_3.txt");
	
	while(ifs >> N) {
//		cout << "N: " << N << endl; 
		if(N == 0) break;
		Answer=0;
		heights.clear();
		heights.resize(N);
		
		for(ll i=0;i<N;++i) {
			ifs >> heights[i];
//			cout << heights[i] << ' ';	
		}
//		cout << endl;
		
		processing();
			
		cout << Answer << endl;
	}

	return 0;	
}
