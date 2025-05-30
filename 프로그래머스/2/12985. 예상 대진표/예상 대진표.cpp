#include <iostream>

using namespace std;

// a와 b가 몇 번째 라운드에서 만나는지 -> 번호를 다시 배부받았을 때 2n과 2n + 1인지
// (1, 2), (3, 4) (5, 6) (7, 8)... 
// 1 (2) //  3 (4)

int solution(int n, int a, int b)
{
    int answer = 0;

    // 두 숫자가 같다는 것은 이미 한판 떴다는 의미
    while (a != b)
    {
        // 만약 a가 1이라면, (1 + 1) / 2 ==> 1
        // 만약 b가 4라면, (4 + 1) / 2 ==> 2
        a = (a + 1) / 2;
        b = (b + 1) / 2;

        answer++;
    }

    return answer;
}