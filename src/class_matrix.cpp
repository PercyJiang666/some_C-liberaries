#include<bits/stdc++.h>
class Matrix{
private:
    int rows,cols;
    std::vector<std::vector<double>>M;
public:
    Matrix(int rownum,int columnum):rows(rownum),cols(columnum){
        M.resize(rows,std::vector<double>(cols));
    }
};
int main(){


}