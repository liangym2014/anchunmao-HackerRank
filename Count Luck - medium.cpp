// https://www.hackerrank.com/challenges/count-luck/problem?isFullScreen=false
class Matrix{
private:
    vector<string> matrix;
    int sx, sy;
    int count;
public:
    Matrix(vector<string> &matrix): matrix(matrix), count(0){
        // find starting point M
        for(int i = 0; i< (int)matrix.size(); i ++){
            for(int j = 0; j < (int)matrix[0].size(); j ++){
                if(matrix[i][j] == 'M'){
                    sx = i;
                    sy = j;
                    break;
                }
            }
        }
    }
    
    string find_path(int& k){
        dfs(sx, sy);   // mark the path from start to end wth '1'
        return count == k? "Impressed":"Oops!";
    }

    inline bool available_directions(int x, int y){
        if(x < 0 || x >= (int)matrix.size() ||
            y < 0 || y >= (int)matrix[0].size() ||
            matrix[x][y] == 'X' || matrix[x][y] == '1') return false;
        return true;
    }
     
    bool dfs(int x1, int y1){
        if(matrix[x1][y1] == '*'){
            matrix[x1][y1] = '1';
            return true;
        }
                
        bool path_found = false;
        int dir = 0;  // the number of available directions  
        
        matrix[x1][y1] = '1';   // mark path with '1'
        if(available_directions(x1 + 1, y1)){
            dir ++;
            if(!path_found && dfs(x1 + 1, y1)) path_found = true; 
        }

        if(available_directions(x1 - 1, y1)){
            dir ++;
            if(!path_found && dfs(x1 - 1, y1)) path_found = true; 
        }

        if(available_directions(x1, y1 + 1)){
            dir ++;
            if(!path_found && dfs(x1, y1 + 1)) path_found = true; 
        }

        if(available_directions(x1, y1 - 1)){
            dir ++;
            if(!path_found && dfs(x1, y1 - 1)) path_found = true; 
        }

        if(!path_found){
            matrix[x1][y1] = '.';  // unmark
            return false; 
        }
        // count this as the situation in need of waving a wand,
        // only when the current point belongs to the path
        if(dir > 1) count ++;
        return true;       
    }
      
};

string countLuck(vector<string> matrix, int k) {
    return Matrix(matrix).find_path(k); 
}
