// Given a set of distinct integers, print the size of a maximal subset of S where the sum of any 2 numbers in S' is not evenly divisible by k.
// https://www.hackerrank.com/challenges/non-divisible-subset/problem
int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> rem(k);
    for(auto &n: s)
        rem[n % k] ++;

    if(rem[0] > 1)
        rem[0] = 1;
    
    int ans = rem[0];    
    for(int l = 1, r = k - 1; l < r; l ++, r --)
        ans += max(rem[l], rem[r]);
    
    if((k & 1) == 0 && rem[k >> 1] >= 1)
        ans += 1;
    return ans;
}
