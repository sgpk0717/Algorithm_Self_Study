#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, c0, c1, h;
	int testcase, coin_sum;
	string str;
	cin >> testcase;
	while(testcase-->0) {
		cin >> n >> c0 >> c1 >> h;
		cin >> str;
		coin_sum=0;
		
		if (c0 > c1) {
			if (c1 + h < c0) c0 = c1 + h;
		}
		else if (c0 < c1) {
			if (c0 + h < c1) c1 = c0 + h;
		}
			
		for(int i=0;i<str.size();++i)
			if (str[i] == '0')
				coin_sum += c0;
			else 
				coin_sum += c1;
		
		cout << coin_sum << endl;
	}
	
	
	return 0;
}
