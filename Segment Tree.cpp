struct node{
	// Data
	// node(): {} 
	node(): {};
};
struct segtree{
	vector<node> T;
	int N;
	void clear(int n){
		N=n;
		T.resize(4*N);
	}
	void merge(const node &a,const node &b,node &c){
		// c=a+b;
	}
	void build(int v,int tl,int tr){
		if(tl==tr){
			// T[v]= 
		}else{
			int tm=(tl+tr)>>1,lf=v<<1,rt=lf^1;;
			build(lf,tl,tm);
			build(rt,tm+1,tr);
			merge(T[lf],T[rt],T[v]); 
		}
	}
	node query(int v,int tl,int tr,int l,int r){
		if(l>r or tl>r or tr<l){
			return node(); // Return Zero for Data query	
		}if(l<=tl && tr<=r){
			return T[v];
		}
		int tm=(tl+tr)>>1,lf=v<<1,rt=lf^1;
		node res;
		merge(query(lf,tl,tm,l,min(r,tm)),query(rt,tm+1,tr,max(l,tm+1),r),res);
		return res;
	}
	node query(int v,int tl,int tr,int pos){
		if(tl>pos or tr<pos){
			return node(); // Return Zero for Data query
		}if(tl==tr){
			return T[v];
		}
		int tm=(tl+tr)>>1,lf=v<<1,rt=lf^1;
		if(pos<=tm) return query(lf,tl,tm,pos);
		else return query(rt,tm+1,tr,pos);
	}
	int q(int l,int r){
		return query(1,0,N-1,l,r).ans;
	}
	int q(int pos){
		return query(1,0,N-1,pos).ans;
	}
} st;