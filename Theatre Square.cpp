#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int N, M, A;
	
	cin >> N >> M >> A;

	int x = ceil((double)N/A);
	int y = ceil((double)M/A);
	
	cout << (long long)x*y << endl;
	
	return 0;
}
