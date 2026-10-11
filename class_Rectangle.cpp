#include<bits/stdc++.h>
class Rectangle{
public:
    Rectangle():width(5),height(5){};
    Rectangle(const double& w,const& double h):width(w),height(h){
        if(width<=0||height<=0)throw std::invalid_argument("edge must bigger than 0\n");
    }
    double getWidth()const{
        return width;
    }
    double getHeight()const{
        return height;
    }
    double getArea()const{
        return width*height;
    }
    double getDiagonal()const{
        return std::sqrt(height*height+width*width);
    }
    std::string getDataString()const{
        //printf("height:%lf width:%lf\n",width,height);
        return "width:"+std::to_string(width)+" height:"+std::to_string(height);
    }
    friend Rectangle operator+(const Rectangle& R1,const Rectangle& R2){
        return Rectangle(R1.width+R2.width,R1.height+R2.height);
    }

private:
    double width,height;
};
class TestRectangle{
public:
    TestRectangle(const Rectangle& sub):subject(sub){};
    void Test(){
        printf("GetWidth:%lf\nGetHeight:%lf\nGetArea:%lf\nGetDiagonal:%lf\nGetDataString:%s\n",subject.getWidth(),subject.getHeight(),subject.getArea(),subject.getDiagonal(),subject.getDataString().c_str());
    }
private:
    Rectangle subject;
};

