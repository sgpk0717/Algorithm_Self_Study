#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 

using namespace std;

int paper[2187][2187];
int N;
int paper_minus, paper_zero, paper_plus;

void print_paper(void) {
	cout << "----------------paper----------------" << endl << endl;
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j)
			cout << paper[i][j] << '\t';
		cout << endl << endl;
	}
	cout << "-------------------------------------" << endl;
}

int main(void)
{
	ifstream ifs("1780_1.txt");
	ifs >> N;
	
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			ifs >> paper[i][j];
	
	print_paper();
	
	
	
	return 0;
}
