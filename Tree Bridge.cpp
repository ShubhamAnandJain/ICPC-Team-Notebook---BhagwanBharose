struct dsu{
    v32 par,rk;
    dsu(){}
    dsu(int n) {reset(n);}
    void reset(int n){
        rk.assign(n,0);
        par.resize(n);
        iota(all(par),0);}
    int getpar(int i){
        return (par[i]==i)? i:(par[i]=getpar(par[i]));}
    bool con(int i,int j){
        return getpar(i)==getpar(j);}
    bool join(int i,int j){
        i=getpar(i),j=getpar(j);
        if(i==j) return 0;
        if(rk[i]>rk[j]) par[j]=i;
        else{
            par[i]=j;
            if(rk[i]==rk[j]) rk[j]++;}
        return 1;}};
vector<vector<int> > getBridgeTree(vector<vector<int> > &v,int n){
	int in[n]={0},low[n],ctm=0;
	vector<pair<int,int> > bridge;
	dsu d(n);
	function<void(int,int)> dfs=[&](int u,int p){
		in[u]=low[u]=++ctm;
		for(auto &it: v[u]){
			if(it==p) continue;
			if(in[it]){
				if(low[it]<low[u]) low[u]=low[it];
			}else{
				dfs(it,u);
				if(low[it]<low[u]) low[u]=low[it];
				if(low[it]>in[u]) bridge.push_back({u,it});
				else d.join(u,it);}}};
	for(int i=0;i<n;++i) if(!in[i]) dfs(i,i);
	int par[n],id[n];
	for(int i=0;i<n;++i) par[i]=d.getpar(i),id[i]=-1;
	vector<vector<int> > g;
	for(auto &it: bridge){
		it.first=par[it.first],it.second=par[it.second];
		if(id[it.first]==-1){
			id[it.first]=g.size();
			g.push_back(vector<int>(0));}
		if(id[it.second]==-1){
			id[it.second]=g.size();
			g.push_back(vector<int>(0));}
		g[id[it.first]].push_back(id[it.second]);
		g[id[it.second]].push_back(id[it.first]);}
	return g;}
// dfs find all brideges and g contain bridge tree rest is diameter calculation
