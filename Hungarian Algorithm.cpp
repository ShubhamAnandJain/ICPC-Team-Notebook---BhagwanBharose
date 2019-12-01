struct Hungarian{
  //Important: cost matrix a[1..n][1..m]>=0,n<=m (works with negative costs)
  // O(V^3) Use p to find matching of 1..m
  vv64 a;
  v64 u,v;
  v32 p,way;
  int n,m;
  Hungarian(int n,int m): n(n),m(m),u(n+1,0),v(m+1,0),p(m+1,0),way(m+1,0),a(n+1,v64(m+1,0)){}
  void addEdge(int u,int v,ll val){
    a[u][v]=val;
  }
  ll solveAssignmentProblem(){
    for(int i=1;i<=n;++i){
      p[0]=i;
      int j0=0;
      v64 minv(m+1,2e17+10);
      vector<bool> used(m+1,0);
      do{
        used[j0] = true;
        int i0=p[j0];
        ll delta=2e17+10;
        int j1=0;
        for(int j=1;j<=m;++j){
          if(!used[j]){
            ll cur=a[i0][j]-u[i0]-v[j];
            if(cur<minv[j]){
              minv[j]=cur;
              way[j]=j0;
            }
            if(minv[j]<delta){
              delta=minv[j];
              j1=j;
            }
          }
        }
        for(int j=0;j<=m;++j){
          if(used[j]){
            u[p[j]]+=delta;
            v[j]-=delta;
          }else minv[j]-=delta;
        }
        j0=j1;
      }while(p[j0]!=0);
      do{
        int j1=way[j0];
        p[j0]=p[j1];
        j0=j1;
      }while(j0!=0);
    }
    return -v[0];
  }
};