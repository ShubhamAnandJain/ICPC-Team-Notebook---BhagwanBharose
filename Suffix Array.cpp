struct SuffixArray{
	v32 a;
	string s;
	SuffixArray(const string& _s): s(_s+'\0'){ // e.g. s="aba\0" will have a=[3,2,0,1]
		int N=s.size();
		vector<pair<ll,int> > b(N);
		a.resize(N);
		for(int i=0;i<N;++i){
			b[i].first=s[i];
			b[i].second=i;
		}
		int q=8;
		while((1<<q)<N) q++;
		for(int moc=0;;moc++){
			sort(all(b));
			a[b[0].second]=0;
			for(int i=1;i<N;++i){
				a[b[i].second]=a[b[i-1].second]+(b[i-1].first!=b[i].first);
			}
			if((1<<moc)>=N) break;
			for(int i=0;i<N;++i){
				b[i].first=(ll)a[i]<<q;
				if(i+(1<<moc)<N) b[i].first+=a[i+(1<<moc)];
				b[i].second=i;
			}
		}
		for(int i=0;i<N;++i) a[i]=b[i].second;
	}
	v32 lcp(){ // longest common prefixes:res[i]=lcp(a[i],a[i-1]) e.g. s="aba\0" will have res=[0,0,1,0] 
		int n=a.size(),h=0;
		v32 inv(n),res(n);
		for(int i=0;i<n;++i) inv[a[i]]=i;
		for(int i=0;i<n;++i){
			if(inv[i]>0){
				int p0=a[inv[i]-1];
				while(s[i+h]==s[p0+h]) h++;
				res[inv[i]]=h;
				if(h>0) h--;
			}
		}
		return res;
	}
};