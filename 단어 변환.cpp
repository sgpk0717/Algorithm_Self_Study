#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Answer=1000;
vector< vector<int> > differences;

int check_different(string current_word, string target_word) {
    int cnt=0;
    for(int i=0;i<current_word.size();++i) {
        if(current_word[i] != target_word[i]) {
            cnt+=1;
        }
    }
    return cnt;
}
void cal_differences(const vector<string>& words, vector< vector<int> >& differences) {
    int len = words.size();
    
    for(int i=0;i<len;++i) {
        for(int j=i+1;j<len;++j) {
            if(i==j) {
                differences[i][j]=0;
                continue;
            }
            int diff = check_different(words[i],words[j]);
            differences[i][j] = diff;
            differences[j][i] = diff;
        }
    }
}
int find_target_index(string target, const vector<string>& words) {
    for(int i=0;i<words.size();++i) {
        if(target==words[i])
            return i;
    }
    return -1;
}

bool check_all_visit(const vector<bool>& check_visit) {
    for(int i=0;i<check_visit.size();++i) {
        if(check_visit[i]==false)
            return false;
    }
    return true;
}
void DFS(int current_idx, int target_idx, const vector<string>& words, vector<bool>& check_visit, int cnt) {
	cout << "=================================" << endl;
    cout << "current_word: " << words[current_idx] << ", target_word: " << words[target_idx] << endl;
    cout << "cnt: " << cnt << endl;
    if(current_idx == target_idx) {     // Ÿ�� ã������
        cout << "�����ܾ� ã��" << endl;
        
        if(cnt < Answer) {
            cout << "cnt: " << cnt << ", " << "Answer: " << Answer << endl;
            Answer = cnt;
        }
        return;        
    }
    
    for(int i=0;i<words.size();++i) {   // �ܾ��߿���
        cout << "����ܾ�: " << words[current_idx] << endl;
		cout << "Ÿ�ٴܾ�: " << words[i] << endl;
		cout << "��������: " << differences[current_idx][i] << endl;
		cout << "�湮����: " << check_visit[i] << endl << endl;; 
        if(differences[current_idx][i]==1) {   // �Ѱ� ���̳��¾ֵ� �߿���
            if(check_visit[i]!=true) { // �ȹٲ�� �ֵ�� �ٲ�.
                cout << "==> �湮������." << endl;
                check_visit[i]=true;
                DFS(i, target_idx, words, check_visit, cnt+1);   
                check_visit[i]=false;
            }
            else 
            	cout << "==> �湮��." << endl; 
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int target_idx = find_target_index(target, words);
    if(target_idx==-1) {
        cout << "Impossible!" << endl;
        return 0;        
    }
    vector<bool> check_visit(words.size(),false);
    differences.resize(words.size(), vector<int>(words.size(), 0));
    cal_differences(words,differences);
    
    for(int i=0;i<words.size();++i) {
        int diff = check_different(begin, words[i]);
        if(diff!=1) continue;
        
        check_visit.clear();
        check_visit.resize(words.size(),false);
        check_visit[i]=true;
        printf("==========DFS����==========\n");
        DFS(i, target_idx, words, check_visit, 1);
        printf("==========DFS����==========\n");
    }
    
    return Answer;
}

int main(void)
{
	vector<string> words{"hot", "dot", "dog", "lot", "log", "cog"};
	cout << solution("hit", "cog", words) << endl;

	return 0;
}


