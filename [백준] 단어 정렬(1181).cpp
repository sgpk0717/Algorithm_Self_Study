#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> words;

bool cmp(const string& s1, const string& s2) {
	if(s1.size() == s2.size()) {
		return s1 < s2;
	}
	else
		return s1.size() < s2.size();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N;
	cin >> N;
	words.resize(N);
	for(int i=0;i<N;++i) {
		cin >> words[i];
	}
	
	sort(words.begin(),words.end(),cmp);
	words.erase(unique(words.begin(),words.end()),words.end());
	for(int i=0;i<words.size();++i)
		cout << words[i] << '\n';
	
	
	
	return 0;
}
