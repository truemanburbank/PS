#include <string>
#include <iostream>

using namespace std;

// 상 하 좌 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
bool map[11][11][4];

int findIndex(char c)
{
    if (c == 'U') return 0;
    else if (c == 'D') return 1;
    else if (c == 'L') return 2;
    else return 3;
}

// (출발점, 갈 방향)을 기준으로 작성 
int solution(string dirs) {
    int answer = 0;
    pair<int, int> pos = { 5, 5 };

    for (char c : dirs)
    {
        int i = findIndex(c);
        int opposite = i ^ 1;
        int nx = pos.first + dx[i];
        int ny = pos.second + dy[i];

        if (nx < 0 || nx > 10 || ny < 0 || ny > 10) continue;
        if (map[pos.first][pos.second][i] == false && map[nx][ny][opposite] == false)
        {
            answer++;
            map[pos.first][pos.second][i] = true;
            map[nx][ny][opposite] = true;
        }

        pos = { nx, ny };
    }

    return answer;
}