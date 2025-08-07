#include <vector>
#include <iostream>
using namespace std;

// arr의 크기는 최대 100만 --> O(N)으로 풀어야 한다.
// stack으로 pop한 것과 top을 비교해서 중복 제거 
// vector의 pop_back, back은 O(1)이다. stack처럼 사용해 보자.
vector<int> solution(vector<int> arr) 
{
    // stack처럼 사용하기 위해 배열을 뒤집음. 
    vector<int> rv(arr.rbegin(), arr.rend());
    vector<int> answer;
    
    answer.push_back(rv.back());
    rv.pop_back();
    
    while(!rv.empty())
    {
        int next = rv.back();
        rv.pop_back();
        
        if(answer.empty() || answer.back() != next)
            answer.push_back(next);
    }
    
    return answer;
}