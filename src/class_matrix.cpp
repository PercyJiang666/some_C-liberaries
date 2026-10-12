#include<bits/stdc++.h>
template <typename T>
class Matrix{
private:
    int rows,cols;
    std::vector<T>M;
public:
    Matrix(){
        rows=cols=0;
    }
    Matrix(int rownum,int columnum):rows(rownum),cols(columnum){
        M.resize(rows*cols,0);
    }
    int getRows()const{
        return rows;
    }
    int getCols()const{
        return cols;
    }
    T& operator() (int rowindex,int colindex){
        if(rowindex>=rows||colindex>=cols||rowindex<0||colindex<0){
            throw std::invalid_argument("the index of "+std::to_string(rows)+","+std::to_string(cols)+"Matrix is not valid\n");
        }
        return M[rowindex*cols+colindex];
    }
    const T& operator() (int rowindex,int colindex)const{
        if(rowindex>=rows||colindex>=cols||rowindex<0||colindex<0){
            throw std::invalid_argument("the index of "+std::to_string(rows)+","+std::to_string(cols)+"Matrix is not valid\n");
        }
        return M[rowindex*cols+colindex];
    }
    Matrix operator +(const Matrix& A)const{
        if(rows!=A.rows||cols!=A.cols){
            throw std::invalid_argument("the add of "+std::to_string(rows)+","+std::to_string(cols)+" and "
                                        +std::to_string(A.rows)+","+std::to_string(A.cols)+" is not defined\n");
        }
        Matrix B(*this);
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                B(i,j)+=A(i,j);
        return B;
    }
    Matrix operator -()const{
        Matrix B(*this);
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                B(i,j)=-B(i,j);
        return B;
    }
    Matrix operator -(const Matrix& M)const{
        if(rows!=M.rows||cols!=M.cols){
            throw std::invalid_argument("the minus of "+std::to_string(rows)+","+std::to_string(cols)+" and "
                                        +std::to_string(M.rows)+","+std::to_string(M.cols)+" is not defined\n");
        }
        Matrix B(*this);
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                B(i,j)-=M(i,j);
        return B;
    }
    friend Matrix<T> operator *(const T c,const Matrix& M){
        Matrix R(M);
        for(int i=0;i<M.rows;i++)
            for(int j=0;j<M.cols;j++)
                R(i,j)*=c;
        return R;
    }
    friend Matrix<T> operator *(const Matrix& M,const T c){
        return c*M;
    }
    Matrix operator * (const Matrix& A)const{
        Matrix B(rows,A.cols);
        if(cols!=A.rows){
            throw std::invalid_argument("the multiply of "+std::to_string(rows)+","+std::to_string(cols)+" and "
                                        +std::to_string(A.rows)+","+std::to_string(A.cols)+" is not defined\n");
        }
        for(int i=0;i<rows;i++)
            for(int k=0;k<cols;k++)
                for(int j=0;j<A.cols;j++)
                    B(i,j)+=((*this)(i,k))*A(k,j);
        return B;
    }    
    void inputMatrix(){
        std::cout<<"please input the data of a matrix\n";
        std::cout<<"number of rows:";
        std::cin>>rows;
        std::cout<<"number of columns:";
        std::cin>>cols;
        M.resize(rows*cols,0);
        for(int i=0;i<rows;i++){
            std::cout<<"the "<<cols<<" entries of "<<i+1<<" row:";
            for(int j=0;j<cols;j++)std::cin>>(*this)(i,j);
        }
    }
    void outputMatrix()const{
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                std::cout<<std::setw(5)<<(*this)(i,j);    
            }
            std::cout<<'\n';
        }
    }
    
};

void tst(){
    Matrix<int> A;
    Matrix<int> B;
    A.inputMatrix();
    std::cout<<"Matrix A:\n";
    A.outputMatrix();
    B.inputMatrix();
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
    try{
        system("chcp 65001 > nul");
        while(1)tst();
    }
    catch(const std::exception& e){
        std::cout<<"\n程式發生標準異常\n";
        std::cout<<"錯誤原因e.what():"<<e.what()<<'\n';
        return 1;
    }
    catch(...){
        std::cout<<"\n程式發生未知異常\n";
        return 1;
    }
    return 0;
}
