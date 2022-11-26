#include<bits/stdc++.h>
using namespace std;

int n,m=0,sum=0;
vector<int> chk;
bool x=true;

void solve(vector<int> &num,int i){
    if(i<n){
        sum+=num[i];
        if(sum==m){
            x=false;
            return;
        }
        else if(sum<m){
            solve(num,i+1);
        }
        sum-=num[i];
        solve(num,i+1);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> num;
        for(int i=0;i<n;i++){
           int a;
           cin>>a;
           m+=a;
           num.push_back(a);
        }
        if(m%2!=0){
            cout<<"NO\n";
        }
        else{
            m/=2;
            solve(num,0);
            if(x) cout<<"NO\n";
            else cout<<"YES\n";
        }
        x=true;
        chk.erase(chk.begin(),chk.end());
        m=0;
        sum=0;
    }
    return 0;
}
