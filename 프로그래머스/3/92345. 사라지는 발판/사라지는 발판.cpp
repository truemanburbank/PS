#include <string>
#include <vector>
#include <climits>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

// Minimax + backtracking

// 현재 플레이어가 이겼는지 여부와 turn 수 반환
pair<int, int> backtraking(vector<vector<int>>& board, int ax, int ay, int bx, int by)
{
    // 현재 밟고 있는 발판이 사라졌으면 짐
    if (board[ax][ay] == 0)
        return { false, 0 };

    bool canMove = false;
    int minTurn = INT_MAX;  // 이길 때 최소 턴
    int maxTurn = 0;        // 질 때 최대 턴

    for (int i = 0; i < 4; i++)
    {
        int nax = ax + dx[i];
        int nay = ay + dy[i];

        if (nax < 0 || nay < 0 || nax >= board.size() || nay >= board[0].size()) continue;
        if (board[nax][nay] == 0) continue;

        canMove = true;
        board[ax][ay] = 0; // nax, nay를 밟을 것이므로 현재 발판은 끔

        // 상대방
        auto [win, turn] = backtraking(board, bx, by, nax, nay);

        board[ax][ay] = 1; // 복구

        // 한 번이라도 이길 수 있으면 무조건 이긴다.
        if (win == false) // 상대방이 짐
        {
            minTurn = min(minTurn, turn + 1);
        }
        else // 내가 진다면 최대한 끌어야 한다. 
        {
            maxTurn = max(maxTurn, turn + 1);
        }
    }

    // 한번도 움직이지 못함 -> 졌음
    if (canMove == false)
        return { false, 0 };

    // 한 번이라도 이겼다면
    if (minTurn != INT_MAX)
        return { true, minTurn };
    else
        return { false, maxTurn };
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) 
{
    return backtraking(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}