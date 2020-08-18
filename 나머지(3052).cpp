#include <iostream>
#include <vector>

using namespace std;

vector<int> remains;

int main(void)
{
	int temp;
	int remain; 
	
	while(cin >> temp) {
		remain = temp%42;
		
		int i;
		for(i=0;i<remains.size();++i) {
			if(remains[i]==remain)
				break;
		}
		if(i==remains.size()) {
			remains.push_back(remain);	
		}
	}
	
	cout << remains.size() << endl;
	
	return 0;
}
