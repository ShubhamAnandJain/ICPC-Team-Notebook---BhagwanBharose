// Li chao Tree (can be made persistent)
struct Line{
	ll m, c;
	Line(ll mm=0,ll cc=-3e18): m(mm),c(cc){}
	inline ll get(const int &x){return m*x+c;}
	inline ll operator [](const int &x){return m*x+c;} };
vector<Line> LN;
struct node{
	node *lt,*rt;
	int Ln;
	node(const int&l): Ln(l),lt(0),rt(0){};
	inline ll operator[](const int &x){ return LN[Ln].get(x);}
	inline ll get(const int &x){return LN[Ln].get(x);}};
const static int LX=-(1e9+1),RX=1e9+1;
struct Dynamic_Hull{ /* Max hull */
	node *root=0;
	void add(int l,node* &it,int lx=LX,int rx=RX){
		if(it==0) it=new node(l);
		if(it->get(lx)>=LN[l].get(lx) and it->get(rx)>=LN[l].get(rx)) return;
		if(it->get(lx)<=LN[l].get(lx) and it->get(rx)<=LN[l].get(rx)){
			it->Ln=l;
			return;}
		int mid=(lx+rx)>>1;
		if(it->get(lx)<LN[l][lx]) swap(it->Ln,l);
		if(it->get(mid)>=LN[l][mid]){
			add(l,it->rt,mid+1,rx);}
      else{
		 	swap(it->Ln,l); 
		 	add(l,it->lt,lx,mid); }}
  inline void add(int ind){add(ind,root);}
  inline void add(int m,int c){LN.pb(Line(m,c));add(LN.size()-1,root);}
  ll get(int &x,node* &it,int lx=LX,int rx=RX){
    if(it==0) return -3e18; // Max hull
    ll ret=it->get(x);
    int mid=(lx+rx)>>1;
    if(x<=mid) ret=max(ret,get(x,it->lt,lx,mid));
    else ret=max(ret,get(x,it->rt,mid+1,rx));
    return ret;}
  inline ll get(int x){return get(x,root);}};
// const static int LX = -(1e9), RX = 1e9;
// struct Dynamic_Hull { /* Max hull */
//   struct Line{
//     ll m, c; // slope, intercept
//     Line(ll mm=0, ll cc=-1e18) { m = mm; c = cc; }
//     ll operator[](const int&x){ return m*x+c; }  
//   };
//   struct node {
//     node *lt,*rt; Line Ln;
//     node(const Line &l){lt=rt=nullptr; Ln=l;}
//   };
//   node *root=nullptr;
//   void add(Line l,node*&it,int lx=LX,int rx=RX){
//     if(it==nullptr)it=new node(l);
//     if(it->Ln[lx]>=l[lx] and it->Ln[rx]>=l[rx]) return;
//     if(it->Ln[lx]<=l[lx] and it->Ln[rx]<=l[rx]) {it->Ln=l; return;}
//     int mid = (lx+rx)>>1;
//     if(it->Ln[lx] < l[lx]) swap(it->Ln,l);
//     if(it->Ln[mid] >= l[mid]) add(l,it->rt,mid+1,rx);
//     else { swap(it->Ln,l); add(l,it->lt,lx,mid); }
//   }
//   void add(const ll &m,const ll &c) { add(Line(m,c),root); }
//   ll get(int &x,node*&it,int lx=LX,int rx=RX){
//     if(it==NULL) return -1e18; // Max hull
//     ll ret = it->Ln[x];
//     int mid = (lx+rx)>>1;
//     if(x<=mid) ret = max(ret , get(x,it->lt,lx,mid));
//     else ret = max(ret , get(x,it->rt,mid+1,rx));
//     return ret;
//   }
//   ll get(int x){ return get(x,root); }
// };
struct  Hull{
  struct line {
    ll m,c;
    ll eval(ll x){return m*x+c;}
    ld intersectX(line l){return (ld)(c-l.c)/(l.m-m);}
    line(ll m,ll c): m(m),c(c){}};
  deque<line> dq;
  v32 ints;
  Hull(int n){ints.clear(); forn(i,n) ints.pb(i); dq.clear();}
  // Dec order of slopes
  void add(line cur){
    while(dq.size()>=2 && cur.intersectX(dq[0])>=dq[0].intersectX(dq[1]))
      dq.pop_front();
    dq.push_front(cur);}
  void add(const ll &m,const ll &c){add(line(m,c));}
  // query sorted dec.
  // ll getval(ll x){
  //   while(dq.size()>=2 && dq.back().eval(x)<=dq[dq.size()-2].eval(x))
  //     dq.pop_back();
  //   return dq.back().eval(x);
  // }
  // arbitary query
  ll getval(ll x,deque<line> &dq){
    auto cmp = [&dq](int idx,ll x){return dq[idx].intersectX(dq[idx+1])<x;};
    int idx = *lower_bound(ints.begin(),ints.begin()+dq.size()-1,x,cmp);
    return dq[idx].eval(x);}
  ll get(const ll &x){return getval(x,dq);}};