#include <iostream>
#include <vector> 

using namespace std;

vector<pair<int,int>> fibos(41);

int main(void)
{
	int N, T;
	cin >> T;
	
	fibos[0] = make_pair(1,0);
	fibos[1] = make_pair(0,1);
	fibos[2] = make_pair(1,1);
	
	for(int i=3;i<42;++i) {
		fibos[i] = make_pair(fibos[i-1].first+fibos[i-2].first, fibos[i-1].second+fibos[i-2].second);	
	}
	
	cout << fibos[1].first << endl;
	for(int i=0;i<T;++i) {
		cin >> N;
		cout << fibos[N].first << ' ' << fibos[N].second << endl;
	}
	return 0;
}
