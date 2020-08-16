#include <iostream>

using namespace std;

int main(void)
{
	int score;
	int sum;
	
	while(cin >> score) {
		if(score < 40) score = 40;
		
		sum += score;		
	}
	
	cout << sum/5 << endl;
	
	return 0;
}
