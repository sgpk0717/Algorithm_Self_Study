#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current_weight=0;
    vector<int> time_spent(truck_weights.size(), 0);
    queue<int> trucks_on_bridge;
    
    current_weight+=truck_weights[0];
    time_spent[0] = bridge_length+1;
    trucks_on_bridge.push(0);
    
    for(int i=1;i<time_spent.size();++i) {
        if(truck_weights[i]+current_weight <= weight) {     // ���� �÷��� ������ ���ٸ�
            current_weight += truck_weights[i];             // ���� ���ϰ�
            trucks_on_bridge.push(i);                       // �ٸ����� �ø���
            time_spent[i] = time_spent[i-1]+1;              // ������ +1
        }
        else {  // �ø��� �ȵȴٸ�
            int detach_truck_index;
            while(true) {
                detach_truck_index = trucks_on_bridge.front(); 
                trucks_on_bridge.pop();   
                current_weight -= truck_weights[detach_truck_index];
                if(truck_weights[i]+current_weight <= weight)
                    break;
            }
            trucks_on_bridge.push(i);                               // ���� �ø���
            current_weight += truck_weights[i];                     // ���� �ö���³� ���� ���ϰ�
            time_spent[i] = time_spent[detach_truck_index]+bridge_length;   // ���� ����
        }
    }
    answer = time_spent[time_spent.size()-1];
    return answer;
}

int main(void)
{
	vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << solution(2, 4, weights) << endl;
	
	return 0;
}
