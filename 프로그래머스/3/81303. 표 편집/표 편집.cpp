#include <string>
#include <vector>
#include <stack> 
using namespace std;

// n이 100만 
// 삭제 -> 스택 push, (가장 최근)복구 -> 스택 pop 

// 커맨드 실행 시 while문으로 가리키는 항목이 삭제되었는지 일일이 확인 X
// 100만 * 20만은 시간 초과

// 삭제된 것을 어떻게 효율적으로 확인하는가? 
// 연결리스트 방법으로!

string solution(int n, int k, vector<string> cmd)
{
    vector<int> prev(n);
    vector<int> next(n);
    stack<int> deleted;

    for (int i = 0; i < n; i++)
    {
        prev[i] = i - 1;
        next[i] = i + 1;
    }

    int cur = k;

    // 명령어 뒤 U 12와 같이 두자리수가 올 수 있으므로
    // str[2] 같은 방식이 아닌 str.substr(0, 2)로 문자열을 잘라 처리
    for (string str : cmd)
    {
        if (str[0] == 'C')
        {
            deleted.push(cur);

            // 연결리스트 방식
            if (prev[cur] != -1) next[prev[cur]] = next[cur];
            if (next[cur] != n) prev[next[cur]] = prev[cur];

            // 현재 가리키는 행이 마지막인지 여부에 따라
            // 이전 행을 가리킬 것인가, 다음 행을 가리킬 것인가 처리
            cur = (next[cur] == n) ? prev[cur] : next[cur];
        }
        else if (str[0] == 'Z')
        {
            int restore = deleted.top();
            deleted.pop();

            // 연결리스트 방식
            if (prev[restore] != -1) next[prev[restore]] = restore;
            if (next[restore] != n) prev[next[restore]] = restore;
        }
        else if (str[0] == 'U')
        {
            for (int i = 0; i < stoi(str.substr(2)); i++)
                cur = prev[cur];
        }
        // D
        else
        {
            for (int i = 0; i < stoi(str.substr(2)); i++)
                cur = next[cur];
        }
    }

    string answer(n, 'O');

    // 현재 stack에 납아 있는 것만 삭제된 것임
    while (!deleted.empty())
    {
        answer[deleted.top()] = 'X';
        deleted.pop();
    }

    return answer;
}