#include <iostream>

using namespace std;

int main(void)
{
	int N;
	int min=1000001, max=-1000001;
	cin >> N;
	
	int temp;
	for(int i=0;i<N;++i) {
		cin >> temp;
		if(min > temp)
			min = temp;
		if(max < temp)
			max = temp;
	}
	
	cout << min << " " << max << endl;
	
	return 0;
}
