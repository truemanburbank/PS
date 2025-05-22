#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> peopleByName;

    // "사람 - 명" 의 표를 만든다.
    for (string name : participant)
    {
        peopleByName[name]++;
    }
    
    // 도착자 수를 표에서 차감한다.
    for (string name : completion)
    {
        peopleByName[name]--;
    }

    // 1명 이상 남아 있는 경우 완주하지 못한 선수이다.
    for (string name : participant)
    {
        if (peopleByName[name] > 0)
            answer = name;
    }

    return answer;
}