#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    // 문제에서 데이터 중복을 허용하지 않고, 저장 데이터를 정렬해야 함.
    // 따라서 set 자료 구조를 사용한다.
    set<int> ret;
    
    // 서로 다른 인덱스에 있는 두 개의 수를 뽑는다.
    // 중복 선택 없이 발생할 수 있는 모든 경우의 수를 찾음.
    // set은 데이터 삽입 시 자동 정렬한다.
    for(int i = 0; i < numbers.size(); i++)
        for(int j = i + 1; j < numbers.size(); j++)
            ret.insert(numbers[i] + numbers[j]);
    
    // vector를 set으로 변환한다.
    vector<int> answer(ret.begin(), ret.end());
    return answer;
}