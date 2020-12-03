#include <iostream>
#include <string>

using namespace std;

int alpha2int(char c) {
	int num = c - 'A';
	if(num <= 2) {
		return 2;
	}
	else if(num <= 5) {
		return 3;
	}
	else if(num <= 8) {
		return 4;
	}
	else if(num <= 11) {
		return 5;
	}
	else if(num <= 14) {
		return 6;
	}
	else if(num <= 18) {
		return 7;
	}
	else if(num <= 21) {
		return 8;
	}
	else if(num <= 25) {
		return 9;
	}
}

int main(void)
{
	string input;
	int sum=0;
	 
	cin >> input;
	
	for(int i=0;i<input.size();++i)
		sum += alpha2int(input[i]);
	
	cout << sum+input.size() << endl;
	
	return 0;
}
