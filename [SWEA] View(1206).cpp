#include<iostream>
#include <vector>
 
using namespace std;
 
vector<int> heights;
vector<int> min_diffs;
 
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    int N;
    int min_diff, diff;
    int sum;
     
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        heights.clear();
        min_diffs.clear();
         
        heights.resize(N);
        min_diffs.resize(N);
         
        for(int j=0;j<N;++j) {   // get heights
            cin >> heights[j];            
        }
         
        for(int j=2;j<N-2;++j) {
            min_diff=300;
            for(int k=j-2;k<=j+2;++k) {
                if(k==j) continue;
                diff = heights[j] - heights[k];
//              printf("%d-%d = %d\n",heights[j], heights[k], diff);
                if(diff < min_diff)              
                    min_diff = diff;
            }
            if(min_diff >= 0) min_diffs[j] = min_diff;
            else min_diffs[j] = 0;
        }
         
        sum=0;
        for(int j=2;j<N-2;++j) {
//          cout << min_diffs[j] << ' ';
            sum+=min_diffs[j];
        }
//      cout << endl;
        printf("#%d %d\n",test_case,sum);
    }
 
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
