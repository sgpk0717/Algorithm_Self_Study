#include <string>
#include <vector>
#include <iostream>

using namespace std;

int count_same_string(int str_len, int index, const string& s) {
    int count=1;
    string target = s.substr(index,str_len);
    index+=str_len;
    while(index+str_len<=s.size()) {
        if(s.substr(index,str_len)==target) {
            ++count;
            index+=str_len;
        }
        else {
            break;
        }
    }
    return count;
}

int solution(string s) {
    int answer = 0;
    int length, index;
    vector<int> zip(s.size()/2+1,0);
    zip[0] = s.size();
    
    for(int i=1;i<zip.size();++i) {
        length=0;
        for(index=0;index<s.size();) {
        	string target = s.substr(index,i);
            int retv = count_same_string(i,index,s);
            index+=retv*i;
            if(retv > 1) {
                length+=i+1;
            }
            else {
                length+=i;
            }
        }
        zip[i] = length+(s.size()-index);
    }
    
    for(int i=0;i<zip.size();++i) {
    	cout << zip[i] << endl;    	
    }
    
    return answer;
}

int main(void)
{
	string s;
	cin >> s;
	solution(s);



	return 0;
}
