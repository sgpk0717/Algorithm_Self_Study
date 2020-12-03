#include <iostream>

using namespace std;

int main(void)
{
	int x;
	int Answer=0;
	cin >> x;
	
	while(x>0) {
		if(x%2==0) {
			x/=2;
			continue;
		}
		x-=1;
		Answer++;
	}
	
	cout << Answer << endl;
	
	return 0;
}
