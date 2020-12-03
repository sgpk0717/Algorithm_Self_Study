#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector< vector<int> > matrix;

int main(void)
{
	int t;
	int n, m;
	
	cin >> t;	
	
	for(int testcase=0;testcase<t;++testcase) {
		int answer = 0;
		cin >> n >> m;
		matrix.clear();
		matrix.resize(n, vector<int>(m));
		
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j) 
				cin >> matrix[i][j];
				
		cout << "============before============" << endl;
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) 
				cout << matrix[i][j] << ' ';
			cout << endl;
		}
			
		for(int i=0;i<n;++i) {
			for(int j=0,k=m-1;j<k;++j,--k) {
				if(matrix[i][j]!=matrix[i][k]) {
					printf("%d와 %d가 다름. answer은 %d만큼 증가.\n", matrix[i][j],matrix[i][k],abs(matrix[i][j]-matrix[i][k]));
					answer+=abs(matrix[i][j]-matrix[i][k]);	
					matrix[i][k] = matrix[i][j];
				}
			}
		}
		cout << "============after1============" << endl;
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) 
				cout << matrix[i][j] << ' ';
			cout << endl;
		}
			
		for(int i=0;i<m;++i) {
			for(int j=0,k=n-1;j<k;++j,--k) {
				if(matrix[j][i]!=matrix[k][i]) {
					printf("%d와 %d가 다름. answer은 %d만큼 증가.\n", matrix[j][i],matrix[k][i],abs(matrix[j][i]-matrix[k][i]));
					answer+=abs(matrix[j][i]-matrix[k][i]);	
					matrix[k][i] = matrix[j][i];
				}
			}
		}
		
		cout << "============after2============" << endl;
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) 
				cout << matrix[i][j] << ' ';
			cout << endl;
		}
		
		cout << answer << endl;
	}
	
	
	
	
	
	return 0;
}
