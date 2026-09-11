class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        if (original.size() != m * n)
            return {};

        vector<vector<int>> mat(m, vector<int>(n));

        for (int i = 0; i < original.size(); i++) {
            int r = i / n;
            int c = i % n;

            mat[r][c] = original[i];
        }

        return mat;
    }
};