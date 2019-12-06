map<int, int> active;
int ans = 0, n;

void init(){
	active[-1] = -1;
	active[2e9] = 2e9;
	active[1] = n;
	ans = n;}

void add(int L, int R){ //Always remove [L, R] before adding
	active[L]=R;
	ans+=R-L+1;}

void remove(int L, int R){
	int removed=0;
	auto it = active.lower_bound(L);
	it--;
	if(it->second>=L){
		active[L] = it->second;
		it->second = L-1;}
	it++;
	while(it->first <= R){
		if(it->second > R){
			removed+=R + 1 - it->first;
			active[R+1] = it->second;
		}
		else
			removed+= it->second - it->first + 1;
		auto it2=it;
		it++;
		active.erase(it2);}
	ans-=removed;}