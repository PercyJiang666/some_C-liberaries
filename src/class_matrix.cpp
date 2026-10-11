#include<bits/stdc++.h>
class Matrix{
private:
    int rows,cols;
    std::vector<std::vector<double>>M;
public:
    Matrix(){
        std::cout<<"please input the data of a matrix\n";
        std::cout<<"number of rows:";
        std::cin>>rows;
        std::cout<<"number of columns:";
        std::cin>>cols;
        M.resize(rows);
        for(int i=0;i<rows;i++){
            std::cout<<"the "<<cols<<" entries of "<<i+1<<" row:";
            for(int j=0;j<cols;j++)std::cin>>M[i][j];
        }
    }
    Matrix(int rownum,int columnum):rows(rownum),cols(columnum){
        M.resize(rows,std::vector<double>(cols));
    }
    std::vector<double>& operator[] (int rowindex){
        return M[rowindex];
    }
    const std::vector<double>& operator[] (int rowindex)const{
        return M[rowindex];
    }
    Matrix operator * (const Matrix& A)const{
        Matrix B(rows,A.cols);
        if(cols!=A.cols){
            std::cout<<"the multiply of matrix is not defined\n";
            return B;
        }
        for(int i=0;i<rows;i++)
            for(int j=0;j<A.cols;j++)
                for(int k=0;k<cols;k++)
                    B[i][j]+=M[i][k]*A[k][j];

    }
    
};
void solve(){
    Matrix A,B;

}
int main(){


}