#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 토핑 길이 최대 백만

//철수한테 토핑 다 몰아준 후, 차례대로 동생한테 하나씩 줘본다.
// 크기 비교 후 카운트 증가 
int solution(vector<int> topping) 
{
    unordered_map<int, int> left;   // 철수
    unordered_map<int, int> right;  // 동생
    int answer = 0;

    // 전체 토핑 종류 수 계산
    for (int t: topping)
        left[t]++;

    // 일일이 나눠보기
    for (int t : topping)
    {
        // 동생이 토핑 추가
        right[t]++;

        // 철수 토핑에서 동생이 가져간것 제거
        if (--left[t] == 0)
            left.erase(t); // unordered_map.erase(): 대부분의 경우 O(1)

        if (left.size() == right.size())
            answer++;
    }

    return answer;
}