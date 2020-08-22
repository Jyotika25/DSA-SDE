class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       
        int n = matrix.size();
        //transpose
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        //reverse
        for(int i=0;i<matrix.size();i++)
        {
            reverse(matrix[i].begin() , matrix[i].end());
        }
        
    }
};
