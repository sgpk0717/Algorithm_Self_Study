#include <iostream>
#include <cstring>

using namespace std;

int Answer;
bool flag_char;

string remove_space(string input)
{
	if(input[0]==' ')
		input[0]='a';	
	if(input[input.size()-1]==' ')
		input[input.size()-1]='a';
	
	return input;
}

int main(void)
{
	string input;
	getline(cin, input);

	input = remove_space(input);

	for(int i=0;i<input.size();++i) {
		if( flag_char == 0 && input[i] != ' ') {
			flag_char = 1;
			Answer++;
		}
		else if( flag_char == 1 && input[i] == ' ') {
			flag_char = 0;	
		}
			
	}
	
	cout << Answer << endl;
	
		
	return 0;
}
