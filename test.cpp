#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

int main(void)
{
   string word;
   getline(cin,word);   
   
   transform(word.begin(),word.end(),word.begin(),::tolower);
   sort(word.begin(), word.end());
	cout << word << endl;
   bool is_question = false;
   
   for(string::iterator it=word.begin();it!=word.end()-1;++it){
      // ó�� 
   }
   
   

	return 0;
}
