// Given a set of arrays of size n and an integer k, you have to find the maximum integer for each and every contiguous subarray of size k for each of the given arrays.
// https://www.hackerrank.com/challenges/deque-stl/problem

void printKMax(int arr[], int n, int k){
    deque<int> q;
    for(int l = 0, i = 0; i < n; i ++){
        while(!q.empty() && arr[q.back()] < arr[i])
            q.pop_back();        
        if(q.empty() || arr[q.back()] > arr[i])
            q.push_back(i);
        else if(arr[q.back()] == arr[i])
            q.back() = i;
        
        if(i - l + 1 == k){
            cout<<arr[q.front()]<<' ';
            if(q.front() == l)
                q.pop_front();
            ++ l;
        }
    }
    cout<<'\n';
}
