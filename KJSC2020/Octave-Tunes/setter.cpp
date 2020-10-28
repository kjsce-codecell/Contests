#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pii;
#define endl "\n"
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define FF first
#define SS second
#define ll long long
#define ull unsigned long long
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define forr(k) for (int i = 0; i < k; i += 1)
#define For(j, k) for (int i = j; i < k; i += 1)
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                             \
    freopen("input6.txt", "r", stdin); \
    freopen("output6.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    FIO;
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, temp;
        ll min = 1000000000;
        cin >> n;
        ll count = 0;
        map<int, ll> m;

        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            m[temp]++;
        }
        for (auto &k : m)
        {
            count++;
            if (k.second < min)
            {
                min = k.second;
            }
        }
        if (count < 8)
        {
            cout << 0 << endl;
        }
        else
            cout << min << endl;
    }
    return 0;
}
