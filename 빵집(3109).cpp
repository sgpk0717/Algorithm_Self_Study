#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int R, C;
int Answer;
char maze[10000][500];

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

bool is_valid(int x) {
	if(!(x>=0 && x<R)) return 0;
	return 1;
}

bool pipelining(int x, int y) {
	/* ������ ���������� */ 
	if(y==C-1) return true; // �����ߴٴ� ��ȣ 
	
	//printf("\n������ġ (%d,%d).\n",x,y);
	//print_maze();
	
	int j=y+1;
	int i;
	
	for(i=x-1;i<=x+1;++i) { // ������ �׽�Ʈ 
		if(is_valid(i)) { // ��ǥ�� ��ȿ�Ҷ��� 
			if(maze[i][j]=='.') { // ����϶��� 
				maze[i][j]='0'; // ��� ����
				if(pipelining(i,j)) { // ���� ��η� 
					return true;	// ������
				}
			}
		}
	}
	return false; 
}

void processing(void) {
	//cout << endl << "Processing ����." << endl; 
	for(int i=0;i<R;++i) {	
		//printf("%d,%d���� ���������̴� ����.\n",i,0);
		if(pipelining(i,0)) { 	// ���������̴� ���� 
			++Answer;			// �����ÿ� ī��Ʈ ���� 
			//cout << "����!" << endl; 
			//print_maze();
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin >> R >> C;
	
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			cin >> maze[i][j];
	
//	print_maze();
	
	processing(); 
	
	cout << Answer << endl;
	
	return 0;
}
