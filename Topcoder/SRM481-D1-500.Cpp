/*
explanation : here is the idea is every one will surely wait the total time of his work plus another time till others fininsh their 
work so if i just work for small time why should i wait one who works for a long time this adds alot extra time to me but imagine 
the opposite it will add very small time to the largest one from here the idea of the problem comes.
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define   angle(n)      atan2((n.imag()),(n.real()))
#define   vec(a,b)       ((b)-(a))
#define   length(a)      hypot( (a.imag()),(a.real()) )
#define   normalize(a)      (a)/(length(a))
#define    dp(a,b)          (((conj(a))*(b)).real())
#define    cp(a,b)          (((conj(a))*(b)).imag())
#define    lengthsqrt(a)       dp(a,a)
#define    rotate0( a,ang)    ((a)*exp( point(0,ang) ))
#define    rotateA(about,p,ang)   (rotate0(vec(about,p),ang)+about)
#define    lcm(a,b)                ((a*b)/(__gcd(a,b)))
#define    reflection0(m,v)         (conj((v)/(m))*(m))
#define     reflectionA(m,v,p0)     (conj( (vec(p0,v))/(vec(p0,m)) ) * (vec(p0,m)) ) + p0
#define     same(p1,p2)               ( dp(  vec(p1,p2),vec(p1,p2)) < eps )
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
class  	BatchSystem
{
public :
     vector<int> schedule(vector<int> v1,vector<string> s )
    {
        vector<ll> v(v1.begin(),v1.end());
        map<string,pair<ll,vector<int>> > mb;
        for(int i=0;i<sz(v1);i++)
        {
            mb[s[i]].first+=v1[i];
            mb[s[i]].second.pb(i);
        }
        vector<int> ans;
        vector< pair<ll,vector<int> > > v2;
        for(auto i=mb.begin();i!=mb.end();i++)
        {
            ll c=(*i).second.first;
            vector<int> w;
            w=(*i).second.second;
            v2.pb(mp(c,w));
        }
        sort(all(v2));
        for(int i=0;i<sz(v2);i++)
        {
            vector<int> q=v2[i].second;
            sort(all(q));
            for(int j=0;j<sz(q);j++)
                ans.pb(q[j]);
        }
          return ans;
    }
};
