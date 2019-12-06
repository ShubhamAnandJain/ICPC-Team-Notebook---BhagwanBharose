struct MaxMatchingEdmonds{
    // Assume General Unweighted Directed Graph
    // O(V^3) edmonds for maximum matching
    vv32 g;
    v32 match,p,base;
    vector<bool> blossom;
    int n;
    int lca(int a,int b){
        vector<bool> used(match.size(),0);
        while(1){
          a=base[a];
          used[a]=1;
          if(match[a]==-1) break;
          a=p[match[a]];}
        while(1){
          b=base[b];
          if(used[b]) return b;
          b=p[match[b]];}}
    void markPath(int v,int b,int children) {
        for(;base[v]!=b;v=p[match[v]]){
          blossom[base[v]]=blossom[base[match[v]]]=1;
          p[v]=children;
          children=match[v];}}
    int findPath(int root) {
        vector<bool> used(n,0);
        p.assign(n,-1);
        base.assign(n,0);
        for(int i=0;i<n;++i) base[i] = i;
        used[root]=1;
        int qh=0;
        int qt=0;
        v32 q(n,0);
        q[qt++]=root;
        while(qh<qt){
          int v=q[qh++];
          for(int &to:g[v]){
            if(base[v]==base[to] || match[v]==to) continue;
            if(to==root || match[to]!=-1 && p[match[to]]!=-1){
              int curbase=lca(v,to);
              blossom.assign(n,0);
              markPath(v,curbase,to);
              markPath(to,curbase,v);
              for(int i=0;i<n;++i)
                if(blossom[base[i]]){
                  base[i]=curbase;
                  if(!used[i]){
                    used[i]=1;
                    q[qt++]=i;}}
            }else if(p[to]==-1){
              p[to]=v;
              if(match[to]==-1) return to;
              to=match[to];
              used[to]=1;
              q[qt++]=to;}}}
        return -1;}
    int maxMatching(vv32 &graph){
        n=graph.size();
        g=graph;
        match.assign(n,-1);
        p.assign(n,0);
        for(int i=0;i<n;++i){
          if(match[i]==-1){
            int v=findPath(i);
            while(v!=-1){
              int pv=p[v];
              int ppv=match[pv];
              match[v]=pv;
              match[pv]=v;
              v=ppv;}}}
        int matches=0;
        for(int i=0;i<n;++i) if(match[i]!=-1) ++matches;
        return matches/2;}};