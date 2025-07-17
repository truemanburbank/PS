#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 카펫의 가로 세로 크기를 반환. 

// 이차방정식으로 풀이 (문제의 조건에서, w>=h이므로 하나의 답 선택 가능)
// 관련식
// 전체 카펫의 가로, 높이를 w, h라 할 때. 
// 1. w * h (노란 영역 + 갈색 영역)
// 2. (w - 2) + (h - 2) ((갈색 영역 - 4) / 2) [w - 2, h - 2는 노랑 영역의 w', h'이다.]
// --- w + h = ((갈색 영역 - 4) / 2) + 4
// 위 두 식을 이용하여 이차방정식을 풀고 w, h를 구하자.
// 두 근의 합, 두 근의 곱이 있으면 이차방정식을 바로 작성 가능 

vector<int> solution(int brown, int yellow)
{
    // 두 근의 합
    int b = (-1) * (((brown - 4) / 2) + 4);

    // 두 근의 곱
    int c = brown + yellow;

    // ax^2 + bx + c 식의 근의 공식 루트 부분
    // a = 1
    int sqrtD = sqrt(b * b - 4 * c);

    // 문제에서 w >= h이므로.
    int w = ((-1) * b + sqrtD) / 2;
    int h = ((-1) * b - sqrtD) / 2;
    
    return { w, h };
}