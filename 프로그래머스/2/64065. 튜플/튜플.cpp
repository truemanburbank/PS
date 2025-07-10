#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// {{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}} == (2, 1, 3, 4)
// 1개 -> 1번째 원소 있음
// 2개 -> 2번째 원소 있음
// 3개 -> 3번째 원소 있음 ...
// s는 최대 100만. s의 원소는 최대 10만. 자연수만 표현
// 계수 정렬을 통해 쉽게 풀 수 있다.
int counting[100001];

vector<int> solution(string s) 
{
    vector<int> answer;
    vector<pair<int, int>> numbers;
    string number;

    // 문자열에서 숫자를 뽑아 카운팅
    for (char c : s)
    {
        if (isdigit(c))
        {
            number += c;
        }
        else
        {
            if (!number.empty())
            {
                counting[stoi(number)]++;
                number.clear();
            }
        }
    }

    // 한 번이라도 나온 숫자는 배열에 저장
    // numbers 배열에 개수, 숫자 저장
    for (int i = 0; i < 100001; i++)
    {
        if (counting[i] > 0)
            numbers.push_back({ counting[i], i });
    }

    // 개수를 기준으로 내림차 순 정렬
    // 많이 나올수록 튜플의 앞에 위치
    sort(numbers.rbegin(), numbers.rend());

    for (auto& p : numbers)
        answer.push_back(p.second);

    return answer;
}