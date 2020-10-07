#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Answer;

void print_expression(const vector<int>& numbers, const vector<int>& symbols) {
    int sum=0;
    for(int i=0;i<numbers.size();++i) {
        sum+=symbols[i]*numbers[i];
        if(symbols[i]==1) {
            printf("+");
        }
        else {
            printf("-");
        }
        printf("%d",numbers[i]);
    }
    cout << " = " << sum << endl;
}

void recursive(const vector<int>& numbers, vector<int> symbols, int index, int target) {
    if(index==numbers.size()) {
        int sum=0;
        for(int i=0;i<numbers.size();++i) {            
            sum+=symbols[i]*numbers[i];
        }
        if(sum==target) {
            print_expression(numbers, symbols);
            Answer++;
        }
        return;
    }
    
    symbols[index]=-1;
    recursive(numbers, symbols, index+1, target);
    symbols[index]=1;
    recursive(numbers, symbols, index+1, target);
  
    return;
}

int solution(vector<int> numbers, int target) {
    vector<int> symbols(numbers.size(),0);
    recursive(numbers, symbols, 0, target);
    
    
    return Answer;
}

int main(void)
{
	int target = 36;
	vector<int> numbers = {1, 1, 1, 3, 4, 2, 5, 1, 2, 6, 4, 6, 7, 1, 8, 6, 10, 24, 16, 24, 12, 33, 12, 41, 15, 3, 6, 8, 4, 14, 46, 7, 9, 37}
	solution(


	return 0;
}
