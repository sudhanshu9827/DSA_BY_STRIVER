#include <bits/stdc++.h>
using namespace std;

void printSubmatrices(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    for(int r1 = 0; r1 < n; r1++) {
        for(int c1 = 0; c1 < m; c1++) {
            for(int r2 = r1; r2 < n; r2++) {
                for(int c2 = c1; c2 < m; c2++) {

                    cout << "Submatrix:\n";
                    for(int i = r1; i <= r2; i++) {
                        for(int j = c1; j <= c2; j++) {
                            cout << mat[i][j] << " ";
                        }
                        cout << "\n";
                    }
                    cout << "\n";
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2},
        {3, 4}
    };

    printSubmatrices(mat);

    return 0;
}



// for square matrix 


#include <bits/stdc++.h>
using namespace std;

void printSquareSubmatrices(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    for(int r1 = 0; r1 < n; r1++) {
        for(int c1 = 0; c1 < m; c1++) {

            // Try all possible square sizes
            for(int len = 1; r1 + len - 1 < n && c1 + len - 1 < m; len++) {

                int r2 = r1 + len - 1;
                int c2 = c1 + len - 1;

                cout << "Square Submatrix:\n";
                for(int i = r1; i <= r2; i++) {
                    for(int j = c1; j <= c2; j++) {
                        cout << mat[i][j] << " ";
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printSquareSubmatrices(mat);
    return 0;
}