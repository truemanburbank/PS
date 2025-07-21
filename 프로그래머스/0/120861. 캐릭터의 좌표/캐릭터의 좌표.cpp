#include <string>
#include <vector>

using namespace std;

bool OOB(int nx, int ny, int maxX, int maxY)
{
    return nx < 0 || ny < 0 || nx >= maxX || ny >= maxY;
}

// O(N)
//(0, 0)이 중앙일 때 
// 가로 세로는 무조건 홀수 
vector<int> solution(vector<string> keyinput, vector<int> board) 
{
    int xOffset = board[0] / 2;
    int yOffset = board[1] / 2;

    // (0, 0)에 offset 더해서 중앙에서 시작하게 구현
    int x = xOffset;
    int y = yOffset;

    for (string key : keyinput)
    {
        if (key == "left")
        {
            int nx = x - 1;
            int ny = y;
            if (OOB(nx, ny, board[0], board[1])) continue;

            x = nx;
            y = ny;
        }
        else if (key == "right")
        {
            int nx = x + 1;
            int ny = y;
            if (OOB(nx, ny, board[0], board[1])) continue;

            x = nx;
            y = ny;
        }
        else if (key == "up")
        {
            int nx = x;
            int ny = y + 1;
            if (OOB(nx, ny, board[0], board[1])) continue;

            x = nx;
            y = ny;
        }
        else
        {
            int nx = x;
            int ny = y - 1;
            if (OOB(nx, ny, board[0], board[1])) continue;

            x = nx;
            y = ny;
        }
    }

    return {x - xOffset, y - yOffset};
}