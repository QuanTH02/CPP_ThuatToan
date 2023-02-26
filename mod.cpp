#include <iostream>
using namespace std;
const uint64_t m = 1000000007;
uint64_t sqr(uint64_t a)
{
    return a * a;
}
uint64_t mod(uint64_t a, uint64_t b)
{
    if (b == 0)
        return 1 % m;
    else if (b % 2 == 0)
        return sqr(mod(a, b / 2)) % m;
    else
        return a * (sqr(mod(a, b / 2)) % m) % m;
}
uint64_t gtn(uint64_t n, uint64_t k)
{
    uint64_t ans = 1;
    for (int i = n; i > k; i--)
    {
        ans = (ans * i) % m;
    }
    return ans;
}
uint64_t compose(uint64_t k, uint64_t n)
{
    uint64_t s1 = gtn(k, 0);
    uint64_t s2 = gtn(n, n - k);
    uint64_t s3 = mod(s1, m - 2);
    return (s3 * s2) % m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    uint64_t k, n, ans;
    cin >> k >> n;
    if (k > (n - k))
        k = n - k;
    ans = compose(k, n);
    cout << ans;
    return 0;
}