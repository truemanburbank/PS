#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 가장 많은 종류의 폰켓몬을 갖고 싶다.
// unordered_set으로 중복을 제거한다.
// min(뽑아야 하는 폰켓몬 수 (n / 2), unordered_set.size())

int solution(vector<int> nums)
{
    unordered_set<int> ponketmon;
    int must = nums.size() / 2; // 뽑아야 하는 폰켓몬 수

    // 중복 제거 
    for (int i = 0; i < nums.size(); i++)
        ponketmon.insert(nums[i]);

    return min(must, (int)ponketmon.size());
}