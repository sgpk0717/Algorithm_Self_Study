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
//		cout << i << "번째 행 탐색 시작." << endl; 
		int j;
		for(j=1;j<N;++j) {
			int current_height = maps[i][j];
//			printf("이전 높이: %d, 현재 높이: %d\n",prev_height, current_height); 
			if(prev_height!=current_height) {
//				printf("높이는 %d만큼 차이남.\n", abs(prev_height-current_height)); 
				if( abs(prev_height-current_height)>1 ) break;
				
				if(prev_height>current_height) {
					if(j+L>N) break;
					if(slopes[i][j]) break;	// 현재 위치에 슬로프가 이미 있으면 탈락 
					int k;
					for(k=j;k<j+L-1;++k) {		// 슬로프 놓을 길이 다 평면인지 확인 
						if(maps[i][k]!=maps[i][k+1]) break;
						if(slopes[i][k+1]) break;	// 슬로프 있으면 탈락	
					}	
					if(k<j+L-1) break;
					
					for(k=j;k<j+L;++k) 	// 문제없으면 슬로프 깔기 
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
//			cout << "Answer 1 증가." << endl; 
			Answer++;	
		}
	}
	
	slopes.clear();
	slopes.resize(N, vector<bool>(N,false));
	
	for(int i=0;i<N;++i) {
		int prev_height = maps[0][i];
//		cout << "=======================" << endl;
//		cout << i << "번째 열 탐색 시작." << endl;
		int j; 
		for(j=1;j<N;++j) {
			int current_height = maps[j][i];
//			printf("이전 높이: %d, 현재 높이: %d\n",prev_height, current_height); 
			if(prev_height!=current_height) {
//				printf("높이는 %d만큼 차이남.\n", abs(prev_height-current_height)); 
				if( abs(prev_height-current_height)>1 ) break;
				
				if(prev_height>current_height) {
					if(j+L>N) break;
					if(slopes[j][i]) break;	// 현재 위치에 슬로프가 이미 있으면 탈락 
					int k;
					for(k=j;k<j+L-1;++k) {		// 슬로프 놓을 길이 다 평면인지 확인 
						if(maps[k][i]!=maps[k+1][i]) break;
						if(slopes[k+1][i]) break;	// 슬로프 있으면 탈락	
					}	
					if(k<j+L-1) break;
					
					for(k=j;k<j+L;++k) 	// 문제없으면 슬로프 깔기 
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
//			cout << "Answer 1 증가." << endl; 
			Answer++;	
		}
	}
	
	cout << Answer << endl;	
	
	return 0;
}
