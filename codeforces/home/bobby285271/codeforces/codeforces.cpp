#if 0
        clear
        g++ -std=c++17 -O2 -Wall -lm "$0" && time ./a.out
        exit
#endif
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define _USE_MATH_DEFINES
#define endl '\n'
#define pb push_back
#define fir first
#define sec second
#define umap unordered_map
#define mp make_pair
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
long long TESTCASE_NUM = 1;
long long TESTCASE_CUR = 0;
template <typename T>
inline void _read(T &x) { cin >> x; }
inline void _read(int &x) { scanf("%d", &x); }
inline void _read(long long &x) { scanf("%lld", &x); }
inline void _read(float &x) { scanf("%f", &x); }
inline void _read(double &x) { scanf("%lf", &x); }
inline void _read(char &x) { x = getchar(); }
inline void _read(char *x) { scanf("%s", x); }
inline void read() {}
template <typename T, typename... U>
inline void read(T &head, U &...tail)
{
    _read(head);
    read(tail...);
}
template <typename T>
inline void _write(const T &x) { cout << x; }
inline void _write(const int &x) { printf("%d", x); }
inline void _write(const long long &x) { printf("%lld", x); }
inline void _write(const float &x) { printf("%.6f", x); }
inline void _write(const double &x) { printf("%.8lf", x); }
inline void _write(const char &x) { putchar(x); }
inline void _write(const char *x) { printf("%s", x); }
inline void write() {}
template <typename T, typename... U>
inline void write(const T &head, const U &...tail)
{
    _write(head);
    write(tail...);
}
inline void debug() {}
#ifdef _USE_DEBUG
template <typename T, typename... U>
inline void debug(const T &head, const U &...tail)
{
    _write("\033[1m\033[33m\33[4m");
    write(head, tail...);
    _write("\033[0m");
    // system("sleep 1");
    fflush(stdout);
}
#else
template <typename T, typename... U>
inline void debug(const T &head, const U &...tail)
{
}
#endif
template <typename T>
inline bool isprime(T p)
{
    if (p == 2 || p == 3)
        return 1;
    if (p < 2 || (p % 6 != 1 && p % 6 != 5))
        return 0;
    for (T i = 5; i * i <= p; i = i + 6)
        if (p % i == 0 || p % (i + 2) == 0)
            return 0;
    return 1;
}
template <typename T1, typename T2, typename T3>
inline T1 qpow(T1 a, T2 b, T3 m)
{
    T1 ans = 1, base = a;
    while (b)
    {
        if (b & 1)
            ans = ans * base % m;
        base = base * base % m;
        b >>= 1;
    }
    return ans;
}
template <typename T1, typename T2>
inline T1 qpow(T1 a, T2 b)
{
    T1 ans = 1, base = a;
    while (b)
    {
        if (b & 1)
            ans = ans * base;
        base = base * base;
        b >>= 1;
    }
    return ans;
}

template <typename T1, typename T2>
inline T1 inv(T1 i, T2 m) { return qpow(i, m - 2, m); }
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) { return a < b ? b : a; }
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) { return a < b ? a : b; }

ll C(ll n, ll m, ll p)
{
    if (m > n)
        return 0;
    ll up = 1, down = 1;
    for (int i = n - m + 1; i <= n; i++)
        up = up * i % p;
    for (int i = 1; i <= m; i++)
        down = down * i % p;
    return up * inv(down, p) % p;
}

ll Lucas(ll n, ll m, ll p)
{
    if (m == 0)
        return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

void read(__int128 &_ret)
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch) && ch != '-')
        ch = getchar();
    if (ch == '-')
        f = -1;
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    _ret = f * x;
}
void write(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

void solve();
void init();

signed main()
{
#ifdef _USE_FILEIO
    freopen("in1.txt", "r", stdin);
    // freopen("ans1.txt", "w", stdout);
#endif
    // scanf("%lld\n", &TESTCASE_NUM);
    init();
    while (TESTCASE_CUR++ < TESTCASE_NUM)
    {
        // printf("Case #%lld: ", TESTCASE_CUR);
        solve();
    }
    return 0;
}

// 今天你认真读题了吗？o(≧口≦)o

const int MAXN = 2e5 + 10;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

void init() {}

void solve()
{
}
