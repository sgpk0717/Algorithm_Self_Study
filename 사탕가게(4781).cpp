// 156ms

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> calory;	// 1������ ����̰� ���� ������ 1���� ������Ű�鼭 Į�θ��� ���. 
vector< int > candy; // ĵ���� ������ ����. �̶� ���ݺ��� ������ �ε����� ����. 
vector<bool> check; // ������ �ε����� ĵ���� ������ ����Ǿ������� üũ���ִ� �迭. 
vector< pair<int,int> > rcandy; // �ߺ� ���ŵ� ĵ��. 

bool compare(const pair<int,int>& p1, const pair<int,int>& p2) {
	return p1.second < p2.second;	
}

void set_list_of_candy(void) {
	for(int i=1;i<=10000;++i)
		if(check[i])
			rcandy.push_back(pair<int,int>(candy[i],i));
	sort(rcandy.begin(),rcandy.end(),compare);
}

void print_calory(int money) {
	for(int i=0;i<=money;++i)
		printf("%d���϶�: %d\n",i,calory[i]); 
	cout << endl;
}

void print_candy(void) {
	for(int i=0;i<rcandy.size();++i) {
		printf("(%d,%d) ",rcandy[i].first,rcandy[i].second);
	}
	cout << endl;
}

void cal_highest_calory(int money) {
	for(int i=1;i<=money;++i) {
		for(int j=0;j<rcandy.size();++j) {
			if(i-rcandy[j].second<0) break;
			calory[i]=max(calory[i],calory[i-rcandy[j].second]+rcandy[j].first);
		}
	}
}

int main(void)
{
	int n,c;
	double m,p;
	int index;
	
	while(cin >> n >> m) {
		if(n==0) break;
		int money = (int)(m*100.00+0.5);
		candy.clear();
		check.clear();
		calory.clear();
		rcandy.clear();
		
		calory.resize(money+1);
		candy.resize(10001);
		check.resize(10001);
		
		for(int i=0;i<n;++i) {
			cin >> c >> p;
			index = (int)(p*100.00+0.5);
			if(!check[index]) {
				check[index]=true;
				candy[index]=c;	
			} else {
				candy[index]=candy[index] < c ? c : candy[index];
			}
		}
		set_list_of_candy();
		//print_candy();
		cal_highest_calory(money);
		//print_calory(money);
		
		cout << calory[money] << endl;
	}
	
	return 0;
}
