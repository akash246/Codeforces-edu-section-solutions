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
    ll n = s.length();
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
vector<ll> lcp_construction(string const& s, vector<ll> const& p)
{
    ll n = s.length();
    vector<ll> ranks(n, 0);
    for (ll i = 0; i < n; i++)
        ranks[p[i]] = i;
    ll k = 0;
    vector<ll> lcp(n-1, 0);
    for (ll i = 0; i < n; i++) {
        if (ranks[i] == n - 1) {
            k = 0;
            continue;
        }
        ll j = p[ranks[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[ranks[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
void merges(ll node, vector<vector<ll> > &tree)
{
    ll x=tree[2*node].size(), y=tree[2*node+1].size();
    ll l=0, r=0;
    while(l<x && r<y) {
        if(tree[2*node][l]<=tree[2*node+1][r]) {
            tree[node].pb(tree[2*node][l++]);
        } else {
            tree[node].pb(tree[2*node+1][r++]);
        }
    }
    while(l<x)
        tree[node].pb(tree[2*node][l++]);
    while(r<y)
        tree[node].pb(tree[2*node+1][r++]);
}
void build(ll node, ll start, ll ends, vector<ll> &arr, vector<vector<ll> > &tree)
{
    if(start==ends) {
        tree[node].push_back(arr[start]);
    } else {
        ll mid=(start+ends)/2;
        build(2*node, start, mid, arr, tree);
        build(2*node+1, mid+1, ends, arr, tree);
        merges(node, tree);
    }
}
ll query(ll node, ll start, ll ends, ll l, ll r, vector<vector<ll> > &tree, ll val)
{
    if(ends<l || start>r)
        return INF;
    if(start>=l && ends<=r) {
        auto it=upper_bound(all(tree[node]), val);
        ll res=INF;
        if(it!=tree[node].end()) {
            ll t=*it;
            res=min(res, abs(val - t));
        }
        if(it!=tree[node].begin()) {
            it--;
            ll t=*it;
            res=min(res, abs(val - t));
        }
        return res;
    } else {
        ll mid=(start+ends)/2;
        return min(query(2*node, start, mid, l, r, tree, val), query(2*node+1, mid+1, ends, l, r, tree, val));
    }
}
void solve()
{
    string s;
    cin>>s;
    ll n=s.length();
    if(n==1) {
        cout<<1;
        return ;
    }
    vector<ll> p=suffix_array(s);
    vector<ll> lcp=lcp_construction(s, p);
    ll m=lcp.size();
    vector<ll> prev(m), next(m);
    stack<ll> st;
    F(i,0,m) {
        while(!st.empty() && lcp[st.top()]>lcp[i]) {
            next[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        next[st.top()]=m;
        st.pop();
    }

    for(ll i=m-1; i>=0; i--) {
        while(!st.empty() && lcp[st.top()]>lcp[i]) {
            prev[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        prev[st.top()]=-1;
        st.pop();
    }
    vector<ll> a(m), b(m);
    vector<vector<ll> > tree1(4*m), tree2(4*m);
    F(i,0,m) {
        a[i]=p[i];
    }
    F(i,0,m) {
        b[i]=p[i+1];
    }
    build(1, 0, m-1, a, tree1);
    build(1, 0, m-1, b, tree2);
    ll ans=1;
    F(i,0,m) {
        ll l=prev[i]+1, r=next[i]-1;
        ll res=query(1, 0, m-1, i, r, tree2, p[i]);
        res=min(res, query(1, 0, m-1, l, i, tree1, p[i+1]));
        ans=max(ans, 1+lcp[i]/res);
    }
    cout<<ans;
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
