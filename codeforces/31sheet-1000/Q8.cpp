// https://codeforces.com/problemset/problem/1791/D

#include<bits/stdc++.h>
using namespace std;
#define uint            unsigned int
#define int             long long
#define f_(i,a,b)       for(int i=a;i<b;i++)
#define rv_(i,a,b)      for(int i=a;i>=b;i--)    
#define via(n)          vector<int> a(n) 
#define all(a)          (a).begin(),(a).end()
#define clr(x)          memset(x, 0, sizeof(x))
#define printl(a)       cout<<a<<endl
#define print(a)        cout<<a<<" "
#define pnx             cout<<endl
#define ufill(a,n)      f_(i,0,n)cin>>a[i]
#define pii             pair<int,int>
#define pdd             pair<double,double>
#define fr              first
#define sc              second
#define pb              push_back
#define pob             pop_back
#define pm(a,b)         make_pair(a,b)
#define ushow(v,n)      f(i,0,n)print(v[i])
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
const int M=1e9+7;
const int MX=1e15+7;
const int MN=-1e15+7;
const int N=1e5+7;
int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return((a*b)/gcd(a,b));
}
bool comp(pair<int,pii> a,pair<int,pii> b){
    if(a.sc.fr>b.sc.fr)return false;
    return true;
}
/* .........................................................................................................*/
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    map<int,int> pre,suf;
    set<char> s1,s2;
    f_(i,0,n){
        s1.insert(s[i]);
        pre[i]=s1.size();
    }
    rv_(i,n-1,0){
        s2.insert(s[i]);
        suf[i]=s2.size();
    }
    int ans=0;
    f_(i,0,n-1){
        ans=max(ans,pre[i]+suf[i+1]);
    }
    printl(ans);
}
/* ......................................................................................................... */
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>>_t;while(_t--)solve();
    //clock_t s=clock();
    //solve();
    //clock_t e=clock();
    cout<<setprecision(10);
    //cout<<"Time taken="<<double(e-s)/double(CLOCKS_PER_SEC)<<endl;
    return 0;
}