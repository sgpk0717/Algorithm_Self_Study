#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> numbers;
vector<int> counts;
vector< vector<int> > count_rank;

int main(void)
{
	int sum=0;
	int most_freq = 0;
	
	cin >> N;
	numbers.resize(N);
	counts.resize(8001);
	count_rank.resize(500001);
	
	for(int i=0;i<N;++i) {
		cin >> numbers[i];
		sum += numbers[i];
	}
		 
	sort(numbers.begin(), numbers.end());
	
	for(int i=0;i<N;++i) {
	    counts[numbers[i]+4000]+=1;
	    if (most_freq < counts[numbers[i]+4000]) {
	    	most_freq+=1;
	        count_rank[most_freq].push_back(numbers[i]);
	    }
	    else {
	        count_rank[counts[numbers[i]+4000]].push_back(numbers[i]);
	    }
	}
	
	cout << round((double)sum/N) << endl;
	cout << numbers[N/2] << endl;
	if (count_rank[most_freq].size()>1)
	    cout << count_rank[most_freq][1] << endl;
	else
	    cout << count_rank[most_freq][0] << endl;
	cout << numbers[numbers.size()-1]-numbers[0] << endl;
	
	return 0;
}

