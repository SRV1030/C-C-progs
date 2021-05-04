//>>>>>>>>>>>>>>>>>>>>>>>>>>JAI BAJRANG BALI<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
#define HARSH_JUDGE
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
#define db(x)                   cout<<#x<<"="<<x<<'\n'
#define db2(x,y)                 cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define ll long long
#define ld long double
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ull unsigned long long
#define setbits(x)      __builtin_popcountll(x)
#define str string
#define Iosi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define forr(i,n,a) for(ll i=n;i>=a;i--)
#define cases   long long t;cin>>t;while(t--)
#define eb emplace_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define ff first
#define ss second
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define sp(x,y)         fixed<<setprecision(y)<<x
#define nl '\n'
#define sz(x) ((int)(x).size())



typedef vector<int> vi;
typedef map<ll, ll> mll;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<ll, int> mli;
typedef map<char, int> mci;
typedef vector<long long> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vector<int> > vv;
const ll INF = 1e18 ;
const ll N = 1e5 + 7 ;
const int MOD = (int) 1e9 + 7;


void solve()
{

	ll n, a, b;
	cin >> n >> a >> b;
	str s, ss;
	cin >> s >> ss;
	ll mn = INF;
	// ll i=0;
	fo(j, 0, n)
	{
		ll i = j, cnt = 0;

		fo(k, 0, n)
		{
			if (s[i % n] != ss[k])cnt++;
			i++;
		}
		mn = min(mn, j * a + cnt * b);
	}
	cout << mn << nl;
	return;

}

int main()
{
	Iosi;
//#ifndef HARSH_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif
	ll t = 1;
	cin >> t;
	// clock_t timest = clock();
	// cerr << "[Executes in " << (double)(clock() - timest) / CLOCKS_PER_SEC << "s]" << endl;
	while (t--)
	{
		solve();

	}
}
