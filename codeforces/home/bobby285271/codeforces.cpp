#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

#define endl '\n'
#define pb push_back
#define fir first
#define sec second

template <class T>
void _read(T &x)
{
    cin >> x;
}
void _read(int &x) { scanf("%d", &x); }
void _read(ll &x) { scanf("%lld", &x); }
void _read(float &x) { scanf("%f", &x); }
void _read(double &x) { scanf("%lf", &x); }
void _read(char &x) { x = getchar(); }
void _read(char *x) { scanf("%s", x); }
template <class T, class U>
void _read(pair<T, U> &x)
{
    _read(x.first);
    _read(x.second);
}
void read() {}
template <class T, class... U>
void read(T &head, U &... tail)
{
    _read(head);
    read(tail...);
}

template <class T>
void _write(const T &x) { cout << x << " "; }
void _write(const int &x) { printf("%d ", x); }
void _write(const ll &x) { printf("%lld ", x); }
void _write(const float &x) { printf("%.6f ", x); }
void _write(const double &x) { printf("%.8lf ", x); }
void _write(const char &x)
{
    putchar(x);
    if (x != '\n')
        putchar(' ');
}
void _write(const char *x) { printf("%s ", x); }
template <class T, class U>
void _write(const pair<T, U> &x)
{
    _write(x.first);
    _write(x.second);
}
template <class T>
void _write(const vector<T> &x)
{
    for (auto i = x.begin(); i != x.end(); _write(*i++))
        ;
}
void write() {}
template <class T, class... U>
void write(const T &head, const U &... tail)
{
    _write(head);
    write(tail...);
}
ll TESTCASE_NUM = 1;
inline ll qpow(ll x, ll n, ll m)
{
    ll res = 0;
    while (n)
    {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}
inline void fastio()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}

void solve();
signed main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    read(TESTCASE_NUM);
    while (TESTCASE_NUM--)
        solve();
}

//////// Solution Below ////////

ll a, b;
void solve()
{
    read(a, b);
    write(a + b, endl);
}
