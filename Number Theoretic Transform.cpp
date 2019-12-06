const int mod=998244353;
// 998244353=1+7*17*2^23 : g=3
// 1004535809=1+479*2^21 : g=3
// 469762049=1+7*2^26 : g=3
// 7340033=1+7*2^20 : g=3
// For below change mult as overflow:
	// 10000093151233=1+3^3*5519*2^26 : g=5
	// 1000000523862017=1+10853*1373*2^26 : g=3
	// 1000000000949747713=1+2^29*3*73*8505229 : g=2
// For rest find primitive root using Shoup's generator algorithm
// root_pw: power of 2 >= maxn, Mod-1=k*root_pw => w = primitive^k 
template<long long Mod,long long root_pw,long long primitive>
struct NTT{
	inline long long powm(long long x,long long pw){
		x%=Mod;
		if(abs(pw)>Mod-1) pw%=(Mod-1);
		if(pw<0) pw+=Mod-1;
		ll res=1;
		while(pw){
			if(pw&1LL) res=(res*x)%Mod;
			pw>>=1;
			x=(x*x)%Mod;}
		return res;}
	inline ll inv(ll x){
    	return powm(x,Mod-2); }
	ll root,root_1;
	NTT(){
		root=powm(primitive,(Mod-1)/root_pw);
		root_1=inv(root);}
	void ntt(vector<long long> &a,bool invert){
		int n=a.size();
		for(long long i=1,j=0;i<n;i++){
			long long bit=n>>1;
			for(;j&bit;bit>>=1) j^=bit;
			j^=bit;
			if(i<j) swap(a[i],a[j]);}
		for(long long len=2;len<=n;len<<=1){
			long long wlen= invert ? root_1:root;
			for(long long i=len;i<root_pw;i<<=1) wlen=wlen*wlen%Mod;
			for(long long i=0;i<n;i+=len){
				long long w=1;
				for(long long j=0;j<len/2;j++){
					long long u=a[i+j],v=a[i+j+len/2]*w%Mod;
					a[i+j]= u+v<Mod ? u+v:u+v-Mod;
					a[i+j+len/2]= u-v>=0 ? u-v:u-v+Mod;
					w=w*wlen%Mod;}}}
		if(invert){
			ll n_1=inv(n);
			for(long long &x: a) x=x*n_1%Mod;}}
	vector<long long> multiply(vector<long long> const& a,vector<ll> const& b){
		vector<long long> fa(a.begin(),a.end()),fb(b.begin(),b.end());
		int n=1;
		while(n<a.size()+b.size()) n<<=1;
		point(fa,1,n);
		point(fb,1,n);
		for(int i=0;i<n;++i) fa[i]=fa[i]*fb[i]%Mod;
		coef(fa);
		return fa;}
	void point(vector<long long> &A,bool not_pow=1,int atleast=-1){
		if(not_pow){
			if(atleast==-1){
				atleast=1;
				while(atleast<A.size()) atleast<<=1;}
			A.resize(atleast,0);}
		ntt(A,0);}
	void coef(vector<long long> &A,bool reduce=1){
		ntt(A,1);
		if(reduce) while(A.size() and A.back()==0) A.pop_back(); }
	void point_power(vector<long long> &A,long long k){
		for(long long &x: A) x=powm(x,k);}
	void coef_power(vector<long long> &A,int k){
		while(A.size() and A.back()==0) A.pop_back();
		int n=1;
		while(n<k*A.size()) n<<=1;
		point(A,1,n);
		point_power(A,k);
		coef(A);}
	vector<long long> power(vector<long long> a,ll p){
		while(a.size() and a.back()==0) a.pop_back();
		vector<long long> res;
		res.pb(1);
		while(p){
			if(p&1) res=multiply(res,a);
			a=multiply(a,a);
			p/=2;}
		return res;}};
NTT<mod,1<<20,3> ntt;