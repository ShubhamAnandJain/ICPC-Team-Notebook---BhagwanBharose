//Description: pi[x] computes the length of the longest 
//prefix of s that ends at x, other than s[0...x] itself (abacaba -> 0010123).
//Can be used to find all occurrences of a string.
//Time: O(n)
v32 pi(const string& s){
	v32 p(s.size());
	forsn(i,1,s.size()){
		int g=p[i-1];
		while(g && s[i]!=s[g]) g=p[g-1];
		p[i]=g+(s[i]==s[g]);
	}
	return p;
}
// v32 of all ind. of occ. of pat in s
v32 match(const string& s,const string& pat){
	v32 p=pi(pat+'\0'+s),res;
	forsn(i,(int)p.size()-(int)s.size(),p.size())
		if(p[i]==pat.size()) res.pb(i-2*pat.size());
	return res;
}