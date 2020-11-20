#include <iostream>  
#include <vector>
#include <cmath>

using namespace std;
 

int N;
int Answer=99999999; 
vector<int> populations;
vector<bool> visited;
vector< vector<int> > zone_list; 
vector< vector<int> > connections;
vector<int> zone;


void DFS_check_zone(int zone_num, vector<int>& zone) {
	visited[zone_num]=true;
	zone.push_back(zone_num);
	
	for(int i=0;i<connections[zone_num].size();++i) {
		int zn = connections[zone_num][i];
		if(!visited[zn]) {
			visited[zn]=true;
			DFS_check_zone(zn,zone);	
		}
	}
}

int get_zone_num(void) {
	int zone_num=0;
	vector<int> zone;
	for(int i=0;i<N;++i) {	
		if(!visited[i]) {
			++zone_num;
			vector<int> zone;
			DFS_check_zone(i, zone);
			zone_list.push_back(zone);
		}
	}
	return zone_num;
}

void split_zone(int c, int n) {
	if(c==N+1) {
		return;
	}
	if(zone.size()==n) {
		zone_list.push_back(zone);
		return;
	}
	
	zone.push_back(c);
	split_zone(c+1,n);
	zone.pop_back();
	
	split_zone(c+1,n);
}

bool is_zone_connected(vector<int>& zone) {
	vector<int> q;
	
	for(int i=0;i<zone.size();++i)
		visited[zone[i]]=false;
	q.push_back(zone[0]);
	visited[zone[0]]=true;
	
	while(!q.empty()) {
		vector<int> next;
		for(int i=0;i<q.size();++i)
			next.push_back(q[i]);
		q.clear();
			
		for(int i=0;i<next.size();++i) {
			int target_zone = next[i];
			for(int j=0;j<connections[target_zone].size();++j) {
				if(!visited[connections[target_zone][j]]) {
					visited[connections[target_zone][j]] = true;	
					q.push_back(connections[target_zone][j]);
				}
			}
		}
		int i;
		for(i=0;i<visited.size();++i) 
			if(visited[i]==false) break;
		if(i==visited.size()) return true;
	}
	return false;
}

int get_sum_population(const vector<int>& zone) {
	int sum=0;
	for(int i=0;i<zone.size();++i) {	
		sum+=populations[zone[i]];
	}
	return sum;
}

int main(void)
{
	cin >> N;
	populations.resize(N);
	connections.resize(N);
	visited.resize(N);
	
	for(int i=0;i<N;++i) {
		cin >> populations[i];
		visited[i]=false;
	}	

	for(int i=0;i<N;++i) {
		int len, temp;
		cin >> len;
		for(int j=0;j<len;++j) {
			cin >> temp;
			connections[i].push_back(temp-1);
		}
	}

	int zone_num = get_zone_num();
	
	if(zone_num > 2) {
		Answer = -1;	
	}
	else if(zone_num == 2) { // 걍 두개로 나누면 끝. 
		int z1 = 0, z2 = 0;
		for(int i=0;i<zone_list[0].size();++i) {
			z1+=populations[zone_list[0][i]];	
		}
		for(int i=0;i<zone_list[1].size();++i) {
			z2+=populations[zone_list[1][i]];	
		}
		Answer = abs(z1-z2);
	}
	else if(zone_num == 1) { // 이거는 두개로 '잘' 나눠야 함. 
		zone_list.clear();
		
		for(int i=1;i<N;++i) 
			split_zone(0,i);

		
		for(int i=0;i<zone_list.size();++i) {
			for(int j=0;j<N;++j)
				visited[j] = true;
			if(!is_zone_connected(zone_list[i])) {
				zone_list.erase(zone_list.begin()+i);
				--i;
				continue;
			}
			
			vector<int> rest_zone;
			for(int k=0;k<N;++k) {
				int l;
				for(l=0;l<zone_list[i].size();++l) {
					if(k == zone_list[i][l]) break;	
				}
				if(l==zone_list[i].size())
					rest_zone.push_back(k);
			}
			
			for(int j=0;j<N;++j)
				visited[j] = true;
			if(!is_zone_connected(rest_zone)) {
				zone_list.erase(zone_list.begin()+i);
				--i;
				continue;
			}
			
			int sz1 = get_sum_population(zone_list[i]);
			int sz2 = get_sum_population(rest_zone);
			int min = abs(sz1-sz2);
			if(min < Answer) Answer = min;
		}
		
		
	}

	cout << Answer << endl;
	
    return 0;
}
