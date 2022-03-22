//https://www.hackerrank.com/challenges/the-grid-search/problem
string gridSearch(vector<string> G, vector<string> P) {
    int m = P.size(), n = P[0].size(), a = G.size(), b = G[0].size();
    for(int i = 0, lim_i = a - m; i <= lim_i; ++ i){
        size_t pos = G[i].find(P[0]);
        while(pos != string::npos){
            bool found = true;
            // compare G[i: i + m, pos: pos + n] with P
            for(int j = 0; j < m; j ++){
                if(G[i + j].substr(pos, n) != P[j]){
                    found = false;
                    break;
                }
            }
            if(found)  return "YES";
            pos = G[i].find(P[0], pos + 1);
        }
    }
    return "NO";
}
