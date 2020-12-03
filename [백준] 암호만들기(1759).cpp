#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> alphas;
vector<char> pw;

bool check_valid(void) {
	int cnt_moeum=0;
	int cnt_jaeum=0;
	
	char moeum[5] = {'a', 'e', 'i', 'o', 'u'};
	for(int i=0;i<pw.size();++i) {
		int j;
		for(j=0;j<5;++j) {
			if(pw[i]==moeum[j]) {
				cnt_moeum++;
				break;	
			}
		}
		if(j==5)
			cnt_jaeum++;	
	}
//	printf("자음: %d, 모음: %d\n", cnt_jaeum, cnt_moeum); 
	if(cnt_moeum>=1 && cnt_jaeum>=2)
		return true;
	else
		return false;
}

void DFS(int index) {
	if(pw.size()==L) {
		if(check_valid()) {
			for(int i=0;i<pw.size();++i)
				cout << pw[i];
			cout << endl; 
		}
		return;
	}
	if(index==C)
		return;


	for(int i=index;i<C;++i) {
		pw.push_back(alphas[i]);
		DFS(i+1);
		pw.pop_back();
	}
}

int main(void)
{
	cin >> L >> C;
	alphas.resize(C);
	for(int i=0;i<C;++i)
		cin >> alphas[i];
		
	sort(alphas.begin(), alphas.end());
//	for(int i=0;i<alphas.size();++i)
//		cout << alphas[i] << ' ';
//	cout << endl;
	
	DFS(0);
	
	
	return 0;
}
