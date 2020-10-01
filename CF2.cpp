#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <math.h> 
#include <stdio.h> 
#define ll long  long
#define ld long double
#define mod 1000000007
#define max_char 128
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lbd lower_bound
#define ubd upper_bound
#define PI 3.141592653589793238
#define pf push_front
#define all(x) x.begin(),x.end()
#define FOR(i, a, b)    for(int i=a; i<b; i++)
#define rep(i,a,n) for( ll i=a ; i<n ; i++)
#define mems(x, y) memset(x, y, sizeof(x))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


void solve(){
	ll n,l;
	cin>>n>>l;
    vector <ll> a(n+2);
    std::cout << std::fixed;
    std::cout << std::setprecision(8);
    FOR(i,1,n+1)  cin>>a[i];
    ll s1, s2;
    s1= 0 ; s2 = 0;
    ld t, q;
    ld c1=0, c2=n+1, v1 = 1, v2 = 1 ;
    if(n==0){
        t = (l*1.0)/((1.0)*(v1+v2));
        cout << setprecision(6) << t << '\n';
        return;
    }
    t=0;
    a[0]=0;a[n+1]=l;
    ld temp, temp2;
    while(s1+s2<l){
        if(c1+1==c2)
        break;

        temp  = a[c1+1] -s1; temp2 = (l-s2)-a[c2-1] ;
       
        if(((temp*(1.0))/(v1*(1.0)))<((temp2*(1.0))/(v2*(1.0)))){
            
            q = ((temp*(1.0))/(v1*(1.0)));
            s1 += temp;
            temp2 = q*(v2);
            s2 += temp2;
            t += q;
            v1++;
            c1++;

        }
        else if(((temp*(1.0))/(v1*(1.0)))==((temp2*(1.0))/(v2*(1.0)))){
            
            q = ((temp*(1.0))/(v1*(1.0)));
            s1 += temp;
            temp2 = q*(v2);
            s2 += temp2;
            t += q;
            v1++; v2++; c1++; c2--;
           
            if(c1==c2){
                cout<<t<<endl;
                return;
            }
        }
        else{
            
            q = ((temp2*(1.0))/(v2*(1.0)));
            s2 += temp2;
            temp = q*(v1);
            s1 += temp;
            t += q;
            v2++; c2--;
        }
        


    }
    if(c1+1==c2){
        
        l += -s1-s2;
        t += (l*1.0)/((v1+v2)*(1.0));
        cout<<t<<endl;
        
    }
    

    
}



int main(){
    fastio
    int t=1;
    cin>>t;
    while(t--){  
        solve();
    }
    return 0;
}
