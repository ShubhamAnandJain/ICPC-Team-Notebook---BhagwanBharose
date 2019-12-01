int MOD1=MOD;
inline ll add(ll a,ll b){
	return (a+b)%MOD1;
}
inline ll mult(ll a,ll b){
	return a*b%MOD1;
}
struct matrix{
	int arr[105][105]={0};
	int SZ;
	void reset(int sz){
		SZ=sz;
		//memset(arr,0,sizeof(arr));
	}
	void makeiden(int sz){
		reset(sz);
		for(int i=0;i<SZ;i++){
			arr[i][i]=1;
		}
	}
	matrix operator +(const matrix &o)const{
		matrix res;
		res.reset(SZ);
		for(int i=0;i<SZ;i++){
			for(int j=0;j<SZ;j++){
				res.arr[i][j]=add(arr[i][j],o.arr[i][j]);
			}
		}
		return res;
	}
	matrix operator *(const matrix &o)const{
		matrix res;
		res.reset(SZ);
		for(int i=0;i<SZ;i++){
			for(int j=0;j<SZ;j++){
				res.arr[i][j]=0;
				for(int k=0;k<SZ;k++){
					res.arr[i][j]=add(res.arr[i][j],mult(arr[i][k],o.arr[k][j]));
				}
			}
		}
		return res;
	}
};
matrix mpower(matrix a,int sz,ll b){
	matrix res;
	res.makeiden(sz);
	while(b){
		if(b&1){
			res=res*a;
		}
		a=a*a;
		b>>=1;
	}
	return res;
}