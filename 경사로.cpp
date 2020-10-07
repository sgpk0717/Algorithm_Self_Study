#include <iostream>
#include <vector> 
#include <cmath>

using namespace std;

vector< vector<int> > maps;
vector< vector<bool> > slopes;
int N, L;
int Answer=0;

void print_slopes(void) {
	for(int i=0;i<N;++i) {	
		for(int j=0;j<N;++j) {
			if(slopes[i][j])
				cout << 1 << ' ';		
			else
				cout << 0 << ' ';		
		}
		cout << endl;
	}
}

int main(void)
{
	cin >> N >> L;
	maps.resize(N, vector<int>(N));
	slopes.resize(N, vector<bool>(N,false));
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			cin >> maps[i][j];
	
	
	for(int i=0;i<N;++i) {
		int prev_height = maps[i][0];
//		cout << "=======================" << endl;
//		cout << i << "��° �� Ž�� ����." << endl; 
		int j;
		for(j=1;j<N;++j) {
			int current_height = maps[i][j];
//			printf("���� ����: %d, ���� ����: %d\n",prev_height, current_height); 
			if(prev_height!=current_height) {
//				printf("���̴� %d��ŭ ���̳�.\n", abs(prev_height-current_height)); 
				if( abs(prev_height-current_height)>1 ) break;
				
				if(prev_height>current_height) {
					if(j+L>N) break;
					if(slopes[i][j]) break;	// ���� ��ġ�� �������� �̹� ������ Ż�� 
					int k;
					for(k=j;k<j+L-1;++k) {		// ������ ���� ���� �� ������� Ȯ�� 
						if(maps[i][k]!=maps[i][k+1]) break;
						if(slopes[i][k+1]) break;	// ������ ������ Ż��	
					}	
					if(k<j+L-1) break;
					
					for(k=j;k<j+L;++k) 	// ���������� ������ ��� 
						slopes[i][k] = true;
//					print_slopes();
				}
				else {
					if(j-L<0) break;
					if(slopes[i][j-1]) break;
					int k;
					for(k=j-1;k>j-L;--k) {
						if(maps[i][k]!=maps[i][k-1]) break;	
						if(slopes[i][k-1]) break;
					}
					if(k>j-L) break;
					
					for(k=j-1;k>j-L-1;--k)
						slopes[i][k] = true;
//					print_slopes();
				}
			}
			
			prev_height = current_height;
		}
		if(j==N) {
//			for(int k=0;k<N;++k)
//				cout << maps[i][k] << ' ';
//			cout << endl;
//			cout << "Answer 1 ����." << endl; 
			Answer++;	
		}
	}
	
	slopes.clear();
	slopes.resize(N, vector<bool>(N,false));
	
	for(int i=0;i<N;++i) {
		int prev_height = maps[0][i];
//		cout << "=======================" << endl;
//		cout << i << "��° �� Ž�� ����." << endl;
		int j; 
		for(j=1;j<N;++j) {
			int current_height = maps[j][i];
//			printf("���� ����: %d, ���� ����: %d\n",prev_height, current_height); 
			if(prev_height!=current_height) {
//				printf("���̴� %d��ŭ ���̳�.\n", abs(prev_height-current_height)); 
				if( abs(prev_height-current_height)>1 ) break;
				
				if(prev_height>current_height) {
					if(j+L>N) break;
					if(slopes[j][i]) break;	// ���� ��ġ�� �������� �̹� ������ Ż�� 
					int k;
					for(k=j;k<j+L-1;++k) {		// ������ ���� ���� �� ������� Ȯ�� 
						if(maps[k][i]!=maps[k+1][i]) break;
						if(slopes[k+1][i]) break;	// ������ ������ Ż��	
					}	
					if(k<j+L-1) break;
					
					for(k=j;k<j+L;++k) 	// ���������� ������ ��� 
						slopes[k][i] = true;
//					print_slopes();
				}
				else {
					if(j-L<0) break;
					if(slopes[j-1][i]) break;
					int k;
					for(k=j-1;k>j-L;--k) {
						if(maps[k][i]!=maps[k-1][i]) break;	
						if(slopes[k-1][i]) break;
					}
					if(k>j-L) break;
					
					for(k=j-1;k>j-L-1;--k)
						slopes[k][i] = true;
//					print_slopes();
				}
			}
			prev_height = current_height;
		}
		if(j==N) {
//			for(int k=0;k<N;++k)
//				cout << maps[i][k] << ' ';
//			cout << endl;
//			cout << "Answer 1 ����." << endl; 
			Answer++;	
		}
	}
	
	cout << Answer << endl;	
	
	return 0;
}
