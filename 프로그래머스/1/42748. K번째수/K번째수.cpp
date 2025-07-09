#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 배열을 commands[0] - 1 ~ commands[1] - 1까지 자른 후 정렬
// 이후 commands[2] 번째 수 반환
vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> tmp(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[i][2] - 1]);
    }

    return answer;
}