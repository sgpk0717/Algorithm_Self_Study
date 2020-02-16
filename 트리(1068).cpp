#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector< vector<int> > inputs;
int Answer;

void delete_node(int node) {
	/* ���� �������� �ʴ� ����̹Ƿ� �信�� ���� */ 
	--Answer;
	
	if(inputs[node].size()==0) return;
	
	for(int i=0;i<inputs[node].size();++i) 
		delete_node(inputs[node][i]);

	inputs[node].clear();	
}

int main(void)
{
	int N;
	int parent_node, remove_node;
	
	cin >> N;
	inputs.resize(N);
	
	/* ��Ʈ���� �߰����� */ 
	for(int i=0;i<N;++i) {
		cin >> parent_node;
		if(parent_node==-1) continue;
		inputs[parent_node].push_back(i);
	}
	
	/* ������ ��� �Է¹���*/ 
	cin >> remove_node;
	
	/* ���� ������ ��带 �������ִ� �θ����� �ڽĳ���Ͽ��� �ش� ��带 ����*/ 
	for(int i=0;i<inputs.size();++i)
		for(int j=0;j<inputs[i].size();++j)
			if(inputs[i][j]==remove_node) {
				inputs[i].erase(inputs[i].begin()+j);
			}
			
	/* �׸��� ���� ������ ����� ���������� ��� dfs�� ���� */ 
	delete_node(remove_node);
	
	/* ������� �ĺ����� �߰� */ 
	for(int i=0;i<inputs.size();++i)
		if(inputs[i].size()==0)
			++Answer;
			
	cout << Answer << endl;
	
	return 0;
}
