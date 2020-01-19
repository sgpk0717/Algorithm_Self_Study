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
	cout << "is Repeated?" << endl;
	cout << index1 << ", " << index2 << ", " << substr << endl;
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
	
	cout << (i-index1)/size << " repeated." << endl;
	return (i-index1)/size;
}

bool is_efficient(string plain, int size, int number)
{
	int remove = size*(number-1);
	int add = 3;
	return remove >= add;	
}

/* ���ڿ��� �̿��� RLC */ 
string str_RLE(string plain) 
{
	for(int i=0;i<plain.size();++i) {
		cout << "===========================" << endl;
		
		char target = plain[i];
		cout << "target: " << target << endl;
		if(target=='(' || target==')') {
			cout << "Invalid target." << endl;
			continue;
		}
		
		int j; 
	
		/* ��ǥ���ڿ� ���� ù��° ���ڸ� ã�� */ 
		for(j=i+1;j<plain.size();++j) {
			if(plain[j] == target) {
				/* ã�Ҵµ� 1ĭ���̸� */
				if(j==i+1) {
					cout << "1 repeated. "; 
					int k;
					
					for(k=j+1; k<plain.size() && plain[k]==target; ++k);
				
					/* ������ �� ��ȿ���� */	
					if(k-i<4){ cout << "But inefficient." << endl; continue; }
				
					/* �����ϴ°� ���� �̻��϶� */ 
					cout << k-i << "times." << endl;
					cout << plain << " ==> ";
					
					/* ���� */ 
					plain.replace(i,k-i,int_to_string(k-i)+"("+plain[i]+")");
					cout << plain << endl;
					
					continue;
				}
				
				/* i�� j���� ������ �ݺ��Ǵ��� �˻� */
				if(is_repeated(plain, plain.substr(i,j-i), i, j)) { // �ݺ��ɶ�  
					cout << "Repeat." << endl;
					cout << plain.substr(i,j-i) << endl;
					int number = get_repeated_time(plain, 
												plain.substr(i,j-i),i,j); // ��� �ݺ��Ǵ���  
					
					if(is_efficient(plain,j-i,number)) { // replace�� ȿ�����϶� 
						cout << "replace is efficient." << endl;
						
						/* ���� */ 
						cout << plain << " ==> ";
						plain.replace(i, (j-i)*number, 
									int_to_string(number)+"("+plain.substr(i,j-i)+")"); 
						cout << plain << endl;
						continue; 
					}
					else { // replace ���ϴ°� ������ 
						cout << "replace is inefficient." << endl;
						
					}
					
					for(int n=i, m=j; n<j; ++n,++m) {
						cout << plain[n] << "||" << plain[m] << endl;
					}
				}
				else { // �ݺ����� ������  
					cout << "No repeat." << endl; 	
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
	
	string char_after = char_RLE(plain);
	string str_after = str_RLE(plain);
	
	cout << "==========Final==========" << endl;

	cout << "<���ڿ� ��>" << endl; 
	cout << "���� ���ڿ�\t: " << plain << endl;
	cout << "char ������\t: " << char_after << endl;
	cout << "str ������\t: " << str_after << endl;
	
	cout << endl;
	cout << "<���� ��>" << endl;
	cout << "���� ���ڿ�\t: " << plain.size() << endl;
	cout << "char ������\t: " << char_after.size() << endl;
	cout << "str ������\t: " << str_after.size() << endl;

	cout << endl;
	cout << "�� ª�� ���� ==> " << min(char_after.size(),str_after.size()) << endl; 
	return 0;
}
