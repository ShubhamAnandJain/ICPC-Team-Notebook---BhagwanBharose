// Z Algorithm
// Z[i] is the length of the longest substring starting from S[i]
// which is also a prefix of S
// O(n)
void z_func(v32 &s,v32 &z){
	int L=0,R=0;
	int sz=s.size();
	z.assign(sz,0);
	forsn(i,1,sz){
		if(i>R){
			L=R=i;
			while(R<sz && s[R-L]==s[R]) R++;
			z[i]=R-L; R--;
		}else{
			int k=i-L;
			if(z[k]<R-i+1) z[i]=z[k];
			else{
				L=i;
				while(R<sz && s[R-L]==s[R]) R++;
				z[i]=R-L; R--;   
			}
		}
	}
}