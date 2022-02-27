// https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
string organizingContainers(vector<vector<int>> container) {
    int n = container.size();
    unordered_map<long long, int> row_sum;
    vector<long long> col_sum(n);
    
    for(int i = 0; i < n; i ++){
        long long sum = accumulate(container[i].begin(), 
                        container[i].end(), (long long)0);
        row_sum[sum] ++;

        for(int j = 0; j < n; j ++){
            col_sum[j] += (long long)container[i][j];
        }
    }
    
    for(int j = 0; j < n; j ++){
        if(row_sum.count(col_sum[j])){
            row_sum[col_sum[j]] --;
            if(row_sum[col_sum[j]] == 0)
                row_sum.erase(col_sum[j]);
        }
        else
            return "Impossible";
    }
    return "Possible";
}
