#include<bits/stdc++.h>
class Matrix{
private:
    int rows,cols;
    std::vector<double>M;
public:
    Matrix(){
        std::cout<<"please input the data of a matrix\n";
        std::cout<<"number of rows:";
        std::cin>>rows;
        std::cout<<"number of columns:";
        std::cin>>cols;
        M.resize(rows*cols);
        for(int i=0;i<rows;i++){
            std::cout<<"the "<<cols<<" entries of "<<i+1<<" row:";
            for(int j=0;j<cols;j++)std::cin>>(*this)(i,j);
        }
    }
    Matrix(int rownum,int columnum):rows(rownum),cols(columnum){
        M.resize(rows*cols);
    }
    double& operator() (int rowindex,int colindex){
        return M[rowindex*rows+colindex%cols];
    }
    const double& operator() (int rowindex,int colindex)const{
        return M[rowindex*rows+colindex%cols];
    }
    Matrix operator * (const Matrix& A)const{
        Matrix B(rows,A.cols);
        if(cols!=A.rows){
            std::cout<<"the multiply of matrix is not defined\n";
            return B;
        }
        for(int i=0;i<rows;i++)
            for(int j=0;j<A.cols;j++)
                for(int k=0;k<cols;k++)
                    B(i,j)+=((*this)(i,k))*A(k,j);
        return B;
    }
    void outputMatrix(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                std::cout<<std::setw(5)<<(*this)(i,j);    
            }
            std::cout<<'\n';
        }
    }
    
};
void tst(){
    Matrix A,B;
    std::cout<<"Matrix A:\n";
    A.outputMatrix();
    std::cout<<"Matrix B:\n";
    B.outputMatrix();
    std::cout<<"Matix A*B:\n";
    Matrix C(A*B);
    C.outputMatrix();
    //(A*B).outputMatrix();

}
int main(){
    tst();
    return 0;
}