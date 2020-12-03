#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> A;
vector<int> B;
vector<int> sum;

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int max_len = s1.size() > s2.size() ? s1.size() : s2.size();
	int idx;
	
	A.resize(max_len);
	B.resize(max_len);
	sum.resize(max_len);
//	cout << "max_len: " << max_len << endl;
	
	for(int i=s1.size()-1,idx=0;i>=0;--i) {
		A[idx++] = s1[i]-'0';		
	}
	for(int i=s2.size()-1,idx=0;i>=0;--i) {
		B[idx++] = s2[i]-'0';	
	}
	
//	for(int i=max_len-1;i>=0;--i)
//		cout << A[i];
//	cout << endl;
//	
//	for(int i=max_len-1;i>=0;--i)
//		cout << B[i];
//	cout << endl;
	
	
	int carry=0,s;
	for(int i=0;i<max_len;++i) {
		s = A[i] + B[i];
		s += carry;
		sum[i] = s%10;
		
		if(s>=10) carry=1;
		else carry=0;
	}
	
	if(carry==1) sum.push_back(1);
	
	for(int i=sum.size()-1;i>=0;--i)
		cout << sum[i];
	cout << endl;
	
	return 0;
}
