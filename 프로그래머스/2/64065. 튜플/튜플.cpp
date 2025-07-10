#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// {{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}} == (2, 1, 3, 4)
// 1개 -> 1번째 원소 있음
// 2개 -> 2번째 원소 있음
// 3개 -> 3번째 원소 있음 ...
// s는 최대 100만. s의 원소는 최대 10만. 자연수만 표현

bool isUsed[100001];

bool cmp(string a, string b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) 
{
    // 문자열을 1차원 배열 형태로 받아오기, s 크기 오름차 순으로 정렬 slogs
    // s*500를 돌면서 새로 들어오는 것을 answer에 추가?
    vector<int> answer;
    vector<string> vec;

    string number = "";
    bool isNext = false;

    // 문자열을 배열로 변환
    for (char c : s)
    {
        if (c == '{')
        {
            isNext = false;
        }
        else if (c == '}')
        {
            if (number == "") continue;
            vec.push_back(number);
            isNext = true;
            number = "";
        }
        else if (c == ',')
        {
            if(isNext == false)
                number += c;
        }
        else
        {
            number += c;
        }
    }

    // 집합 크기 순으로 정렬 
    sort(vec.begin(), vec.end(), cmp);

    // answer에 추가
    for (string set : vec)
    {
        string number = "";
        for (char c : set)
        {
            if (c == ',')
            {
                int n = stoi(number);
                if (isUsed[n] == false)
                {
                    isUsed[n] = true;
                    answer.push_back(n);
                }
                number = "";
            }
            else
            {
                number += c;
            }
        }

        if (number != "")
        {
            int n = stoi(number);
            if (isUsed[n] == false)
            {
                isUsed[n] = true;
                answer.push_back(n);
            }
            number = "";
        }
    }

    return answer;
}

int main()
{
    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
}