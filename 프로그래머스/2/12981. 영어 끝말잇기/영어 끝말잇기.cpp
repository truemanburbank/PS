#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// 신경 써야 할 것 - > return {사람 번호, 몇 번째 턴}
// 1. 현재 지금이 몇 번째 턴인지
// 2. 아무도 탈락하지 않을 때 예외
// 3. 끝말잇기를 제대로 안 했을 때 

// map (단어 - bool) 로 현재 단어 사용했는지 확인?

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, bool> isUsed;
    int phase = 1; 
    auto prevLast = words[0].rbegin();
    isUsed[words[0]] = true;

    for (int i = 1; i < words.size(); i++)
    {
        // 몇 번째 사람 차례인지
        int who = i % n + 1;

        // 몇 번째 턴인지
        bool isNewPhase = i % n == 0;

        // 첫 번째 글자
        auto curFirst = words[i].begin();

        // 몇 번째 턴인지
        if (isNewPhase) phase++;

        // 올바른 단어를 말했는가
        if (*prevLast != *curFirst || isUsed[words[i]])
        {
            answer.push_back(who);
            answer.push_back(phase);
            return answer;
        }

        // 단어 사용 처리 
        prevLast = words[i].rbegin();
        isUsed[words[i]] = true;
    }

    answer.push_back(0);
    answer.push_back(0);

    return answer;
}