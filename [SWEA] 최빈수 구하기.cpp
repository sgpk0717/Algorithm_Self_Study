#include <iostream>
#include <vector>

using namespace std;

int get_frequent_index(const vector<int>& scores) {
    int max=0;
    int index=-1;
    for(int i=0;i<scores.size();++i) {   
    	if(scores[i] > max) {
			max = scores[i];
			index = i;
		}
    }
    
    return index;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

//	freopen("input.txt", "r", stdin);
	cin>>T;
    
	
    int tmp, case_num;
	for(test_case = 1; test_case <= T; ++test_case)
	{
       	vector<int> scores(101, 0);
        
        cin >> case_num;
        int cnt=0;
        while(cnt<1000) {
        	cin >> tmp;
            scores[tmp]++;
            cnt++;
        }
        for(int i=0;i<scores.size();++i)
        	printf("%d: %d\n", i, scores[i]);
        int answer = get_frequent_index(scores);
		
        printf("#%d %d\n",case_num,answer);
	}
	return 0;
}
