struct hashtable{
	v64 hash1,hash2,inv1,inv2;
	ll MOD1=MOD,MOD2=MOD+2;
	ll pr1=31,pr2=37;
	void create(string &p){
		int len=p.size();
		hash1.resize(len);hash2.resize(len);
		inv1.resize(len);inv2.resize(len);
		ll p1=1,p2=1;
		int i=0;
		while(p[i]){
			hash1[i]= (i==0)? 0:hash1[i-1];
			hash2[i]= (i==0)? 0:hash2[i-1];
			hash1[i]= (hash1[i]+p[i]*p1)%MOD1;
			hash2[i]= (hash2[i]+p[i]*p2)%MOD2;
			p1=p1*pr1%MOD1;
			p2=p2*pr2%MOD2;
			i++;}
		ll iv1=inv(pr1,MOD1),iv2=inv(pr2,MOD2);
		inv1[0]=1,inv2[0]=1;
		forsn(i,1,len){
			inv1[i]=inv1[i-1]*iv1%MOD1;
			inv2[i]=inv2[i-1]*iv2%MOD2;}}
	p64 gethash(int l,int r){
		ll ans1=hash1[r-1];
		if(l!=0) ans1+=MOD1-hash1[l-1];
		ll ans2=hash2[r-1];
		if(l!=0) ans2+=MOD2-hash2[l-1];
		ans1=ans1*inv1[l]%MOD1;
		ans2=ans2*inv2[l]%MOD2;
		return mp(ans1,ans2);}};