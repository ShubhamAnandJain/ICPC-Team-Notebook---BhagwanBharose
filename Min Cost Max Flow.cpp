// Mincost Maxflow : O(E^2) 
// [Hell-Johnson MinCostMaxFlow using Dijstra with potential & Fibonnaci Heap]
// Negative cost cycles are not supported.
struct MCMF{
  struct Edge{
    int u,v,rind;
    FLOW cap,flow;
    COST cost;
  };
  int N;
  vector<COST> pot,dist;
  vector<vector<Edge> > v;
  vector<pair<int,int> > par;
  MCMF(int n): N(n),dist(n),v(n),par(n){}
  void AddEdge(int to,int from,int cap,int cost){
    if(to==from){
      assert(cost>=0);
      return;
    }
    int i1=v[to].size(),i2=v[from].size();
    v[to].push_back({to,from,i2,cap,0,cost});
    v[from].push_back({from,to,i1,0,0,-cost});
  }
  void setpi(int s){
    pot.assign(N,CINF);
    pot[s]=0;
    int ch=1,ite=N;
    COST cur,nw;
    while(ch-- && ite--){
      for(int i=0;i<N;++i){
        if(pot[i]!=CINF){
          cur=pot[i];
          for(auto &e: v[i]){
            if(e.cap>0 && (nw=cur+e.cost)<pot[e.v]){
              pot[e.v]=nw; ch=1;
            }
          }
        }
      }
    }
    assert(ite>=0); // Else negative cycle
  }
  bool path(int s,int t){
    fill(dist.begin(),dist.end(),CINF);
    dist[s]=0;
    __gnu_pbds::priority_queue<pair<COST,int> > pq;
    vector<decltype(pq)::point_iterator> its(N);
    pq.push({0,s});
    COST curr,val;
    int node,cnt;
    bool ok=0;
    while(!pq.empty()){
      tie(curr,node)=pq.top();
      pq.pop();
      curr=-curr;
      if(curr!=dist[node]) continue;
      curr+=pot[node];
      if(node==t) ok=1;
      cnt=0;
      for(auto &e: v[node]){
        if(e.cap>e.flow && (val=curr+e.cost-pot[e.v])<dist[e.v]){
          dist[e.v]=val;
          par[e.v]=make_pair(node,cnt);
          if(its[e.v]==pq.end()) its[e.v]=pq.push({-val,e.v});
              else pq.modify(its[e.v],{-val,e.v});
        }
        ++cnt;
      }
    }
    for(int i=0;i<N;++i){
      pot[i]=min(pot[i]+dist[i],FINF);
    }
    return ok;
  }
  pair<FLOW,COST> SolveMCMF(int s,int t,FLOW need=FINF,bool neg=0){
    FLOW tot=0,cflow=0; COST tcost=0;
    if(s==t) return {tot,tcost};
    if(!neg) pot.assign(N,0);
    else setpi(s);
    int cntr=0;
    while(path(s,t) && need>0){
      cflow=need;
      for(int node=t,u,ind;node!=s;node=u){
        u=par[node].first;
        ind=par[node].second;
        cflow=min(cflow,v[u][ind].cap-v[u][ind].flow);
      }
      tot+=cflow; need-=cflow;
      for(int node=t,u,ind,rind;node!=s;node=u){
        u=par[node].first;
        ind=par[node].second;
        rind=v[u][ind].rind;
        v[u][ind].flow+=cflow;
        v[node][rind].flow-=cflow;
      }
    }
    return {tot,tcost};
  }
};
