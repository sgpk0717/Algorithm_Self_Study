#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int N;
	string word;
	cin >> N;
	for(int i=0;i<N;++i) {
		cin >> word;
		if(word.size()<=10) {
			cout << word << endl;
			continue;
		}
		
		string temp = "";
		temp+=word[0];
		temp+=to_string(word.size()-2);
		temp+=word[word.size()-1];
		cout << temp << endl;
	}
			
	return 0;
}
