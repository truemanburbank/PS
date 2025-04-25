#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// 괄호 쌍 데이터화 
unordered_map<char, char> pairs = { {')', '('}, {']', '['}, {'}', '{'} };

bool IsValid(string &s, int start)
{
    // 괄호 쌍을 찾기 위해 스택 활용
    stack<char> stk;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        // 회전
        char c = s[(start + i) % n];

        // 닫힌 괄호
        if (pairs.count(c))
        {
            // 스택이 비었거나 스택 맨 위가 닫힌 괄호의 쌍과 맞지 않을 때 -> 실패
            if (stk.empty() || stk.top() != pairs[c])
                return false;

            stk.pop();
        }
        // 열린 괄호
        else
        {
            stk.push(c);
        }
    }

    return stk.empty();
}

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        answer += IsValid(s, i);
    }

    return answer;
}