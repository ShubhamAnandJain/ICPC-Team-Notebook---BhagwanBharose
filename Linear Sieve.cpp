int mu[LIM],is_com[LIM];
v32 pr;
void sieve(){
    mu[1]=1;
    forsn(i,2,LIM){
        if(!is_com[i]) pr.pb(i),mu[i]=-1;
        forstl(it,pr){
            if(it*i>=LIM) break;
            is_com[i*it]=1;
            if(i%it==0){
                mu[i*it]=0;
                break;
            }else{
                mu[i*it]=mu[i]*mu[it];
            }
        }
    }
}