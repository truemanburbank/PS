#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 최소 피로도 , 소모 피로도
// 최대한 많은 던전을 탐험하기
// 던전의 개수 최대 1 ~ 8 (매우 작음)

int ans;

void backtracking(int stamina, vector<bool> visited, const vector<vector<int>>& dungeons, int count)
{
    vector<bool> ownVisited(visited);

    // 던전을 들어간 순간 카운팅
    ans = max(ans, count);

    // 던전을 방문하는 모든 조합을 탐색 
    for (int i = 0; i < dungeons.size(); i++)
    {
        int require = dungeons[i][0];
        int use = dungeons[i][1];

        if (require <= stamina && ownVisited[i] == false)
        {
            ownVisited[i] = true;
            backtracking(stamina - use, ownVisited, dungeons, count + 1);
            ownVisited[i] = false;
        }
    }
}


int solution(int k, vector<vector<int>> dungeons) 
{
    vector<bool> visited(dungeons.size(), false);
    backtracking(k, visited, dungeons, 0);

    return ans;
}