using namespace std;

// 순간이동 시 생기는 비용은 0이다.
// 따라서 N을 몫이 0이 될 때까지 2로 나눔.
// 나머지가 생길 때마다 count + 1

int solution(int n)
{
    int ans = 0;

	while (n != 0)
	{
		int r = n % 2;
		n /= 2;

		if (r == 1)
			ans++;
	}

    return ans;
}