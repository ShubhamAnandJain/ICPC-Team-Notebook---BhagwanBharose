vector<set<int> > g;
vector<int> par,sub;
int dfs(int u,int p){
	sub[u]=1;
	for(auto &it: g[u]) if(it!=p) sub[u]+=dfs(it,u);
	return sub[u];}
int find_centroid(int u,int p,int n){
	for(auto &it: g[u]){
		if(it!=p && sub[it]>n/2){
			return find_centroid(it,u,n);}}
	return u;}
void decompose(int u,int p=-1){
	int n=dfs(u,p);
	int centroid=find_centroid(u,p,n);
	if(p==-1) p=centroid;
	// Do stuff here for merges
	// Recurse
	par[centroid]=p;
	for(auto &it: g[centroid]){
		g[it].erase(centroid);
		decompose(it,centroid);}
	g[centroid].clear();}
void reset(int n){
	par.resize(n);
	sub.resize(n);
	g.assign(n,set<int>());}
