/*
explanation : here the probability is the number of correct states divided by all 
possible states, it is easy to calculate all possible states which are 6^n but the 
harder point is to calculate the correct states it cant be calculated so we will run
a dp to count such states then divide by the whole states.

complexity : O( n^2*6 )
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define    vi       vector<int>
#define    vd       vector<double>
#define    vvi      vector< vector<int> >
#define    vvll      vector< vector<long long> >
#define    vvpi     vector< vector< pair<int,int> > >
#define    vvpll     vector< vector< pair<long long,long long> > >
#define    vvd      vector< vector<double> >
#define    vs       vector<string>
#define    vvs      vector< vector<string> >
#define     vpi        vector< pair<int ,int> >
#define      pi        pair<int ,int>
#define      pll       pair<long long ,long long>
#define     vpd        vector< pair<double ,double> >
#define     vpll        vector< pair<long long ,long long> >
#define    vll       vector<long long>
#define    dqi        deque< int >
#define     si         set<int>
#define     spi        set< pair<int ,int > >
#define     row          vector< ll >
#define     matrix            vector< row >
#define     si         set<int>
#define    oo         900000000000000000
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int n,x;
ull mem[24+9][150+9];
ull fun(int id,int s)
{
    if(id==n)
    {
        if(s>=x)
            return 1;
        return 0;
    }
    ull &ret=mem[id][s];
    if(ret!=-1)
        return ret;
    ull res=0;
    for(int i=1;i<=6;i++)
    {
       res+= fun(id+1,s+i);
    }
    ret=res;
    return ret;
}
ull power(ull b,int p)
{
    if(p==0)
        return 1;
    if(p&1)
    {
        return b*power(b*b,p/2);
    }
    else
        return power(b*b,p/2);
}
ull gcd(ull a,ull b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
   while(cin>>n>>x)
 {
    if(n==0&&x==0)
        break;
    clr(mem,-1);
   ull ans= fun(0,0);
   ull um= ans;
   ull den= power(6,n);
   if(um%den==0)
   {  //cout<<ans<<den<<endl;
       cout<< um/den <<endl;
   }
   else
   {
       ull g=gcd(um,den);

       cout<< um/g <<"/"<< den/g<<endl;
   }
 }
}
