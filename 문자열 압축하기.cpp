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

/* ���ڷ� RLE ���� */ 
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

/* ���ڿ��� �̿��� RLC */ 
string str_RLE(string plain, int iii) 
{
	for(int i=iii;i<plain.size();++i) {
		
		char target = plain[i];
		if(target=='(' || target==')') {
			continue;
		}
		
		int j; 
	
		/* ��ǥ���ڿ� ���� ù��° ���ڸ� ã�� */ 
		for(j=i+1;j<plain.size();++j) {
			if(plain[j] == target) {
				/* ã�Ҵµ� 1ĭ���̸� */
				if(j==i+1) {
					int k;
					
					for(k=j+1; k<plain.size() && plain[k]==target; ++k);
				
					/* ������ �� ��ȿ���� */	
					if(k-i<4){  continue; }
				
		
					/* ���� */ 
					plain.replace(i,k-i,int_to_string(k-i)+"("+plain[i]+")");
		
					continue;
				}
				
				/* i�� j���� ������ �ݺ��Ǵ��� �˻� */
				if(is_repeated(plain, plain.substr(i,j-i), i, j)) { // �ݺ��ɶ�  
					int number = get_repeated_time(plain, 
												plain.substr(i,j-i),i,j); // ��� �ݺ��Ǵ���  
					
					if(is_efficient(plain,j-i,number)) { // replace�� ȿ�����϶� 
						
						/* ���� */ 
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
