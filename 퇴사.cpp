#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int,int> > pays;
vector<int> days;
int N;
int Answer;

void DFS(int day, int pay_sum, int prev_pay) {
	if(day>N) {
		if(Answer<pay_sum) 
			Answer = pay_sum;
		return;
	}
	if(day+pays[day].first<=N+1) {
		days.push_back(day);
		DFS(day+pays[day].first, pay_sum+pays[day].second, pays[day].second);	
		days.pop_back();
	}
	DFS(day+1, pay_sum, 0);	
}

int main(void)
{
	cin >> N;
	pays.resize(N+1);
	for(int i=1;i<=N;++i) {
		cin >> pays[i].first;
		cin >> pays[i].second;
	}
	
	DFS(1,0,0);
	
	cout << Answer << endl;
	return 0;  
}
