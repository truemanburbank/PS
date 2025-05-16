#include <string>
#include <queue>
#include <vector>

using namespace std;

// 각 카드 뭉치의 front와 필요한 단어를 비교해서 yes or no 리턴
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    queue<string> c1, c2;

    for (string str : cards1) c1.push(str);
    for (string str : cards2) c2.push(str);


    for (int i = 0; i < goal.size(); i++)
    {
        string desire = goal[i];

        if (!c1.empty() && c1.front() == desire)
        {
            c1.pop();
        }
        else if (!c2.empty() && c2.front() == desire)
        {
            c2.pop();
        }
        else
        {
            answer = "No";
            break;
        }
    }

    return answer;
}