// https://www.hackerrank.com/challenges/append-and-delete/problem
string appendAndDelete(string s, string t, int k) {
    int m = s.size(), n = t.size(), i, lim = min(m, n);
    for(i = 0; i < lim; i++){
        if(s[i] != t[i])
            break;
    }
        
    int num_ops = m - i + n - i;  // necessary ops
    if(k < num_ops)  return "No";
    // it's OK to implement delete ops on empty string
    if(2 * i + num_ops <= k)  return "Yes";  
    // if you can't delete the entire s, you need to remove and recover
    // elements in s[:i]
    return ((k - num_ops) & 1)? "No": "Yes";
}
