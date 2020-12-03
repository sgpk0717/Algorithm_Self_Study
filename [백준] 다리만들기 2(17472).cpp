#include <iostream>  
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> crd;

int N, M;
int Answer=9999999;
int num_of_island;
int total;
vector< vector<int> > map;
vector< vector<crd> > crd_island;
vector< vector<int> > bridge_list;
vector< vector<int> > bridge_combination;
vector< vector<int> > comb_list;
vector< vector<int> > connection_list;
vector< int > comb;
vector<bool> visited;
vector< vector<bool> > checked;

void print_map(void) {
	for(int i=0;i<N;++i) {
		for(int j=0;j<M;++j)
			cout << map[i][j] << ' ';
		cout << endl;
	}
}

void print_bridge_list(void) {
	for(int i=0;i<bridge_list.size();++i) {
		for(int j=0;j<bridge_list[i].size();++j) {
			if(bridge_list[i][j]==9999) cout << 0 << ' ';
			else cout << bridge_list[i][j] << ' ';	
		}
		cout << endl;
	}
}

bool check_range(int x, int y) {
	if(!((x>=0) && (x<N))) return false;	
	if(!((y>=0) && (y<M))) return false;
	return true;
}

void explore_island(int x, int y, int island_num, vector< vector<int> >& temp_map) {
	vector<crd> crds;
	queue<crd> q;
	q.push(crd(x,y));
	temp_map[x][y]=0;
	map[x][y]=island_num;
	crds.push_back(crd(x,y));
	
	while(!q.empty()) {
		crd next = q.front();
		q.pop();
		int nx=next.first, ny=next.second;
		
		if(check_range(nx-1,ny) && temp_map[nx-1][ny]==1) {
			crds.push_back(crd(nx-1,ny));
			q.push(crd(nx-1,ny));
			temp_map[nx-1][ny]=0;
			map[nx-1][ny]=island_num;
		}
		if(check_range(nx,ny-1) && temp_map[nx][ny-1]==1) {
			crds.push_back(crd(nx,ny-1));
			q.push(crd(nx,ny-1));
			temp_map[nx][ny-1]=0;
			map[nx][ny-1]=island_num;
		}
		if(check_range(nx,ny+1) && temp_map[nx][ny+1]==1) {
			crds.push_back(crd(nx,ny+1));
			q.push(crd(nx,ny+1));
			temp_map[nx][ny+1]=0;
			map[nx][ny+1]=island_num;
		}
		if(check_range(nx+1,ny) && temp_map[nx+1][ny]==1) {
			crds.push_back(crd(nx+1,ny));
			q.push(crd(nx+1,ny));
			temp_map[nx+1][ny]=0;
			map[nx+1][ny]=island_num;
		}
	}
	crd_island.push_back(crds);
}

void get_crd_island(void) {
	vector< vector<int> > temp_map = map;
	int inum=1;
	for(int i=0;i<N;++i) {
		for(int j=0;j<M;++j) {
			if(temp_map[i][j]==1) {
				explore_island(i,j,inum,temp_map);
				++inum;
			}
		}
	}
}

void make_bridge(int x, int y) {
	int bridge_len=0, i;
	/* 위로 다리 뻗기 */ 
	if(x-1>=0) {
		for(i=1;x-i>=0;++i) {
			if(map[x-i][y]!=0) break;
			++bridge_len;
		}
		if(x-i>=0) {
			if(bridge_len>=2) {
				if(bridge_len < bridge_list[ map[x][y]-1 ][ map[x-i][y]-1 ]) {
					bridge_list[ map[x][y]-1 ][ map[x-i][y]-1 ] = bridge_len;
				}
			}
		}
	}
	
	bridge_len=0;
	/* 왼쪽으로 다리 뻗기 */ 
	if(y-1>=0) {
		for(i=1;y-i>=0;++i) {
			if(map[x][y-i]!=0) break;
			++bridge_len;
		}
		if(y-i>=0) {
			if(bridge_len>=2) {
				if(bridge_len < bridge_list[ map[x][y]-1 ][ map[x][y-i]-1 ]) {
					bridge_list[ map[x][y]-1 ][ map[x][y-i]-1 ] = bridge_len;
				}
			}
		}
	}
	
	bridge_len=0;
	/* 아래쪽으로 다리 뻗기 */ 
	if(x+1<N) {
		for(i=1;x+i<N;++i) {
			if(map[x+i][y]!=0) break;
			++bridge_len;
		}
		if(x+i<N) {
			if(bridge_len>=2) {
				if(bridge_len < bridge_list[ map[x][y]-1 ][ map[x+i][y]-1 ]) {
					bridge_list[ map[x][y]-1 ][ map[x+i][y]-1 ] = bridge_len;
				}
			}
		}
	}
	
	bridge_len=0;
	/* 오른쪽으로 다리 뻗기 */ 
	if(y+1<M) {
		for(i=1;y+i<M;++i) {
			if(map[x][y+i]!=0) break;
			++bridge_len;
		}
		if(y+i<M) {
			if(bridge_len>=2) {
				if(bridge_len < bridge_list[ map[x][y]-1 ][ map[x][y+i]-1 ]) {
					bridge_list[ map[x][y]-1 ][ map[x][y+i]-1 ] = bridge_len;
				}
			}
		}
	}
}

bool check_all_connected(const vector< int >& comb) {
	if(comb_list.size()==0) return false;
	queue<int> q;
	vector<int> visit;
	visit.resize(num_of_island,false);
	int start=bridge_combination[comb[0]][0];
	
	vector< vector<int> > temp_blist(num_of_island);
	
	for(int i=0;i<comb.size();++i) { 
		temp_blist[bridge_combination[comb[i]][0]].push_back(bridge_combination[comb[i]][1]);
	}
	for(int i=0;i<comb.size();++i) { 
		temp_blist[bridge_combination[comb[i]][1]].push_back(bridge_combination[comb[i]][0]);
	}
	
	q.push(start);
	visit[start]=true;
	while(!q.empty()) {
		int next = q.front();
		q.pop();
		for(int i=0;i<temp_blist[next].size();++i) {
			if(visit[ temp_blist[next][i] ] == false) {
				visit[ temp_blist[next][i] ] = true;
				q.push( temp_blist[next][i] );
			}
		}
	}
	
	for(int i=0;i<visit.size();++i) {
		if(visit[i]==false) {
			return false;	
		}
	}
	return true;
}

int get_len_sum(const vector<int>& comb) {
	int sum=0;
	
	for(int i=0;i<comb.size();++i) {	
		sum+=bridge_combination[comb[i]][2];		
	}
	return sum;
}

void get_combinations(int c) {
	if(c==bridge_combination.size()+1) {
		return;
	}
	if(comb.size()==num_of_island-1) {
		comb_list.push_back(comb);
		return;
	}
	
	comb.push_back(c);
	get_combinations(c+1);
	comb.pop_back();
	
	get_combinations(c+1);
}


int main(void)
{
	cin >> N >> M;
	map.resize(N, vector<int>(M));
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			cin >> map[i][j];
	
	get_crd_island();
	num_of_island = crd_island.size();
	bridge_list.resize(num_of_island, vector<int>(num_of_island, 9999));
	connection_list.resize(num_of_island);
	checked.resize(num_of_island, vector<bool>(num_of_island,false));
	
	for(int i=0;i<crd_island.size();++i) {
		for(int j=0;j<crd_island[i].size();++j) {
			make_bridge(crd_island[i][j].first, crd_island[i][j].second);
		}
	}
	
	for(int i=0;i<bridge_list.size();++i)
		for(int j=i+1;j<bridge_list[i].size();++j)
			if(bridge_list[i][j]!=9999) {
				vector<int> temp{i, j, bridge_list[i][j]};
				bridge_combination.push_back(temp);	
			}
//	for(int i=0;i<bridge_combination.size();++i) {
//		for(int j=0;j<bridge_combination[i].size();++j) {
//			cout << bridge_combination[i][j] << ' ';		
//		}
//		cout << endl;
//	}

	get_combinations(0);
	
	
//	for(int i=0;i<comb_list.size();++i) {
//		for(int j=0;j<comb_list[i].size();++j) {
//			cout << comb_list[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
	
	for(int i=0;i<comb_list.size();++i) {
		if(check_all_connected(comb_list[i])) {
//			for(int j=0;j<comb_list[i].size();++j) {
//				cout << comb_list[i][j] << ' ';
//			}
//			cout << endl;
			int result = get_len_sum(comb_list[i]);
			if(result<Answer) Answer = result;
		}
	}
	
	
	if(Answer==9999999) cout << -1 << endl;
	else
		cout << Answer << endl;

    return 0;
}
