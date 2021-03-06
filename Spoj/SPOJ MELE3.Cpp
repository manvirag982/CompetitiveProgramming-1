/*
explanation : the idea is simple dijkstra but here the explanation of the calculation the time i will 
reach with it a node the elevator from this node will go up and return back from the begining so i will calcualte 
the position it reaches and the time i will wait till it comes back.
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
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
ll dist[1000+9],vis[1000+9],k,n;
const ll inf=100000000000000000;
struct node
{
    ll n,w;
    node(ll n,ll w) :n(n),w(w) {}

    bool operator < (const node &e) const
    {
        return w>e.w;
    }
};

ll dijk(vector<vector<node> > v)
{

    for(int i=0;i<1009;i++)
        dist[i]=inf;

    dist[1]=0;

    priority_queue< node > pq;

    pq.push(node(1,0));

    while(!pq.empty())
    {

        node cur=pq.top();

        pq.pop();

        if(vis[cur.n])
            continue;

        vis[cur.n]=1;

        ll t= cur.w;

        for(int i=0;i<sz(v[cur.n]);i++)
        {
            node nw=v[cur.n][i];
            ll ew=nw.w;
            ll wt;
            ll cycles=t/ew;
            ll rem=t%ew;

            if(t%ew==0&&cycles%2==0)
                wt=0;
            else if(t%ew==0&&cycles%2!=0)
                wt=ew;
            else if(t%ew!=0&&cycles%2==0)
                wt=ew+(ew-rem);
            else if(t%ew!=0&&cycles%2!=0)
                wt=ew-rem;

            ll ncost= t+wt+ew;

            if(dist[nw.n]>ncost)
            {
                dist[nw.n]=ncost;
                pq.push(node(nw.n,ncost));
            }
        }
    }

    return dist[k];
}



int main()
{

    cin>>k>>n;
    vector< vector< node > > v(1000+9);
    ll a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        ll w= (b-a)*5;
        v[a].pb(node(b,w));
        v[b].pb(node(a,w));
    }

    cout<<dijk(v)<<endl;
}

