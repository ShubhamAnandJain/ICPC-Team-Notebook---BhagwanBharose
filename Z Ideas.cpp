Gray codes:

Applications:
1. Gray code of n bits forms a Hamiltonian cycle on a 
hypercube, where each bit corresponds to one dimension.
2. Gray code can be used to solve the Towers of Hanoi 
problem. Let n denote number of disks. Start with Gray 
code of length n which consists of all zeroes (G(0)) and 
move between consecutive Gray codes (from G(i) to G(i+1)). 
Let i-th bit of current Gray code represent n-th disk 
(the least significant bit corresponds to the smallest 
disk and the most significant bit to the biggest disk).
Since exactly one bit changes on each step, we can treat 
changing i-th bit as moving i-th disk. Notice that there 
is exactly one move option for each disk (except the smallest one)
on each step (except start and finish positions). There 
are always two move options for the smallest disk but 
there is a strategy which will always lead to answer: if n 
is odd then sequence of the smallest disk moves looks 
like f→t→r→f→t→r→... where f is the initial rod, t is 
the terminal rod and r is the remaining rod), and if 
n is even: f→r→t→f→r→t→....

int gray (int n) {
    return n ^ (n >> 1);
}
int rev_g (int g) {
  int n = 0;
  for (; g; g >>= 1)
    n ^= g;
  return n;
}

Enumerating all submasks of a bitmask:

for (int s=m; ; s=(s-1)&m) {
 ... you can use s ...
 if (s==0)  break;
}

Sparse Table: 

int st[MAXN][K];

for (int i = 0; i < N; i++)
    st[i][0] = array[i];

for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

To get minimum of a range:

int j = log[R - L + 1];
int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);


Divide and Conquer DP:

Some dynamic programming problems have a recurrence of this form:
dp(i,j)=mink≤j{dp(i−1,k)+C(k,j)}
where C(k,j) is some cost function.

Say 1≤i≤n and 1≤j≤m, and evaluating C takes O(1) time. 
Straightforward evaluation of the above recurrence is O(nm2). 
There are n×m states, and m transitions for each state.

Let opt(i,j) be the value of k that minimizes the above expression. 
If opt(i,j)≤opt(i,j+1) for all i,j, then we can apply 
divide-and-conquer DP. This known as the monotonicity condition. 
The optimal "splitting point" for a fixed i increases as j increases.

int n;
long long C(int i, int j);
vector<long long> dp_before(n), dp_cur(n);

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr)
{
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    pair<long long, int> best = {INF, -1};

    for (int k = optl; k <= min(mid, optr); k++) {
        best = min(best, {dp_before[k] + C(k, mid), k});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

Lyndon factorization: We can get the minimum cyclic shift.
Factorize the string as s = w1w2w3...wn

string min_cyclic_string(string s) {
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n / 2) {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    return s.substr(ans, n / 2);
}

Rank of a matrix:

const double EPS = 1E-9;

int compute_rank(vector<vector<double>> A) {
    int n = A.size();
    int m = A[0].size();

    int rank = 0;
    vector<bool> row_selected(n, false);
    for (int i = 0; i < m; ++i) {
        int j;
        for (j = 0; j < n; ++j) {
            if (!row_selected[j] && abs(A[j][i]) > EPS)
                break;
        }

        if (j != n) {
            ++rank;
            row_selected[j] = true;
            for (int p = i + 1; p < m; ++p)
                A[j][p] /= A[j][i];
            for (int k = 0; k < n; ++k) {
                if (k != j && abs(A[k][i]) > EPS) {
                    for (int p = i + 1; p < m; ++p)
                        A[k][p] -= A[j][p] * A[k][i];
                }
            }
        }
    }
    return rank;
}

Determinant of a matrix:

const double EPS = 1E-9;
int n;
vector < vector<double> > a (n, vector<double> (n));

double det = 1;
for (int i=0; i<n; ++i) {
    int k = i;
    for (int j=i+1; j<n; ++j)
        if (abs (a[j][i]) > abs (a[k][i]))
            k = j;
    if (abs (a[k][i]) < EPS) {
        det = 0;
        break;
    }
    swap (a[i], a[k]);
    if (i != k)
        det = -det;
    det *= a[i][i];
    for (int j=i+1; j<n; ++j)
        a[i][j] /= a[i][i];
    for (int j=0; j<n; ++j)
        if (j != i && abs (a[j][i]) > EPS)
            for (int k=i+1; k<n; ++k)
                a[j][k] -= a[i][k] * a[j][i];
}

cout << det;

Generating all k-subsets:

vector<int> ans;

void gen(int n, int k, int idx, bool rev) {
    if (k > n || k < 0)
        return;

    if (!n) {
        for (int i = 0; i < idx; ++i) {
            if (ans[i])
                cout << i + 1;
        }
        cout << "\n";
        return;
    }

    ans[idx] = rev;
    gen(n - 1, k - rev, idx + 1, false);
    ans[idx] = !rev;
    gen(n - 1, k - !rev, idx + 1, true);
}

void all_combinations(int n, int k) {
    ans.resize(n);
    gen(n, k, 0, false);
}

Simpsons formula for integration:

const int N = 1000 * 1000; // number of steps (already multiplied by 2)

double simpson_integration(double a, double b){
    double h = (b - a) / N;
    double s = f(a) + f(b); // a = x_0 and b = x_2n
    for (int i = 1; i <= N - 1; ++i) { // Refer to final Simpson's formula
        double x = a + h * i;
        s += f(x) * ((i & 1) ? 4 : 2);
    }
    s *= h / 3;
    return s;
}

Picks theorem:

Given a certain lattice polygon with non-zero area.

We denote its area by S, the number of points with integer 
coordinates lying strictly inside the polygon by I and the 
number of points lying on polygon sides by B.

Then, the Pick formula states: S=I + B/2 − 1
In particular, if the values of I and B for a polygon are given, 
the area can be calculated in O(1) without even knowing the vertices.

Strongly Connected component and Condensation Graph:

    vector < vector<int> > g, gr;
    vector<bool> used;
    vector<int> order, component;

    void dfs1 (int v) {
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i)
            if (!used[ g[v][i] ])
                dfs1 (g[v][i]);
        order.push_back (v);
    }

    void dfs2 (int v) {
        used[v] = true;
        component.push_back (v);
        for (size_t i=0; i<gr[v].size(); ++i)
            if (!used[ gr[v][i] ])
                dfs2 (gr[v][i]);
    }

    int main() {
        int n;
        ... reading n ...
        for (;;) {
            int a, b;
            ... reading next edge (a,b) ...
            g[a].push_back (b);
            gr[b].push_back (a);
        }

        used.assign (n, false);
        for (int i=0; i<n; ++i)
            if (!used[i])
                dfs1 (i);
        used.assign (n, false);
        for (int i=0; i<n; ++i) {
            int v = order[n-1-i];
            if (!used[v]) {
                dfs2 (v);
                ... printing next component ...
                component.clear();
            }
        }
    }

