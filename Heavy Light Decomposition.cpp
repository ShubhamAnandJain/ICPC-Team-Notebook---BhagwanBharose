struct SegTree{
	v32 T,lazy;
	int N,MX;
	void clear(int n,int mx){
		N=n,MX=mx;
		T.assign(4*N,0);
		lazy.assign(4*N,0);}
	void build(int a[],int v,int tl,int tr){
		if(tl==tr){
			T[v]=a[tl];}else{
			int tm=(tl+tr)>>1,lf=v<<1,rt=lf^1;;
			build(a,lf,tl,tm);
			build(a,rt,tm+1,tr);
			T[v]=min(T[lf],T[rt]);}}
	void push(int v){
		int lf=v<<1,rt=lf^1;
		T[lf]=(T[lf]+lazy[v]);
		lazy[lf]=(lazy[lf]+lazy[v]);
		T[rt]=(T[rt]+lazy[v]);
		lazy[rt]=(lazy[rt]+lazy[v]);
		lazy[v]=0;}
	void update(int v,int tl,int tr,int l,int r,int val){
		if(l>r or tl>r or tr<l) return;
		if(l<=tl && tr<=r){
			T[v]=T[v]+val;
			lazy[v]=(lazy[v]+val);}else{
			if(tl==tr) return;
			push(v);
			int tm=(tl+tr)>>1,lf=v<<1,rt=lf^1;;
			update(lf,tl,tm,l,r,val);
			update(rt,tm+1,tr,l,r,val);
			T[v]=max(T[lf],T[rt]);}}
	int query(int v,int tl,int tr,int l,int r){
		if(l>r) return MX;
		if(l<=tl && tr<=r) return T[v];
		push(v);
		int tm=(tl+tr)>>1,lf=v<<1,rt=lf^1;
		return max(query(lf,tl,tm,l,min(r,tm)),query(rt,tm+1,tr,max(l,tm+1),r));}
	int q(int l,int r){
		return query(1,0,N-1,l,r);}
	void u(int l,int r,int val){
		update(1,0,N-1,l,r,val);}
} st;
struct hld{
	int n,t;
	v32 sz,in,out,root,par,depth;
	vv32 g;
	SegTree tree;
	void dfs_sz(int v=0,int p=0){
		sz[v]=1;
		for(auto &u: g[v]){
			if(u==p) continue;
			dfs_sz(u,v);
			sz[v]+=sz[u];
			if(sz[u]>sz[g[v][0]]) swap(u, g[v][0]);}}
	void dfs_hld(int v=0,int p=0){
	    in[v]=t++;
	    par[v]=p;
	    depth[v]=depth[p]+1;
	    for(auto u: g[v]){
	    	if(u==p) continue;
	        root[u]= (u==g[v][0] ? root[v]:u);
	        dfs_hld(u,v);}
	    out[v]=t;}
	void pre(vv32 &v){
		g=v;n=v.size();t=0;
		sz.assign(n,0);in.assign(n,0);out.assign(n,0);
		root.assign(n,0);par.assign(n,0);depth.assign(n,0);
		depth[0]=-1;
		dfs_sz();dfs_hld();
		tree.clear(n,-MOD);}
	template <class BinaryOperation>
	void processPath(int u,int v,BinaryOperation op){
		for(;root[u]!=root[v];v=par[root[v]]){
			if(depth[root[u]] > depth[root[v]]) swap(u,v);
			op(in[root[v]],in[v]);  }
		if(depth[u]>depth[v]) swap(u,v);
		op(in[u],in[v]);}
	void modifyPath(int u,int v,const int &value){
    	processPath(u,v,[this,&value](int l,int r){tree.u(l,r,value);});} // [l,r]
  	void modifySubtree(int u,const int &value){
  		tree.u(in[u],out[u]-1,value);}
  	int queryPath(int u,int v){
    	int res=-MOD;
    	auto add=[](int &a,const int &b){a=max(a,b);};
    	processPath(u,v,[this,&res,&add](int l,int r){add(res,tree.q(l,r));});
    	return res;}
  	int querySubtree(int u){
  		return tree.q(in[u],out[u]-1);}
};