#include <iostream>

using namespace std;

int main(void)
{
	int M, N;
	cin >> M >> N;
	
	int Answer=0;
	Answer+=(M/2)*N;
	
	if(M%2!=0) {
		Answer+=(N/2);	
	}
	
	cout << Answer << endl;
	
	return 0;
}
