/**
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡖⠁⠀⠀⠀⠀⠀⠀⠈⢲⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣧⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣸⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⢀⣀⣤⣤⣤⣤⣀⡀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣔⢿⡿⠟⠛⠛⠻⢿⡿⣢⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣀⣤⣶⣾⣿⣿⣿⣷⣤⣀⡀⢀⣀⣤⣾⣿⣿⣿⣷⣶⣤⡀⠀⠀⠀⠀
⠀⠀⢠⣾⣿⡿⠿⠿⠿⣿⣿⣿⣿⡿⠏⠻⢿⣿⣿⣿⣿⠿⠿⠿⢿⣿⣷⡀⠀⠀
⠀⢠⡿⠋⠁⠀⠀⢸⣿⡇⠉⠻⣿⠇⠀⠀⠸⣿⡿⠋⢰⣿⡇⠀⠀⠈⠙⢿⡄⠀
⠀⡿⠁⠀⠀⠀⠀⠘⣿⣷⡀⠀⠰⣿⣶⣶⣿⡎⠀⢀⣾⣿⠇⠀⠀⠀⠀⠈⢿⠀
⠀⡇⠀⠀⠀⠀⠀⠀⠹⣿⣷⣄⠀⣿⣿⣿⣿⠀⣠⣾⣿⠏⠀⠀⠀⠀⠀⠀⢸⠀
⠀⠁⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⢇⣿⣿⣿⣿⡸⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠈⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠐⢤⣀⣀⢀⣀⣠⣴⣿⣿⠿⠋⠙⠿⣿⣿⣦⣄⣀⠀⠀⣀⡠⠂⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠉⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠋⠁⠀⠀
**/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define nl cout<<"\n";
#define ll long long int
#define ld long double
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define F(i,a,b) for(ll i=a;i<b;i++)
//#include <ext/pb_ds/assoc_container.hpp> // policy based data structure header files
//#include <ext/pb_ds/tree_policy.hpp> // policy based data structure header files
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
//using namespace __gnu_pbds; // for pbds
//#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> // have functions like order_of_key, find_by_order
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781641;
const ll M=1e9+7;
const ll INF=1e18;
const ll MAXN=200200;
vector<ll> sort_cyclic_shifts(string const& s)
{
    ll n = s.size();
    const ll alphabet = 256;
    vector<ll> p(n), c(n), cnt(max(alphabet, n), 0);
    for (ll i = 0; i < n; i++)
        cnt[s[i]]++;
    for (ll i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (ll i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    ll classes = 1;
    for (ll i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<ll> pn(n), cn(n);
    for (ll h = 0; (1 << h) < n; ++h) {
        for (ll i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (ll i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (ll i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (ll i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (ll i = 1; i < n; i++) {
            pair<ll, ll> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<ll, ll> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
vector<ll> suffix_array(string s)
{
    s += "$";
    vector<ll> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
ll check(ll idx, string &t, string &s)
{
    ll n=t.length();
    F(i,0,s.length()) {
        ll curr=(i+idx);
        if(s[i]>t[curr]) {
            return 1;
        }
        if(s[i]<t[curr]) {
            return -1;
        }
    }
    return 0;
}
void solve()
{
    string t;
    cin>>t;
    vector<ll> sorted_shifts=suffix_array(t);
    ll n;
    cin>>n;
    t+='$';
    while(n--) {
        string s;
        cin>>s;
        ll low=0, high=t.length()-1;
        ll con=0;
        while(low<=high) {
            ll mid=(low+high)/2;
            ll f=check(sorted_shifts[mid], t, s);
            if(f==0) {
                cout<<"Yes\n";
                con=1;
                break;
            }
            if(f==1) {
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        if(con)
            continue;
        cout<<"No\n";
    }
}
int main()
{
    IOS
    /*#ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE*/
    ll test=1;
    //cin>>test;
    F(t,1,test+1) {
        //cout<<"Case #"<<t<<": ";
        solve();
        nl
    }
    return 0;
}