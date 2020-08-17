#include <iostream>

using namespace std;

void print_even_line_star(int N) {
	for(int i=0;i<N;++i) {
		if(i%2==0)
			cout << "*";
		else
			cout << " ";
	}	
}

void print_odd_line_star(int N) {
	for(int i=0;i<N;++i) {
		if(i%2!=0)
			cout << "*";	
		else
			cout << " ";
	}	
}

int main(void)
{
	int N;
	cin >> N;
	
	for(int i=0;i<N;++i) {
		print_even_line_star(N);
		cout << endl;
		print_odd_line_star(N);
		cout << endl;
	}
	
	
	return 0;
}
