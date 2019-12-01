ull mulm(ull a,ull b,ull MOD){
  ull res=0;
  a%=MOD,b%=MOD;
  while(b){
    if(b&1LL) res=(res+a)%MOD;
    b>>=1;
    a=(a+a)%MOD;
  }
  return res;
}
ull powm(ull x,ull pw,ull MOD){ //return x^pw % MOD
  x%=MOD;
  ull res=1;
  while(pw){
    if(pw&1LL) res=mulm(res,x,MOD);
    pw>>=1;
    x=mulm(x,x,MOD);
  }
  return res;
}
inline ull inv(ull x,ull MOD){
  return powm(x,MOD-2,MOD); 
}
bool prime(ull p){
  if(p==2) return 1;
  if(p==1 || !(p&1LL)) return 0;
  ull s=p-1;
  while(!(s&1LL)) s/=2;
  forn(i,15){
    ull a=rand()%(p-1)+1,tmp=s;
    ull mod=powm(a,tmp,p);
    while(tmp!=p-1 && mod!=1 && mod!=p-1){
      mod=mulm(mod,mod,p); 
      tmp<<=1;
    }
    if(mod!=p-1 && !(tmp&1LL)) return 0;
  }
  return 1;
}