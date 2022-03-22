//https://www.hackerrank.com/challenges/maxsubarray/problem
vector<int> maxSubarray(vector<int> arr) {
    int subsequence = INT_MIN, subarray = INT_MIN, sum = 0;
    for(auto &e : arr){
        if(e >= 0){
            if(subsequence >= 0)
                subsequence += e;
            else
                subsequence = e;
        }
        else if(subsequence < 0)
            subsequence = max(subsequence, e);

        if(sum >= 0)
            sum += e;
        else
            sum = e;
        subarray = max(subarray, sum);    
    }
    return {subarray, subsequence};
}
