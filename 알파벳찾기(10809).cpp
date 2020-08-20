#include <iostream>
#include <string>

using namespace std;

int check[26];

int main(void)
{
	int index[26]={-1,};
	
	string word;	
	cin >> word;
	
	for(int i=0;i<26;++i) {
		index[i] = -1;
	}
	
	for(int i=0;i<word.size();++i) {
		if(check[word[i]-'a']==0) {
			index[word[i]-'a']=i;
			check[word[i]-'a']=1;
		}
	}
	
	for(int i=0;i<26;++i) {
		cout << index[i] << ' ';	
	}
	cout << endl;
	
	return 0;
}

