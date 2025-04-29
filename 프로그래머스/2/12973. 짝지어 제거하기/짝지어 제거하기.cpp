#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stk;

    // 문자 차례대로 확인
    for (char c : s)
    {
        // 스택이 비어있지 않고, 스택의 top이 현재 문자와 같으면
        if (!stk.empty() && stk.top() == c)
        {
            stk.pop();
        }
        // 스택이 비어있거나, 스택의 top이 현재 문자와 다르면
        else
        {
            stk.push(c);
        }
    }

    // 스택이 비어있으면 짝지어 제거하기 성공 
    if (stk.empty())
        answer = 1;
    else
        answer = 0;

    return answer;
}