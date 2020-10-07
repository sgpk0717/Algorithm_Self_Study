#include <iostream>

using namespace std;

int main(void)
{
	double x, y;
	cin >> x >> y;
	if(y>x) {
		cout << -1 << endl;
		return 0;	
	}
	double mid = (x+y)/2;
	
	double height = mid;
	int i;
	for(i=2;height/i>=y;++i);	
	double point_y = height/(i-1);
	
	printf("%.12lf\n",point_y);
	
	return 0;
}
