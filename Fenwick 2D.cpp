//BIT<N, M, K> b; N x M x K (3-dimensional) BIT
//b.update(x, y, z, P); // add P to (x,y,z)
//b.query(x1, x2, y1, y2, z1, z2); // query between (x1, y1, z1) and (x2, y2, z2)
inline int lastbit(int x){
  return x&(-x);}
template <int N, int... Ns>
struct BIT<N, Ns...> {
  BIT<Ns...> bit[N + 1];
  template<typename... Args>
  void update(int pos, Args... args) {
    for (; pos <= N; bit[pos].update(args...), pos += lastbit(pos));}
  template<typename... Args>
  int query(int l, int r, Args... args) {
    int ans = 0;
    for (; r >= 1; ans += bit[r].query(args...), r -= lastbit(r));
    for (--l; l >= 1; ans -= bit[l].query(args...), l -= lastbit(l));
    return ans;}};
// Another implementation
struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;
    // init(...) { ... }
    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;}
    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;}};