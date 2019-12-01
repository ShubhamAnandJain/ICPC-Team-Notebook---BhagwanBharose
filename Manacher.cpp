Manacher
// Given a string s of length N, finds all palindromes as its substrings.
// p[0][i] = half length of longest even palindrome around pos i
// p[1][i] = longest odd at i (half rounded down i.e len 2*x+1).
//Time: O(N)
void manacher(const string& s){
int n=s.size();
v32 p[2]={v32(n+1),v32(n)};
forn(z,2) for(int i=0,l=0,r=0;i<n;++i){
int t=r-i+!z;
if(i<r) p[z][i]=min(t,p[z][l+t]);
int L=i-p[z][i],R=i+p[z][i]-!z;
while(L>=1 && R+1<n && s[L1]==s[R+1]) p[z][i]++,L--,R++;
if(R>r) l=L,r=R;}}