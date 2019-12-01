int u[LIM],v[LIM],e[LIM],q[LIM];
map<p32,int> ids;
struct dsu{
	int sz;
    v32 par,rk;
    stack<int> st;
    void reset(int n){
        rk.assign(n,1);
        par.resize(n);
        iota(all(par),0);
        sz=n;
    }
    int getpar(int i){
        return (par[i]==i)? i:getpar(par[i]);
    }
    bool con(int i,int j){
        return getpar(i)==getpar(j);
    }
    bool join(int i,int j){
        i=getpar(i),j=getpar(j);
        if(i==j) return 0;
        --sz;
        if(rk[j]>rk[i]) swap(i,j);
        par[j]=i,rk[i]+=rk[j];
        st.push(j);
        return 1;
    }
    int moment(){
    	return st.size();
    }
    void revert(int tm){
    	while(st.size()>tm){
    		auto tp=st.top();
    		rk[par[tp]]-=rk[tp];
    		par[tp]=tp;
    		st.pop();
    		++sz;
    	}
    }
} d;
void solve(int l,int r,vp32 &ed){
	if(l>r) return;
	// dbg(ed,l,r,d.sz);
	int mid=(l+r)>>1;
	vp32 low;
	int tm=d.moment();
	forstl(it,ed){
		if(it.se<l or it.fi>r) continue;
		else if(it.fi<=l and it.se>=r) d.join(u[it.fi],v[it.fi]);
		else low.pb(it);
	}
	if(l==r){
		if(q[l]) cout<<(d.con(u[l],v[l])? "YES":"NO")<<ln;
	}else{
		solve(l,mid,low);
		solve(mid+1,r,low);
	}
	d.revert(tm);
}
signed main(){
	fastio;
	cin>>n>>k;
	d.reset(n);
	string t;
	forn(i,k){
		cin>>t;
		cin>>x>>y; --x,--y;
		if(x>y) swap(x,y);
		u[i]=x,v[i]=y;
		if(t[0]=='c'){
		 	q[i]=1;
		}else{
			if(t[0]=='a'){
				ids[mp(x,y)]=i;
				e[i]=k-1;
			}else{
				e[ids[mp(x,y)]]=i;
				e[i]=-1;
			}
		}
	}
	vp32 ed;
	forn(i,k) if(!q[i] && e[i]!=-1) ed.pb({i,e[i]});
	solve(0,k-1,ed);
	return 0;
}