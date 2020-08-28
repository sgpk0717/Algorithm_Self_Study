#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check_ascendent(const vector<int>& check) {
    vector<int> temp_check = check;
    sort(temp_check.begin(), temp_check.end());

    for(int i=0;i<check.size();++i) {
        if(temp_check[i]!=check[i]) {
            return false;
        }
    }
    return true;
}

int find_first_index(const string& skill, char c) {
    int index, i;
    for(i=0;i<skill.size();++i) {
        if(skill[i]==c) {
            index = i;
            break;
        }
    }
    if(i==skill.size()) {
        return -1;
    }

    return index;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool flag = false;
    bool flag_2 = false;
    vector<int> skill_check;

    for(int i=0;i<skill_trees.size();++i) {
        skill_check.clear();
        skill_check.resize(skill.size());
        flag = false;
        flag_2 = false;

        for(int j=0;j<skill.size();++j) {
            int first_index = find_first_index(skill_trees[i], skill[j]);
            if(first_index!=-1) {
                if(!flag)
                    skill_check.push_back(first_index);
                else {
                    flag_2 = true;
                    break;
                }
            }
            else {
                flag = true;
            }
        }

        if(!flag_2) {
            if(check_ascendent(skill_check)) {
                ++answer;
            }
        }
    }

    return answer;
}
