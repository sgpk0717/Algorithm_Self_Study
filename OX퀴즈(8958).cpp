#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int N;
	string results;
	char result, prev_result='-';
	int score, prev_score=0;
	int sum_score;
	
	cin >> N;
	
	while(N>0) {
		result, prev_result = '-';
		sum_score = 0;
		prev_score=0;
		
		cin >> results;
		for(int i=0;i<results.size();++i) {
			result = results[i];
			
			if(result=='O') {
				score = prev_score+1;
				sum_score += score;
				
				prev_result = result;
				prev_score = score;
			}
			else {
				score = 0;
				prev_result = result;
				prev_score = score;
			}
		}
		cout << sum_score << endl;
		--N;
	}
	
	return 0;
}
