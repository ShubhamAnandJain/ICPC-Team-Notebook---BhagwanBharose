Pre-submit:
Are time limits close? If so, generate max cases. 
Is the memory usage fine? Could anything overflow? Make sure
to submit the right file.

Wrong answer: Print your solution! Print debug output, as
well. 
Are you clearing all datastructures between test
cases? 
Can your algorithm handle the whole range of
input? 
Read the full problem statement again. Do you
handle all corner cases correctly? Have you understood the
problem correctly? 
Any uninitialized variables? Any
overflows? Confusing N and M, i and j, etc.? 
Are you sure
your algorithm works? What special cases have you not
thought of? 
Are you sure the STL functions you use work
as you think? Add some assertions, maybe resubmit
Create some testcases to run your algorithm on. Go
through the algorithm for a simple case. 
Go through this list again. Explain your algorithm to a team mate. 
Ask the team mate to look at your code. Go for a small walk, 
e.g. to the toilet. Is your output format correct?
Rewrite your solution from the start or let a team mate do it.

Runtime error: Have you tested all corner cases locally?
Any uninitialized variables? Are you reading or writing
outside the range of any vector? Any assertions that might
fail? Any possible division by 0? (mod 0 for example)

Any possible infinite recursion? Invalidated pointers or
iterators? Are you using too much memory? Debug with
resubmits. 

Time limit exceeded: Do you have any possible infinite loops? 
What is the complexity of your algorithm? Are you copying a 
lot of unnecessary data? (References) How big is the input 
and output? (consider scanf) Avoid vector, map. (use
arrays/unordered_map) What do your team mates think
about your algorithm?

Memory limit exceeded: What is the max amount of
memory your algorithm should need? Are you clearing all
datastructures between test cases?

Primes - 10001st prime is 1299721, 100001st prime is
15485867 Large primes - 999999937, 1e9+7, 987646789,
987101789 78498 primes less than 10^6 The number of
divisors of n is at most around 100, for n<5e4, 500 for
n<1e7, 2000 for n<1e10, 200,000 for n<1e19 7! 5040, 8!
40320, 9! 362880, 10! 362880, 11! 4.0e7, 12! 4.8e8, 15!
1.3e12, 20! 2e18

The number of divisors of n is at most around 100 for n <
5e4, 500 for n < 1e7, 2000 for n < 1e10, 200 000 for n <
1e19.

Articulation points and bridges articulation point:- there
exist child : dfslow[child] >= dfsnum[curr] bridge :- tree ed:
dfslow[ch] > dfsnum[par];

A connected multigraph has an Euler path but not an Euler
circuit if and only if it has exactly two vertices of odd
degree

Binomial coefficients - base case ncn and nc0 = 1;
recursion is nCk = (n-1)C(k-1)+(n-1)Ck

Catalan numbers - used in valid paranthesis expressions -
formula is Cn = summation{i=0 to n-1} (CiCn-i-1); Another
formula is Cn = 2nCn/(n+1). There are Cn binary trees of n
nodes and Cn-1 rooted trees of n nodes

Derangements - D(n) = (n-1)(D(n-1)+D(n-2))

Burnsides Lemma - number of equivalence classes =
(summation I(pi))/n : I(pi) are number of fixed points. Usual
formula: [summation {i=0 to n-1} k^gcd(i,n)]/n

Stirling numbers - first kind - permutations of n elements
with k disjoint cycles. s(n+1,k) = ns(n,k)+s(n,k-1). s(0,0) =
1, s(n,0) = 0 if n>0. Summation {k=0 to n} s(n,k) = n!

Stirling numbers - Second kind - partition n objects into k
non empty subsets. S(n+1,k) = kS(n,k) + S(n,k-1). S(0,0) =
1, S(n,0) = 0 if n>0. S(n,k) = (summation{j=0 to k} [(-1)^(kj)kCjj^n])/k!

Hermite identity - summation{k=0 to n-1} floor[(x+k)/n] =
floor[nx]

Kirchoff matrix tree theorem - number of spanning trees in
a graph is determinant of Laplacian Matrix with one row
and column removed, where L = degree matrix - adjacency
matrix

Expected value tricks: 
1. Linearity of Expectation: E(X+Y) = E(X)+E(Y) 
2. Contribution to the sum - If we want to find
the sum over many ways/possibilities, we should consider
every element (maybe a number, or a pair or an edge) and
count how many times it will be added to the answer. 
3. Forcindependent events - E(XY) = E(X)E(Y) 
4. Ordered pairs (Super interpretation of square) - 
The square of the size of a set is equal to the number 
of ordered pairs of elements in the set. So we iterate 
over pairs and for each we compute the contribution to 
the answer. Similarly, the k-th power is equal to the 
number of sequences (tuples) of length k. 
5. Powers technique - If you want to maintain the sum of k-th
powers, it might help to also maintain the sum of smaller
powers. For example, if the sum of 0-th, 1-th and 2-nd
powers is S0, S1 and S2, and we increase every element
by x, the new sums are S0, S1+S0·x and S2 + 2S1x + x^2S0.