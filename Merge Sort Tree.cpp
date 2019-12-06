// Merge sort Tree
const int MAXN=1e5+5;
v32 T[4*MAXN];  // nlogn memory
void build(int a[],int v,int tl,int tr){
	if(tl==tr){
		T[v]=v32(1,a[tl]);
	}else{
		int tm=(tl+tr)>>1;
		build(a,v<<1,tl,tm);
		build(a,(v<<1)^1,tm+1,tr);
		merge(all(T[v<<1]),all(T[(v<<1)^1]),back_inserter(T[v]));
		// built in combine in sorted order (2pointer)}}
// number of numbers <=x in [l,r]
int query(int v,int tl,int tr,int l,int r,int x){
	if(l>r) return 0;
	if(l<=tl && tr<=r){
		return upper_bound(all(T[v]),x)-T[v].begin();}
	int tm=(tl+tr)>>1;
	return query(v<<1,tl,tm,l,min(r,tm),x)+query((v<<1)^1,tm+1,tr,max(l,tm+1),r,x);}
// Number of distinct integers in [l,r]
int b[MAXN];
void convert(int a[],int n){ // b store next occ index
	m32 m; // Can be replaced by vv32 in small numbers
	rforn(i,n-1){
		auto it=m.find(a[i]);
		if(it==m.end()) b[i]=MOD; 
		else b[i]=it->se;
		m[a[i]]=i;}
	build(b,1,0,n-1);}
inline int q(int l,int r){ // no. of val in [l,r] with nxt ind > r
	return (r-l+1)-query(1,0,n-1,l,r,r);}