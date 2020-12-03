#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(void)
{
	string A, B;
	int Ai, Bi;
	
	cin >> A >> B;
	
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	
	Ai = atoi(A.c_str());
	Bi = atoi(B.c_str());
	
	cout << (Ai > Bi ? Ai : Bi) << endl; 
	
	return 0;
}
