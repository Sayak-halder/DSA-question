// https://codeforces.com/problemset/problem/1849/B

#include<bits/stdc++.h>
using namespace std;
#define uint            unsigned int
#define int             long long
#define f(i,a,b)        for(int i=a;i<b;i++)
#define rv(i,a,b)       for(int i=a;i>=b;i--)    
#define via(n)          vector<int> a(n) 
#define all(a)          (a).begin(),(a).end()
#define rvall(a)        (a).rbegin(),(a).rend()
#define clr(x)          memset(x, 0, sizeof(x))
#define printl(a)       cout<<a<<endl
#define print(a)        cout<<a<<" "
#define ufill(a,n)      f(i,0,n)cin>>a[i]
#define pii             pair<int,int>
#define fr              first
#define sc              second
#define pb              push_back
#define pob             pop_back
#define pm(a,b)         make_pair(a,b)
#define ushow(v,n)      f(i,0,n)print(v[i])
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
const int MX=1e18+7;
const int M=1e9+7;
const int N=1e5+7;
int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return((a*b)/gcd(a,b));
}
bool comp(pii a,pii b){
    if(a.fr<b.fr)return false;
    else if(a.fr==b.fr && a.sc>b.sc)return false;
    else
    return true;
}
/* ......................................................................................................... */
bool check(int ar[],int n,int mid,int c){
    int sum=0LL;
    f(i,0,n){
        sum+=(2LL*mid+ar[i])*(2LL*mid+ar[i]);
        if(sum>c)return false;
    }
    return sum<=c;
}
void solve(){
    int n,k;cin>>n>>k;
    vector<pii> arr(n);
    f(i,0,n){
        int x;cin>>x;
        arr[i]={x,i+1};
        arr[i].fr%=k;
        if(!arr[i].fr)
        arr[i].fr=k;
    }
    vector<int> ans(n);
    sort(all(arr),comp);
    f(i,0,n)print(arr[i].sc);
    printl("");
}
/* ......................................................................................................... */
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //cout<<setprecision(10);
    int _t;cin>>_t;while(_t--)solve();
    //clock_t s=clock();
    //solve();
    //clock_t e=clock();
    //cout<<"Time taken="<<int(e-s)/int(CLOCKS_PER_SEC)<<endl;
    return 0;
}