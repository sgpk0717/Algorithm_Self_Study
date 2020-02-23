#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int R, C;
int Answer;
vector< vector<char> > maze;
stack< pair<int,int> > tracker;

void print_maze(void) {
	for(int i=0;i<C*8;++i)
		cout << '=';
	cout << '=' << endl;
	for(int i=0;i<R;++i) {
		for(int j=0;j<C;++j) {
			cout << maze[i][j] << '\t';
		}
		cout << endl;
	}
	for(int i=0;i<C*8;++i)
		cout << '=';
	cout << '=' << endl;
}

bool is_valid(int x, int y) {
	if(!(x>=0 && x<R)) return 0;
	if(!(y>=0 && y<C)) return 0;
	return 1;
}

bool pipelining(int x, int y) {
	/* ������ ���������� */ 
	if(y==C-1) return true; // �����ߴٴ� ��ȣ 
	
	//printf("\n������ġ (%d,%d).\n",x,y);
//	print_maze();
	
	int j=y+1;
	int i;
	
	for(i=x-1;i<=x+1;++i) { // ������ �׽�Ʈ 
		if(is_valid(i,j)) { // ��ǥ�� ��ȿ�Ҷ��� 
			if(maze[i][j]=='.') { // ����϶��� 
				maze[i][j]='0'+index; // ��� ����
				tracker.push(pair<int,int>(i,j)); // ���ÿ� �ӽ� ���� 
				if(pipelining(i,j,index)) { // ���� ��η� 
					return true;	// ������
				}
				else { 
					return false;	// ���н�  
				}
			}
		}
	}
	return false; 
}

void processing(void) {
	//cout << endl << "Processing ����." << endl; 
	for(int i=0;i<R;++i) {
		//cout << "�����ʱ�ȭ." << endl; 
		while(!tracker.empty()) // ���û���� ���� �ʱ�ȭ 
			tracker.pop();
		
		//printf("%d,%d���� ���������̴� ����.\n",i,0);
		tracker.push(pair<int,int>(i,0));
		maze[i][0]='0'+i;
		if(pipelining(i,0,i)) { 	// ���������̴� ���� 
			++Answer;			// �����ÿ� ī��Ʈ ���� 
			//cout << "����!" << endl; 
//			print_maze();
		}
		else {					// ���н� 
			//cout << "����... ����ʱ�ȭ" << endl;
			while(!tracker.empty()) { // ��������� �ʱ�ȭ 
				int r = tracker.top().first;
				int c = tracker.top().second;
				tracker.pop();
				
				maze[r][c] = '.';
			}
//			print_maze(); 
		}
	}
}

int main(void)
{
	cin >> R >> C;
	maze.resize(R, vector<char>(C));
	
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			cin >> maze[i][j];
	
//	print_maze();
	
	processing(); 
	
	cout << Answer << endl;
	
	return 0;
}
