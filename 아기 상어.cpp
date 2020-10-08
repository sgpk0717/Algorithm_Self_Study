#include <iostream>  
#include <vector> 
#include <cmath>
#include <algorithm>

using namespace std;  

int N;
int Answer;
int eaten;
vector< vector<int> > sea;
vector< vector<bool> > visit;
typedef pair<int,int> crd;

bool compare(const crd& c1, const crd& c2) {
	if(c1.first != c2.first) return c1.first < c2.first;
	else return c1.second < c2.second;
}
bool check_valid(int x, int y, int shark_size) {
	if( !(x>=0 && x<N) || !(y>=0 && y<N) ) return false;
	if( visit[x][y]==true ) return false;
	if( sea[x][y] > shark_size ) return false;
	return true;
}

void BFS(int sx, int sy, int shark_size) {
	vector< crd > q;
	vector< crd > next;
	
	visit.clear();
	visit.resize(N, vector<bool>(N,false));
	
	q.push_back(crd(sx,sy));
	visit[sx][sy]=true;
	int distance=0;
	int tx=-1, ty=-1;
	while(tx==-1 && !q.empty()) {
		distance++;
		for(int i=0;i<q.size();++i) {
			int nx = q[i].first, ny = q[i].second;
			
			if(check_valid(nx-1, ny, shark_size)) {
				next.push_back(crd(nx-1, ny));
				visit[nx-1][ny] = true;
			}
			if(check_valid(nx, ny-1, shark_size)) {
				next.push_back(crd(nx, ny-1));
				visit[nx][ny-1] = true;
			}
			if(check_valid(nx, ny+1, shark_size)) {
				next.push_back(crd(nx, ny+1));
				visit[nx][ny+1] = true;
			}
			if(check_valid(nx+1, ny, shark_size)) {
				next.push_back(crd(nx+1, ny));
				visit[nx+1][ny] = true;
			}
		}
		
		sort(next.begin(),next.end(),compare);

		for(int i=0;i<next.size();++i) {
			int cx = next[i].first, cy = next[i].second;
			if(sea[cx][cy]>=1 && sea[cx][cy]<shark_size) {
				tx = cx, ty = cy;
				Answer+=distance;
				eaten+=1;
				sea[cx][cy]=0;
				break;			
			}
		}
		if(tx==-1) {
			q.clear();
			for(int i=0;i<next.size();++i) {
				q.push_back(next[i]);				
			}
			next.clear();
		}
	}
	
	if(tx!=-1) {
		if(eaten==shark_size) {
			eaten=0;
			shark_size+=1;
		}
		BFS(tx, ty, shark_size);		
	}
}

int main(void){
	cin >> N;
	sea.resize(N, vector<int>(N));
	
	int sx, sy;
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			cin >> sea[i][j];
			if(sea[i][j]==9) sx=i, sy=j;		
		}
	}
	sea[sx][sy] = 0;
	BFS(sx, sy, 2);
	cout << Answer << endl; 
	
    return 0;
}
