#include <iostream>
#include <vector> 
#include <string>

using namespace std;

vector< vector<int> > cogwheels;
vector<bool> check_rotate;

void print_cogwheels(void) {
	for(int i=0;i<4;++i) {
		for(int j=0;j<8;++j) {
			cout << cogwheels[i][j];
		}
		cout << endl;	
	}
}

int get_result(void) {
	int sum=0;
	
	for(int i=3;i>=0;--i) {
		sum*=2;
		if(cogwheels[i][0]==1) sum+=1;
	}
	return sum;
}

void rotation(int cw_num, int direction) {
	int cw_index = cw_num-1;
	check_rotate[cw_index]=true;
	
	int cog_2 = cogwheels[cw_index][2];	
	int cog_6 = cogwheels[cw_index][6];
	
	if(direction==1) {
		cogwheels[cw_index].insert(cogwheels[cw_index].begin(),cogwheels[cw_index][7]);
		cogwheels[cw_index].pop_back();
	}
	else {	
		cogwheels[cw_index].push_back(cogwheels[cw_index][0]);
		cogwheels[cw_index].erase(cogwheels[cw_index].begin());
	}
	
	if(cw_index!=0) {
		int left_cog_2 = cogwheels[cw_index-1][2];
		if(left_cog_2 != cog_6 && !check_rotate[cw_index-1]) rotation(cw_num-1, direction*(-1));		
	}
	if(cw_index!=3) {
		int right_cog_6 = cogwheels[cw_index+1][6];
		if(right_cog_6 != cog_2 && !check_rotate[cw_index+1]) rotation(cw_num+1, direction*(-1));		
	}
}

int main(void)
{
	int K;
	int cw_num, direction;
	cogwheels.resize(4);
	for(int i=0;i<4;++i) {
		string temp;
		cin >> temp;
		for(int j=0;j<8;++j) {	
			cogwheels[i].push_back(temp[j]-'0');
		}
	}
	cin >> K;
	for(int i=0;i<K;++i) {
		cin >> cw_num >> direction;
		check_rotate.clear();
		check_rotate.resize(4,false);
		rotation(cw_num, direction);
//		print_cogwheels();
	}
	
	cout << get_result() << endl;
	
	return 0;
}
