#include <iostream>
#include <fstream>
#include <vector>

#define UNVISITED 	0
#define VISITED 	1
#define LEAF		2

using namespace std;

int N;
int length;
int max_length=0;
int max_node; 
vector<int> visited;
vector< vector< pair<int,int> > > tree;

void explore(int node) {
//	printf("========%d�� ��带 �湮.========\n",node); 
	
	for(int i=0;i<tree[node].size();++i) {
		if( visited[ tree[node][i].first ] == UNVISITED ) {	// �湮������ ���ٸ� 
//			printf("%d�� ��带 �湮������ �����Ƿ� �湮��.\n",tree[node][i].first); 
			visited[ tree[node][i].first ] = VISITED;	// �湮�ߴٰ� ǥ���ϰ� 
			length += tree[node][i].second;				// �Ÿ��� ���ϰ� 
//			printf("�Ÿ� %d�� ����.\n", tree[node][i].second);
			explore( tree[node][i].first );				// �湮�ض�. 
//			printf("%d�� ��� �湮��.\n",tree[node][i].first); 
			visited[ tree[node][i].first ] = UNVISITED;	// ������ �ٽ� �Ȱ��ɷ��ϰ�
			length -= tree[node][i].second;				// �Ÿ��� ����. 
//			printf("�Ÿ� %d�� ��.\n", tree[node][i].second);
		} 
		else if( visited[ tree[node][i].first ] == LEAF ) {
//			printf("%d�� ��尡 ���������.\n", tree[node][i].first); 
			if(length + tree[node][i].second > max_length) {
//				printf("length�� %d�̰� max_length�� %d�̹Ƿ� �ٲ�.\n",length + tree[node][i].second,max_length); 
				max_length = length + tree[node][i].second;
				max_node   = tree[node][i].first;
			} else {
//				printf("length�� %d�̰� max_length�� %d�̹Ƿ� �ȹٲ�.\n",length + tree[node][i].second,max_length); 
			}
		}
	}
}

void set_leaf(void) {
	for(int i=2;i<=N;++i)	
		if(tree[i].size()==1)
			visited[i]=LEAF;
}

int main(void)
{
	int n1,n2,distance;
	
	ifstream ifs("1967_1.txt");
//	ifs >> N;
	cin >> N;

	visited.resize(N+1);
	tree.resize(N+1);
	for(int i=0;i<N-1;++i) {
//		ifs >> n1 >> n2 >> distance;
		cin >> n1 >> n2 >> distance;
		tree[n1].push_back(pair<int,int>(n2,distance));
		tree[n2].push_back(pair<int,int>(n1,distance));
	}
	set_leaf();
	
//	for(int i=0;i<tree.size();++i) {
//		printf("%d��° ���� ����� ���: ",i); 
//		for(int j=0;j<tree[i].size();++j) 
//			printf("(%d��,%d) ",tree[i][j].first,tree[i][j].second); 
//		cout << endl;
//	}

	visited[1]=VISITED;
	explore(1);
	visited[1]=UNVISITED;
	
	explore(max_node);
	
	cout << max_length << endl;
	
	return 0;
}

