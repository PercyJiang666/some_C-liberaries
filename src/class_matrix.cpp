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
    Matrix operator +(const Matrix& A)const{
        Matrix B(*this);
        if(rows!=A.rows||cols!=A.cols){
            throw std::invalid_argument("the add of"+std::to_string(rows)+","+std::to_string(cols)+"and"
                                        +std::to_string(A.rows)+","+std::to_string(A.cols)+"is not defined\n");
        }
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                B(i,j)+=A(i,j);
        return B;
    }
    friend Matrix operator *(const double c,const Matrix& M){
        Matrix R(M);
        for(int i=0;i<M.rows;i++)
            for(int j=0;j<M.cols;j++)
                R(i,j)*=c;
        return R;
    }
    friend Matrix operator *(const Matrix& M,const double c){
        return c*M;
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
            throw std::invalid_argument("the multiply of"+std::to_string(rows)+","+std::to_string(cols)+"and"
                                        +std::to_string(A.rows)+","+std::to_string(A.cols)+"is not defined\n");
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
    (A*B).outputMatrix();
    std::cout<<"Matrix A+B:\n";
    (A+B).outputMatrix();
    std::cout<<"Please input a const:";
    double c;
    std::cin>>c;
    std::cout<<"Matrix cA:\n";
    (c*A).outputMatrix();
    std::cout<<"\n\n\n";
    //(A*B).outputMatrix();

}
int main(){
    while(1)tst();
    return 0;
}
