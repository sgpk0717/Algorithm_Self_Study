#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> nums;
long long Answer;

int get_max_idx(void) {
	int max_v=0;
	int max_i=-1;
	for(int i=0;i<nums.size();++i) {	
		if(nums[i]>max_v) {
			max_v = nums[i];
			max_i = i;
		}
	}
	
	return max_i;
}

int powering(int x, int k) {
	int retv=1;
	for(int i=0;i<k;++i) 	
		retv*=x;
	return retv;
}

int main(void)
{
	int n, k, x;
	cin >> n >> k >> x;
	
	nums.resize(n);
	for(int i=0;i<n;++i) 
		cin >> nums[i];
		
	int max_idx = get_max_idx();
	
	nums[max_idx]=nums[max_idx]*powering(x,k);
	
	for(int i=0;i<nums.size();++i) {
		Answer|=nums[i];
	}
	
	cout << Answer << endl;
	
	return 0;
}
