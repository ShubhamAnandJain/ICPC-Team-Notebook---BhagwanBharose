struct AhoCorasick{
	enum {alpha=26,first='a'};
	struct Node{
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
		Node(int v){memset(next,v,sizeof(next));}
	};
	vector<Node> N;
	vector<int> backp;
	inline void insert(string &s,int j){
		assert(!s.empty());
		int n=0;
		for(auto &c: s){
			int &m=N[n].next[c-first];
			if(m==-1){n=m=N.size(); N.emplace_back(-1);}
			else n=m;
		}
		if(N[n].end==-1) N[n].start=j;
		backp.push_back(N[n].end);
		N[n].end=j;
		N[n].nmatches++;
	}
	void clear(){
		N.clear();
		backp.clear();
	}
	void create(vector<string>& pat){
		N.emplace_back(-1);
		for(int i=0;i<pat.size();++i) insert(pat[i],i);
		N[0].back=N.size();
		N.emplace_back(0);
		queue<int> q;
		for(q.push(0);!q.empty();q.pop()){
			int n=q.front(),prev=N[n].back;
			for(int i=0;i<alpha;++i){
				int &ed=N[n].next[i],y=N[prev].next[i];
				if(ed==-1) ed=y;
				else{
					N[ed].back=y;
					(N[ed].end==-1 ? N[ed].end:backp[N[ed].start])=N[y].end;
					N[ed].nmatches+=N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	ll find(string word){
		int n=0;
		// vector<int> res; 
		ll count=0;
		for(auto &c: word){
			n=N[n].next[c-first];
			// res.push_back(N[n].end);
			count+=N[n].nmatches;
		}
		return count;
	}
};
struct AhoOnline{
	int sz=0;
	vector<string> v[25];
	AhoCorasick c[25];
	void add(string &p){
		int val=__builtin_ctz(~sz);
		auto &cur=v[val];
		for(int i=0;i<val;++i){
			for(auto &it: v[i]) cur.push_back(it);
			c[i].clear();
			v[i].clear();
		}
		cur.push_back(p);
		c[val].create(cur);
		++sz;
	}
	ll query(string &p){
		ll ans=0;
		for(int i=0;i<25;++i){
			if((1<<i)&sz) ans+=c[i].find(p);
			if((1<<i)>=sz) break;
		}
		return ans;
	}
} add,del;