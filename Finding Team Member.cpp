#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > strength;
vector<int> teammates;

void print_strength(void) {
	for(int i=0;i<strength.size();++i) {
		for(int j=0;j<strength[i].size();++j) {
			cout << strength[i][j] << '\t';
		}
		cout << endl;
	}
}

void find_max_strength(void) {
	int max=0;
	int max_i,max_j;
	for(int i=2;i<strength.size();++i) {
		for(int j=1;j<i;++j) {
			if(strength[i][j]>max) {
				if(teammates[i]==0 && teammates[j]==0) {
					max = strength[i][j];
					max_i = i;
					max_j = j;
				}
			}
		}
	}
	strength[max_i][max_j] = 0;
	strength[max_j][max_i] = 0;
	teammates[max_i]=max_j;
	teammates[max_j]=max_i;
}

int main(void)
{
	int n;
	cin >> n;
	strength.resize(2*n+1,vector<int>(2*n+1,0));
	teammates.resize(2*n+1,0);
	
	for(int i=2;i<=2*n;++i) {
		for(int j=1;j<i;++j) {
			cin >> strength[i][j];
			strength[j][i] = strength[i][j];
		}
	}
//	
//	print_strength();
	
	for(int i=0;i<n;++i)
		find_max_strength();
		
	for(int i=1;i<teammates.size();++i)
		cout << teammates[i] << ' ';
	cout << endl;
	
	return 0;
}
