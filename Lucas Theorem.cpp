//Lucas Theorem: Find (n Choose m) mod p for prime p and large n,m. in O(log(m*n))
// nCm mod p by lucas theorem for large n,m >=0
// p prime, require fact(factorial) & invfact(inverse factorial)
v32 fact,invfact;
ll lucas(ll n,ll m,int p){
	ll res=1;
	while(n || m) {
		ll a=n%p,b=m%p;
		if(a<b) return 0;
		res=((res*fact[a]%p)*(invfact[b]%p)%p)*(invfact[a-b]%p)%p;
		n/=p; m/=p;
	}
	return res;
}