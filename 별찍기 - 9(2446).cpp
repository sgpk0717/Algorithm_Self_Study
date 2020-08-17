#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	for(int i=0;i<N;++i) {
		for(int j=0;j<i;++j)
			cout << " ";
		for(int j=2*N-1-2*i;j>0;j--)
			cout << "*";
		cout << endl;
	}
	for(int i=N-1;i>0;--i) {
		for(int j=1;j<i;++j)
			cout << " ";
		for(int j=2*N+1-2*i;j>0;j--)
			cout << "*";
		cout << endl;	
	}
	
	return 0;
}
