// Giant Step - Baby Step for discrete log
// find x with a^x = b mod MOD
// Find one soln can be changed to find all 
// O(root(MOD)*log(MOD)) can be reduced with unordered map or array
ll solve(ll a,ll b,ll MOD){
    int n=(int)sqrt(MOD+.0)+1;
    ll an=1,cur;
    forn(i,n) an=(an*a)%MOD;
    cur=an;
    vector<pair<ll,int> > vals;
    forsn(i,1,n+1){
    	vals.pb(mp(cur,i));
        cur=(cur*an)%MOD;
    }
    cur=b;
    sort(all(vals));
    forn(i,n+1){
    	auto in=lower_bound(all(vals),mp(cur,-1))-vals.begin();
    	if(in!=vals.size() && vals[in].fi==cur){
    		ll ans=n*(ll)vals[in].se-i;
    		if(ans<MOD) return ans;
    	}
        cur=(cur*a)%MOD;
    }
    return -1;
}