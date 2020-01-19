#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string int_to_string(int i)
{
	stringstream ss;
	ss << i;
	return ss.str();	
}

/* 문자로 RLE 압축 */ 
string char_RLE(string plain) 
{
	char c;
	int cnt;
	string cypher;	
	
	for(int i=0;i<plain.size();++i) {
		cnt = 1;
		c = plain[i];
		cypher += c;
		
		for(int j=i+1;j<plain.size() && plain[j]==c;++j) {
			++cnt;
			++i;
		}
		if( cnt > 1 ) {
			cypher += int_to_string(cnt);
		}
	}
	
	return cypher;
}
bool is_repeated(string plain, string substr, int index1, int index2)
{
	if(index2+(index2-index1)>plain.size()) return false;
	
	if(plain.substr(index2,index2-index1) == substr)
		return true;
	return false;
}

int get_repeated_time(string plain, string substr, int index1, int index2) 
{
	int size = index2-index1;
	int i;
	for(i=index2+size;i<plain.size() && plain[i]==plain[index1];i+=size) {
		if(i+size>plain.size()) break;
		if(plain.substr(i,size) != substr) {
			break;
		}				
	}
	
	return (i-index1)/size;
}

bool is_efficient(string plain, int size, int number)
{
	int remove = size*(number-1);
	int add = 3;
	return remove >= add;	
}

/* 문자열을 이용한 RLC */ 
string str_RLE(string plain, int iii) 
{
	for(int i=iii;i<plain.size();++i) {
		
		char target = plain[i];
		if(target=='(' || target==')') {
			continue;
		}
		
		int j; 
	
		/* 목표문자와 같은 첫번째 문자를 찾음 */ 
		for(j=i+1;j<plain.size();++j) {
			if(plain[j] == target) {
				/* 찾았는데 1칸차이면 */
				if(j==i+1) {
					int k;
					
					for(k=j+1; k<plain.size() && plain[k]==target; ++k);
				
					/* 압축이 더 비효율적 */	
					if(k-i<4){  continue; }
				
		
					/* 압축 */ 
					plain.replace(i,k-i,int_to_string(k-i)+"("+plain[i]+")");
		
					continue;
				}
				
				/* i와 j에서 패턴이 반복되는지 검사 */
				if(is_repeated(plain, plain.substr(i,j-i), i, j)) { // 반복될때  
					int number = get_repeated_time(plain, 
												plain.substr(i,j-i),i,j); // 몇번 반복되는지  
					
					if(is_efficient(plain,j-i,number)) { // replace가 효율적일때 
						
						/* 압축 */ 
						plain.replace(i, (j-i)*number, 
									int_to_string(number)+"("+plain.substr(i,j-i)+")"); 
						continue; 
					}
	
	
				}
	
		
			}
		}
		
	
	}
	
	return plain;	
}

int main(void)
{
	string plain;
	
	cin >> plain;
	
	
	cout << min(str_RLE(plain,0).size(), str_RLE(plain,1).size()) << endl; 
	return 0;
}
