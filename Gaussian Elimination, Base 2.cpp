struct Gaussbase2{
    int numofbits=20;
    int rk=0;
    v32 Base;
    Gaussbase2() {clear();}
    void clear(){
        rk=0;
        Base.assign(numofbits,0);
    }
    Gaussbase2& operator = (Gaussbase2 &g){
        forn(i,numofbits) Base[i]=g.Base[i];
        rk=g.rk;
    }
    bool canbemade(int x){
        rforn(i,numofbits-1) x=min(x,x^Base[i]);
        return x==0;
    }
    void Add(int x){
        rforn(i,numofbits-1){
            if((x>>i)&1){
                if(!Base[i]){
                    Base[i]=x;
                    rk++;
                    return;
                }else x^=Base[i];
            }
        }
    }
    int maxxor(){
        int ans=0;
        rforn(i,numofbits-1){
            if(ans < (ans^Base[i])) ans^=Base[i];
        }
        return ans;
    }
};