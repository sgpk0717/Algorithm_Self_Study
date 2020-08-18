#include <iostream>

using namespace std;

int count[10];

int main(void)
{
	int A, B, C;
	int mul;
	
	cin >> A >> B >> C;
	mul = A*B*C;
	
	while(mul>0) {
		count[mul%10]+=1;
		mul/=10;
	}
	
	for(int i=0;i<10;++i) 
		cout << count[i] << endl;

	return 0;
}
