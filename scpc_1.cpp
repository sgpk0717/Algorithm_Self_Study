/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;
vector<long long> rest_A;
vector<long long> rest_B;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);
    int N, K;
    
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		cin >> N >> K;  // N과 K 입력받음
		rest_A.clear();
		rest_B.clear();
		rest_A.resize(N);   // 공간 늘려놓기
		rest_B.resize(N);
		
		for(int i=0;i<N;++i) {  // 칼로리 입력받음
		    cin >> rest_A[i];
		}
		for(int i=0;i<N;++i) {
		    cin >> rest_B[i];
		}
		
		sort(rest_A.begin(), rest_A.end());  // 오름차순 정렬
		sort(rest_B.begin(), rest_B.end());
		
		if(N != K) {
		    rest_A.erase(rest_A.end()-(N-K), rest_A.end());
		    rest_B.erase(rest_B.end()-(N-K), rest_B.end());
		}
		
 		for(int i=0;i<rest_A.size();++i) {  
 		    cout << rest_A[i] << ' ';
 		}
 		cout << endl;
 		for(int i=0;i<rest_B.size();++i) {
 		    cout << rest_B[i] << ' ';
 		}
 		cout << endl;
        
        for(int i=0;i<rest_A.size();++i) {
            if(rest_A[i] + rest_B[K-1-i] > Answer) {
                Answer = rest_A[i] + rest_B[K-1-i];
            }
        }
        
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
