// https://www.hackerrank.com/challenges/bear-and-steady-gene/problem?isFullScreen=false
inline bool find_all(vector<int>& count, unordered_map<char, int>& m){
    for(auto &[k,v]:m){
        if(count[k - 'A'] < v) return false;
    }
    return true;
}

int steadyGene(string gene) {
    vector<int> count(26,0);
    for(auto &c: gene){
        count[c - 'A'] ++;
    }
    int target = (int)gene.size() / 4;
    unordered_map<char, int> m;
    
    for(auto &c: {'A', 'C','G','T'}){
        if(count[c - 'A'] > target){
            m[c] = count[c - 'A'] - target;
        }
        count[c-'A'] = 0;
    }
    
    if(m.empty()) return 0;
    
    int l = INT_MAX, res = INT_MAX;
    for(auto &[k, v]: m){
        int pos = gene.find(k);
        l = min(l, pos);
    }

    for(int i = l; i < gene.size(); i ++){
        count[gene[i]-'A'] ++;
        while(find_all(count, m)){
            res = min(res, i - l + 1);
            count[gene[l++] - 'A'] --;
            while(!m.count(gene[l])) l ++;
        }
    }
    return res;
}
