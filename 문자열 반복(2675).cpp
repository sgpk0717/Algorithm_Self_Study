#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int testCase, repeat;
	string input;
	
	cin >> testCase;
	
	
	for(int i=0;i<testCase;++i) {
		cin >> repeat >> input;	
		for(int j=0;j<input.size();++j) {
			for(int k=0;k<repeat;++k) {	
				cout << input[j];				
			}
		}
		cout << endl;	
	}
	
	return 0;
}
