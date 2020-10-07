#include <iostream> 
#include <algorithm>
#include <vector> 

using namespace std;  

int N, M, K;
vector< vector<int> > nourishment_map;
vector< vector< vector<int> > > tree_age_map;
vector< vector<int> > nourishment;
vector< vector<int> > trees;
vector< vector< vector<int> > > dead_trees;

int get_total_tree_num(void) {
	int sum=0;
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			sum+=tree_age_map[i][j].size();
		}
	}
	return sum;
}

bool check_range(int r, int c) {	
	if(!(r>=0 && r<N)) return false;
	if(!(c>=0 && c<N)) return false;
	return true;	
}

void add_trees(int r, int c) {
	if(check_range(r-1,c-1)) {
		tree_age_map[r-1][c-1].insert(tree_age_map[r-1][c-1].begin(), 1);
	}
	if(check_range(r-1,c)) {
		tree_age_map[r-1][c].insert(tree_age_map[r-1][c].begin(), 1);
	}
	if(check_range(r-1,c+1)) {
		tree_age_map[r-1][c+1].insert(tree_age_map[r-1][c+1].begin(), 1);
	}
	if(check_range(r,c-1)) {
		tree_age_map[r][c-1].insert(tree_age_map[r][c-1].begin(), 1);
	}
	if(check_range(r,c+1)) {
		tree_age_map[r][c+1].insert(tree_age_map[r][c+1].begin(), 1);
	}
	if(check_range(r+1,c-1)) {
		tree_age_map[r+1][c-1].insert(tree_age_map[r+1][c-1].begin(), 1);
	}
	if(check_range(r+1,c)) {
		tree_age_map[r+1][c].insert(tree_age_map[r+1][c].begin(), 1);
	}
	if(check_range(r+1,c+1)) {
		tree_age_map[r+1][c+1].insert(tree_age_map[r+1][c+1].begin(), 1);
	}
}

void spring(void) {
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			for(int k=0;k<tree_age_map[i][j].size();++k) {	
				if(tree_age_map[i][j][k] > nourishment_map[i][j]) {	// 양분이 모자라면 뒤에 놈들 다 죽이기 
					for(int l=k;l<tree_age_map[i][j].size();++l)	// 먼저 죽은 나무 리스트에 추가하고 
						dead_trees[i][j].push_back(tree_age_map[i][j][l]);
					tree_age_map[i][j].erase(tree_age_map[i][j].begin()+k,tree_age_map[i][j].end()); // 다 지움. 	
					break; 
				}
				nourishment_map[i][j]-=tree_age_map[i][j][k];	// 나이만큼 양분먹고 
				tree_age_map[i][j][k]+=1;	// 나이 한 살 증가 
			}
		}
	}
}

void summer(void) {
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			for(int k=0;k<dead_trees[i][j].size();++k) {
				nourishment_map[i][j]+=dead_trees[i][j][k]/2;	// 죽은 나무의 나이/2 만큼 양분 추가 
			}
			dead_trees[i][j].clear();	// 죽은 나무 목록 초기화 
		}
	}
}

void autumn(void) {
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			for(int k=0;k<tree_age_map[i][j].size();++k) {
				if(tree_age_map[i][j][k]%5==0) {
					add_trees(i,j);
				}
			}
		}
	}
}

void winter(void) {
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			nourishment_map[i][j]+=nourishment[i][j];	// 양분 추가		
		}
	}
}

int main(void){
	cin >> N >> M >> K;
	tree_age_map.resize(N);
	nourishment_map.resize(N, vector<int>(N,5));
	nourishment.resize(N);
	trees.resize(M);
	dead_trees.resize(N);
	
	for(int i=0;i<N;++i) {
		tree_age_map[i].resize(N);
		dead_trees[i].resize(N);
	}
	for(int i=0;i<N;++i) {
		int temp;
		for(int j=0;j<N;++j) {
			cin >> temp;
			nourishment[i].push_back(temp);			
		}
	}
	for(int i=0;i<M;++i) {
		int x, y, age;
		cin >> x >> y >> age;
		tree_age_map[x-1][y-1].push_back(age);
	}
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			if(tree_age_map[i][j].size()>=2)		
				sort(tree_age_map[i][j].begin(), tree_age_map[i][j].end());
		}
	}
	for(int i=0;i<K;++i) {
		spring();
		summer();
		autumn();
		winter();
	}
	
	cout << get_total_tree_num() << endl;
	
    return 0;
}

