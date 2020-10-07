#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int Answer=0;
		
	for(int i=0;i<N;++i) {
		int a[3]={0,};
		
		for(int i=0;i<3;++i)
			cin >> a[i];
		
		int cnt=0;
		for(int i=0;i<3;++i)
			if(a[i]==1)
				cnt++;
				
		if(cnt>=2) 
			Answer++;
	}
	
	cout << Answer << endl;
			
	return 0;
}
