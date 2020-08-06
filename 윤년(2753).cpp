#include <iostream>

using namespace std;

int main(void)
{
	int year;
	
	cin >> year;

	if(year%400!=0) {
		if(year%100!=0) {
			if(year%4==0) {
				cout << 1 << endl;	
			}
			else {
				cout << 0 << endl;
			}
			
		}
		else {
			cout << 0 << endl;
		}
	}
	else {
		cout << 1 << endl;	
	}
	

	

	return 0;
}
