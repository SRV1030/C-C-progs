#include <bits/stdc++.h>
#define ll long long
#define li long long int
#define lp(i, a, b) for (li i = a; i < b; i++)
using namespace std;
vector<li> Pr;
bool isPrime(ll n)
{
    if (n <= 1)
        return false;

    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
void SieveOfEratosthenes(li n)
{
    vector<li> prime;
    lp(i, 0, n) prime.push_back(0);
    for (li p = 2; p * p <= n; p++)
    {
        if (prime[p] == 0)
        {

            for (li i = p * p; i <= n; i += p)
                prime[i] = 1;
        }
    }

    for (li p = 2; p <= n; p++)
        if (!prime[p])
            Pr.push_back(p);
}
void solve()
{
    li x, y;
    cin >> x >> y;
    vector<li>::iterator i, j;
    i = lower_bound(Pr.begin(), Pr.end(), x);
    j = lower_bound(Pr.begin(), Pr.end(), y);
    cout << Pr[i - Pr.begin()] - Pr[j - Pr.begin()] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x, y;
    cin >> x >> y;
    ll k = x;
    ll p = y;
    ll big = x;
    ll small = y;
    if (x < y)
    {
        ll temp = x;
        x = y;
        y = temp;
    }
    bool isthere = false;
    for (ll i = x; i >= y; i--)
    {
        if (isPrime(i))
        {
            big = i;
            isthere = true;
            break;
        }
    }
    for (ll i = y; i >= 2; i--)
    {
        if (isPrime(i))
        {
            small = i;
            break;
        }
    }
    if (isthere)
    {
        k > p ? cout << big - small << endl : cout << small - big << endl;
    }
    else
    {
        cout << "0" << endl;
    }
}