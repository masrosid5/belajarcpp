#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> refleksiH(vector<vector<int>> m, int r, int c){
    for (int i = 0; i < r/2; i++){
        for (int j = 0; j < c; j++) {
            swap(m[i][j], m[r-i-1][j]);
        }
    }
    return m;
}

vector<vector<int>> refleksiV(vector<vector<int>> m, int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c/2; j++) {
            swap(m[i][j], m[i][c-j-1]);
        }
    }
    return m;
}

vector<vector<int>> transposeMatriksPersegi(vector<vector<int>> m, int n){
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            swap(m[i][j], m[j][i]);
        }
    }

    return m;
}

vector<vector<int>> transposeMatriksNM(vector<vector<int>> m, int r, int c){
    if (r == c) return transposeMatriksPersegi(m, r);

    vector<vector<int> > v(c, vector<int>(r));
    for (int j = 0; j < c; j++){
        for (int i = 0; i < r; i++){
            v[j][i] = m[i][j]; 
        }
    }

    return v;
}

vector<vector<int>> rotasi90(vector<vector<int>> m, int r, int c){
    vector<vector<int>> v = transposeMatriksNM(m, r, c);
    v = refleksiV(v, v.size(), v[0].size());
    return v;
}
vector<vector<int>> rotasi(vector<vector<int>> m, int r, int c, int sudut){
    int n = sudut/90;
    for (int i = 0; i < n; i++){
        m = rotasi90(m, m.size(), m[0].size());
    }
    return m;
}

void displayMatriks2d(const vector<vector<int>> &m, int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << m[i][j] << " ";
	    }
	    cout << endl;
    }
}

int main(){
    int N, M, X;
    cin >> N >> M >> X;

    string simbol;

    vector<vector<int>> v(N, vector<int>(M));
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < X; i++){
        cin >> simbol;


        if (simbol == "_") v = refleksiH(v, v.size(), v[0].size());
        else if (simbol == "|") v = refleksiV(v, v.size(), v[0].size());
        else if (simbol == "90") v = rotasi90(v, v.size(), v[0].size());
        else if (simbol == "180") v = rotasi(v, v.size(), v[0].size(),180);
        else v = rotasi(v, v.size(), v[0].size(),270);
    }
    displayMatriks2d(v, v.size(), v[0].size());
}