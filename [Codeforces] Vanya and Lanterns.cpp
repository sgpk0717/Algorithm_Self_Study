#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(void)
{
	int n, l;
	cin >> n >> l;
	
	vector<int> lanterns;
	int temp;
	for(int i=0;i<n;++i) {
		cin >> temp;
		lanterns.push_back(temp);
	}
	sort(lanterns.begin(), lanterns.end());
	lanterns.erase(unique(lanterns.begin(), lanterns.end()),lanterns.end());

//	for(int i=0;i<lanterns.size();++i) 
//		cout << lanterns[i] << ' ';
//	cout << endl;
	double answer = lanterns[0]-0;
	
	for(int i=0;i<lanterns.size()-1;++i) {
		double radius = (lanterns[i+1]-lanterns[i])/2.0;
		
		if(radius > answer) {
			answer = radius;
		}
	}
	answer = l-lanterns[lanterns.size()-1] > answer ? l-lanterns[lanterns.size()-1] : answer;
	cout << fixed << setprecision(10) << answer << '\n';
	return 0;
}
