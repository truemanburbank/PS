#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 바구니는 stack으로 처리
// 제일 위에 있는 인형을 뽑고, 바구니의 top과 비교해서 같은 인형이면 pop하여 처리.

// 현재 어떤 인형을 뽑았는지 반환
// 뽑은 인형이 없을 경우 0을 반환 
// 인형을 뽑은 다음 배열 원본을 수정해야 하므로 참조
int getItem(vector<vector<int>>& board, int index)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][index] != 0)
        {
            int item = board[i][index];
            board[i][index] = 0;
            return item;
        }
    }

    return 0;
}

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    stack<int> basket;

    for (int move : moves)
    {
        // move번째 칸 제일 위에 있는 인형을 바구니로 옮겨 담기
        int cur = move - 1;
        int item = getItem(board, cur);
        cout << "move: " << move << ", item: " << item << endl;
        if (item > 0)
        {
            // 만약 지금 뽑은 인형이 바구니 최상단 인형과 같은 인형이라면
            if (!basket.empty() && item == basket.top())
            {
                basket.pop();
                answer += 2;
            }
            else
            {
                basket.push(item);
            }
        }
    }

    return answer;
}