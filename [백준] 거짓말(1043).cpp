#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> people_check;
vector<bool> party_check;
vector< vector<bool> > party;
queue<int> know_truth;

int N, M, K;
int Answer;

void processing(void) {
	int p;
	
	while(!know_truth.empty()) {
		p=know_truth.front();	
		know_truth.pop();
		//printf("%d �̾Ƴ�.\n", p); 
		
		if(people_check[p])  {
			//cout << "continue" << endl; 
			continue;	
		}
		people_check[p]=true;
		
		for(int i=0;i<party.size();++i) {
			//cout << i+1 << "��° ��Ƽ." << endl; 
			if(party_check[i]) {
				//cout << "continue" << endl; 
				continue;	
			}
			if(party[i][p]) {
				party_check[i]=true;
				//printf("%d�� ������ ��Ƽ��.\n",p); 
				for(int j=0;j<party[i].size();++j)	
					if(party[i][j] && !people_check[j]) {
						//printf("%d �� ������.",j); 
						know_truth.push(j);
						//printf("%d ť�� �߰�.\n",j);	
					}
			}			
		}
		
	}
	
	
}

int main(void)
{
	cin >> N >> M >> K;
	people_check.resize(N+1);
	party_check.resize(M);
	party.resize(M,vector<bool>(N+1));
	
	int t,tt;
	
	for(int i=0;i<K;++i) {
		cin >> t;	
		know_truth.push(t);
		//printf("%d ť�� �߰�.\n",t);
	}
	
	for(int i=0;i<M;++i) {
		cin >> t;
		for(int j=0;j<t;++j) {
			cin >> tt;
			party[i][tt]=true;
		}
	}
	
	processing();
	
//	cout << "������ �ƴ»��: "; 
//	for(int i=1;i<people_check.size();++i)
//		if(people_check[i])
//			cout << i << ' ';
	//cout << endl;
	
	//cout << "������ ���ص��Ǵ� ��Ƽ: "; 
	for(int i=0;i<party_check.size();++i) {
		if(!party_check[i]) {
			//cout << i+1 << ' ';		
		 	++Answer;
		}
			
	}
	//cout << endl;
	cout << Answer << endl;
	
	return 0;
}
