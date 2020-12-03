#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int Answer;
int previous, current;
vector< vector<int> > participants;
vector<int> mafia;
vector<bool> checked;
queue<int> waiting;

int get_max_mafia(void) {
	int cnt=0;
	for(int i=1;i<mafia.size();++i)
		if(mafia[i]==1)
			++cnt;
	
	return cnt;
}

void print_participants(void) {
	cout << "===========역할 출력===========" << endl; 
	for(int i=1;i<mafia.size();++i)
		if(mafia[i]==1)
			printf("%d번: 마피아\n",i); 
		else if(mafia[i]==0)
			printf("%d번: 시민\n",i);
		else
			printf("%d번: 정해지지 않음\n",i);
	cout << "===============================" << endl; 
}

int get_adj_node(int target) {
	if(participants[target].size()==0) return -1;
	return participants[target][0];	
}

int get_max_pointed(void) {
	int max=0;
	int num=0;
	
	for(int i=0;i<participants.size();++i)
		if(participants[i].size()>max) {
			max = participants[i].size();
			num = i;
		}
	
	return num;
}

//void refresh(int target) {
//	if(mafia[target]) {	
//		for(int i=0;i<participants[target].size();++i) {
//			if(mafia[ participants[target][i] ])		// 타겟이 마피아인데 주변에 마피아가 있을경우 
//				mafia[ participants[target][i] ] = false; // 대상을 시민으로 바꿈. 
//		}
//	} 
//	else {
//		for 
//		
//		
//	}
//}

void dfs(int target) {
	if(checked[target])	return;
	checked[target] = true;
	
	 
	if(mafia[target]==1) { // 타겟이 마피아라면 
		printf("=======%d번은 마피아임=======\n", target); 
		for(int i=0;i<participants[target].size();++i) {	// 지목한 사람들은 절대 마피아가 아님 
			mafia[ participants[target][i] ] = false;
			dfs(participants[target][i]);
		}
	}
	else if(mafia[target]==0){	// 타겟이 시민이라면 
		printf("=======%d번은 시민임=======\n", target);
		for(int i=0;i<participants[target].size();++i) {	// 지목한 사람들은 마피아일수도 아닐수도 
			if( checked[ participants[target][i] ] ) continue;
			mafia[ participants[target][i] ] = true;
			dfs(participants[target][i]);
		}
	}
}

void processing(void) {
	int target;
	
	for(int i=1;i<=N;++i)
		waiting.push(i);
		
	while(!waiting.empty()) {
		target = waiting.front();
		waiting.pop();
		
		if(checked[target]) continue;
		printf("%d는 아직 정해지지 않음\n",target); 
		
		dfs(target);		
	}
}

int main(void)
{
	int pointed;
	int start_point;
	
	cin >> N;
	
	participants.resize(N+1);
	mafia.resize(N+1,-1);
	checked.resize(N+1);
	
	for(int i=1;i<=N;++i) {
		cin >> pointed;
		participants[pointed].push_back(i);
	}
	
	/* 1회차 */ 
	print_participants();
	start_point = get_max_pointed();
	mafia[start_point] = 0;
	dfs(start_point);
	processing();
	
	print_participants();
	
	previous = get_max_mafia(); 
	printf("마피아는 최대 %d명\n",previous); 
	
	/* 2회차 */ 
	mafia.clear();
	checked.clear();
	
	mafia.resize(N+1,-1);
	checked.resize(N+1);
	
	mafia[get_adj_node(start_point)] = 0;
	dfs(get_adj_node(start_point));
	processing();
	print_participants();
	
	
	current = get_max_mafia();
	printf("마피아는 최대 %d명\n",current);
	
	cout << max(previous, current) << endl; 
	
	return 0;
}
