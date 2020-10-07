#include <iostream>
#include <vector> 

using namespace std;

int N;
int max_answer=-1000000001;
int min_answer=1000000001;
vector<int> numbers;
vector<int> signs;

int get_result(void) {
	int result=numbers[0];
	for(int i=0;i<N-1;++i) {
		switch(signs[i]) {
			case 1:	// plus?
				result+=numbers[i+1];
				break;
			case 2: // subtract
				result-=numbers[i+1];
				break;
			case 3: // multiply
				result*=numbers[i+1];
				break;
			case 4: // division
				result/=numbers[i+1];
				break;
		}	
	}
	
	return result;
}

void DFS(int index, int p_cnt, int s_cnt, int m_cnt, int d_cnt) {
	if(index==N-1) {
		int result = get_result();
		if(result>max_answer) max_answer = result;
		if(result<min_answer) min_answer = result;
		return;	
	}
	
	if(p_cnt!=0) {
		signs.push_back(1);
		DFS(index+1,p_cnt-1,s_cnt,m_cnt,d_cnt);
		signs.pop_back();
	}
	if(s_cnt!=0) {
		signs.push_back(2);
		DFS(index+1,p_cnt,s_cnt-1,m_cnt,d_cnt);
		signs.pop_back();
	}
	if(m_cnt!=0) {
		signs.push_back(3);
		DFS(index+1,p_cnt,s_cnt,m_cnt-1,d_cnt);
		signs.pop_back();
	}
	if(d_cnt!=0) {
		signs.push_back(4);
		DFS(index+1,p_cnt,s_cnt,m_cnt,d_cnt-1);
		signs.pop_back();
	}
}

int main(void)
{
	cin >> N;
	int temp;
	int p_cnt,s_cnt,m_cnt,d_cnt;
	for(int i=0;i<N;++i) {
		cin >> temp;
		numbers.push_back(temp);
	}
	
	cin >> p_cnt >> s_cnt >> m_cnt >> d_cnt;
	
	DFS(0,p_cnt,s_cnt,m_cnt,d_cnt);
	
	cout << max_answer << endl << min_answer << endl;
	return 0;
}
