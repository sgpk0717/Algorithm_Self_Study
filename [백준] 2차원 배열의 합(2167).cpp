#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > matrix;
vector< vector<int> > targets;
int N, M, K;

int main(void)
{
	cin >> N >> M;
	matrix.resize(N, vector<int>(M));
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			cin >> matrix[i][j];
	
	cin >> K;
	targets.resize(K,vector<int>(4));
	for(int k=0;k<K;++k) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		targets[k][0] = i;
		targets[k][1] = j;
		targets[k][2] = x;
		targets[k][3] = y;
	}
		
	for(int k=0;k<K;++k) {
		int sum=0;
		for(int i=targets[k][0]-1;i<targets[k][2];++i) {	
			for(int j=targets[k][1]-1;j<targets[k][3];++j) {
				sum += matrix[i][j];
			}
		}
		cout << sum << endl;
	}
		
	return 0;
}
