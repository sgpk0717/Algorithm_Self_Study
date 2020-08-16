#include <iostream>

using namespace std;

int main(void)
{
	int burger;
	int cheapest_burger = 2100;
	
	for(int i=0;i<3;++i) {
		cin >> burger;
		if(burger < cheapest_burger)
			cheapest_burger = burger;	
	}
	
	int beverage;
	int cheapest_beverage = 2100;
	
	for(int i=0;i<2;++i) {
		cin >> beverage;
		if(beverage < cheapest_beverage)
			cheapest_beverage = beverage;	
	}
	
	cout << cheapest_burger + cheapest_beverage - 50 << endl;
	
	return 0;
}
