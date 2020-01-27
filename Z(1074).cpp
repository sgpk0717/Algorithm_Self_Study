#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <cmath>

using namespace std;

typedef pair<long long,long long> pos;

long long where_is_target(pos p, long long size) {
	long long r = p.first, c = p.second;
	long long half_bound = size/2;
	long long bound = half_bound*2;
	
	if(0 <= r && r < half_bound) { // ���� �и��϶�
		if(0 <= c && c < half_bound) // 1��и� 
			return 1;
		else						// 2��и� 
			return 2; 
	}
	if(half_bound <= r && r < bound) { // �Ʒ��� �и��϶� 
		if(0 <= c && c < half_bound) // 3��и� 
			return 3;
		else						// 4��и� 
			return 4; 
	}
}

pos modify_pos(pos p, long long area_number, long long size) {
	long long r = p.first, c = p.second;
	
	switch(area_number) {
		case 1:
			return pos(r, c);
		case 2:
			return pos(r, c-size/2);
		case 3:
			return pos(r-size/2, c);
		case 4:
			return pos(r-size/2, c-size/2);
	}
}

long long add_blocks(long long total_blocks, long long area_number, long long size) {
	switch(area_number) {
		case 1:
			total_blocks += 0 * size*size/4;
			break;
		case 2:
			total_blocks += 1 * size*size/4;
			break;
		case 3:
			total_blocks += 2 * size*size/4;
			break;
		case 4:
			total_blocks += 3 * size*size/4;
			break;
	}
	return total_blocks;
}

long long find_into_4(pos p, long long n) {
	long long area_number;
	long long total_blocks=0;
	int size = pow(2,n);
	
	while(size != 1) { // ��ĭ�� �ɶ����� 
//		cout << "n:\t\t" << n << endl;
		area_number = where_is_target(p, size);	// ���и����� ���ϰ�
	
//		cout << "p:\t\t(" << p.first << ", " << p.second << ")" << endl;
//		cout << "total_blocks:\t" << total_blocks << endl;
//		cout << "area_number:\t" << area_number << endl;
//		cout << "======================================" << endl;
		 
		p = modify_pos(p, area_number, size); 		// ��ǥ �����ϰ� 
		total_blocks = add_blocks(total_blocks,area_number,size); // �� ���ϰ� 		
		size/=2;
	}
	return total_blocks;
}

int main(void)
{
	long long N, R, C;
//	ifstream ifs("1074_2.txt");
//	ifs >> N >> R >> C;
	cin >> N >> R >> C;

	cout << find_into_4( pos(R,C), N ) << endl;

	return 0;
}
