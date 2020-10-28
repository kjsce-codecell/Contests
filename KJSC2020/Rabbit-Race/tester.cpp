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
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll len, s1, s2, h1, h2;
        cin >> len >> s1 >> s2 >> h1 >> h2;
        ll mult = len;
        vl v(len);
        forr(len)
        {
            cin >> v[i];
        }
        ll hop1 = 0, hop2 = 0;
        ll pen1 = 0, pen2 = 0;
        ll win1 = 0, win2 = 0;
        ll dead1 = 0, dead2 = 0;

        if (len == 1){
            cout<<'A'<<' '<<'0'<<endl;
            continue;
        }

        if (v[hop1] == 0)
        {
            pen1++;
            h1 -= 5;
        }
        if (v[hop2] == 0)
        {
            pen2++;
            h2 -= 5;
        }

        while (true)
        {
            if (pen1 > 0)
            {
                pen1--;
            }
            else
            {
                {
                    hop1 += s1;
                    if (v[hop1] == 0)
                    {
                        pen1++;
                        h1 -= 5;
                    }
                    if (hop1 > (mult - 1))
                    {
                        hop1 = mult - 1;
                    }
                    if (hop1 >= (mult - 1))
                    {
                        win1 = 1;
                        break;
                    }
                    if (h1 < 1)
                    {
                        dead1 = 1;
                        break;
                    }
                }
            }

            //////////////
            if (pen2 > 0)
            {
                pen2--;
            }
            else
            {
                {
                    // c2 = 0;
                    hop2 += s2;
                    if (v[hop2] == 0)
                    {
                        pen2++;
                        h2 -= 5;
                        // c2 = 1;
                    }
                    if (hop2 > (mult - 1))
                    {
                        hop2 = mult - 1;
                    }
                    if (hop2 >= (mult - 1))
                    {
                        win2 = 1;
                        break;
                    }
                    if (h2 < 1)
                    {
                        dead2 = 1;
                        break;
                    }
                }
            }
        }

        if (h1 < 1 && (win1 == 0 && win2 == 0))
        {
            cout << 'B' << " " << abs(hop1 - hop2) << endl;
        }
        else if (h2 < 1 && (win1 == 0 && win2 == 0))
        {
            cout << 'A' << " " << abs(hop1 - hop2) << endl;
        }
        if (win1 == 1)
        {
            cout << 'A' << " " << abs(hop1 - hop2) << endl;
        }
        else if (win2 == 1)
        {
            cout << 'B' << " " << abs(hop1 - hop2) << endl;
        }
    }

    return 0;
}