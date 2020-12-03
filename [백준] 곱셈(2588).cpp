#include <iostream>

using namespace std;

int multiply(int multiplicator, int multiplier) {
	int return_value=0;
	int print_value;
	
	for(int i=1;multiplier>0;i*=10) {
		print_value = multiplicator*(multiplier%10);
		printf("%d\n",print_value);
		
		return_value += print_value*i;
		
		multiplier/=10;	
	}
	
	return return_value; 
}

int main(void)
{
	int multiplicator, multiplier;
	
	cin >> multiplicator >> multiplier;
	
	cout << multiply(multiplicator, multiplier) << endl;	
	
	return 0;
}
