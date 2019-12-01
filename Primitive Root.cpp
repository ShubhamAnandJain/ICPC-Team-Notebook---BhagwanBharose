// Primitive root Exist for n=1,2,4,(odd prime power),2*(odd prime power)
// O(Ans.logϕ(p).logp + sqrt(phi)) <= O((log p)^8 + root(p))
// Change phi when not prime
// Include powm (inverse)
ll phi_cal(ll n){
	ll result=n;
	for(ll i=2;i*i<=n;++i){
		if(n%i==0){
			while(n%i==0) n/=i;
			result-=result/i;
		}
	}
	if(n>1) result-=result/n;
	return result;
}
ll generator(ll p){
	v64 fact;
	ll phi=p-1; // Call phi_cal if not prime
	ll n=phi;
	for(ll i=2;i*i<=n;++i){
		if(n%i==0){
			fact.push_back(i);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) fact.push_back(n);
	for(ll res=2;res<=p;++res){
		bool ok=true;
		for(size_t i=0;i<fact.size() && ok;++i)
			ok&=(powm(res,phi/fact[i],p)!=1);
		if(ok) return res;
	}
	return -1;
}