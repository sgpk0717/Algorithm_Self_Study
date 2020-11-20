#include <iostream> 
#include <vector>

using namespace std;  

int N, M, K;
int Answer=999999999;
vector< vector<int> > matrix;
vector< vector<int> > permutations;
vector< vector<int> > commands;
vector<int> permutation;
vector<int> flags;

int get_result(void) {
	int min=999999999;
	int sum;
	for(int i=0;i<matrix.size();++i) {
		sum=0;
		for(int j=0;j<matrix[i].size();++j) {
			sum+=matrix[i][j];
		}
		if(min>sum) min = sum;
	}
	return min;
}

void rotate_matrix(int r, int c, int s) {
	int len = 2*s+1;
	vector< vector<int> > temp_matrix(len, vector<int>(len));
	
	for(int i=0;i<len;++i) {
		for(int j=0;j<len;++j) {
			temp_matrix[i][j] = matrix[r-s-1+i][c-s-1+j];
		}
	}
	
	int edge_num=0;
	while(len>1) {
		for(int i=1;i<len;++i) {
			temp_matrix[edge_num][i+edge_num] = matrix[r-s-1+edge_num][c-s-2+i+edge_num];
			temp_matrix[i+edge_num][temp_matrix.size()-edge_num-1] = matrix[r-s-2+i+edge_num][c+s-1-edge_num];
			temp_matrix[temp_matrix.size()-1-edge_num][temp_matrix.size()-1-i-edge_num] = matrix[r+s-1-edge_num][c+s-i-edge_num];
			temp_matrix[temp_matrix.size()-1-i-edge_num][edge_num] = matrix[r+s-i-edge_num][c-s-1+edge_num];
		}
		++edge_num;
		len-=2;
	} 
	
	len = 2*s+1;
	for(int i=0;i<len;++i) {
		for(int j=0;j<len;++j) {
			matrix[r-s-1+i][c-s-1+j] = temp_matrix[i][j];
		}
	}
}

void pmt(int n) {
	if(n==K) {
		permutations.push_back(permutation);
		return;
	}
	for(int i=0;i<K;++i) {
		if(flags[i]==0) {
			flags[i]=1;
			permutation.push_back(i);		
			pmt(n+1);
			permutation.pop_back();
			flags[i]=0;
		}
	}
}



int main(void){
	cin >> N >> M >> K;
	flags.resize(4);
	commands.resize(K,vector<int>(3));
	matrix.resize(N, vector<int>(M));
	
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			cin >> matrix[i][j];
			
	for(int i=0;i<K;++i)
		for(int j=0;j<3;++j)
			cin >> commands[i][j];
	pmt(0);
	
	for(int i=0;i<permutations.size();++i) {
		vector< vector<int> > temp = matrix;
		for(int j=0;j<permutations[i].size();++j) {
			int command_num = permutations[i][j];
			vector<int> command = commands[command_num];
			rotate_matrix( command[0], command[1], command[2] );
		}
		int value = get_result();
		if(value < Answer) Answer = value;
		matrix = temp;
	}
	cout << Answer << endl;
    return 0;
}
