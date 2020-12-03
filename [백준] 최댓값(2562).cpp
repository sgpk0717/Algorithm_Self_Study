#include <iostream>

using namespace std;

int main(void)
{
	int N;
	int max=0, m_index=-1;
	for(int i=0;i<9;++i) {
		cin >> N;
		if(max < N) {
			max = N;	
			m_index = i+1;
		}
	}

	cout << max << endl;
	cout << m_index << endl;

	return 0;
}
