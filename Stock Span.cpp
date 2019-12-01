void stockspan(v32 &d,int n){ 
	// smallest index j such that j>i and d[j]>d[i]
	nxt.assign(n,n);
	// largest index j such that j<i and d[j]>=d[i]
	pre.assign(n,-1);
	int stk[n+10],ptr=0;
	forn(i,n){
		while(ptr && d[i]>d[stk[ptr-1]]) nxt[stk[--ptr]]=i;
		pre[i]= (ptr? stk[ptr-1]:-1);
		stk[ptr++]=i;
	}
}
v32 nxt,pr; // nxt index with val < cur and prev index with val < cur
void stockspan(v32 &d,int n){ 
	int stk[n+10],ptr=0;
	pr.assign(n,-1);
	forn(i,n){
		while(ptr && d[i]<=d[stk[ptr-1]]) --ptr;
		pr[i]= (ptr? stk[ptr-1]:-1);
		stk[ptr++]=i;
	}
	ptr=0;
	nxt.assign(n,n);
	forn(i,n){
		while(ptr && d[i]<d[stk[ptr-1]]) nxt[stk[--ptr]]=i;
		stk[ptr++]=i;
	}
}