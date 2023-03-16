#include <iostream>
#include <cmath>

namespace points {

    struct Point {
        int x;
        int y;
    };

    void readPoint(Point & point){
        std::cin>>point.x;
        std::cin>>point.y;
    }

    void printPoint(const Point& point){
        std::cout<<point.x<<" "<<point.y;
    }
}
namespace triangles {

    struct Triangle {
        points::Point pt1;
        points::Point pt2;
        points::Point pt3;
    };
    void readTriangle(Triangle& triangle ){
        points::readPoint(triangle.pt1);
        points::readPoint(triangle.pt2);
        points::readPoint(triangle.pt3);

    }
    void printTriangle(const Triangle& triangle){
        points::printPoint(triangle.pt1);
        std::cout<<" ";
        points::printPoint(triangle.pt2);
        std::cout<<" ";
        points::printPoint(triangle.pt3);
        std::cout<<" ";
    }
    double findSides(points::Point pt1,points::Point pt2){
        double side;
        side= sqrt((pt1.x-pt2.x)*(pt1.x-pt2.x)+(pt1.y-pt2.y)*(pt1.y-pt2.y));

        return side;
    }
}

void readArray(triangles::Triangle* arr,int n){

    for(int i=0;i<n;i++){
        triangles::readTriangle(arr[i]);
    }
}
void printArray(const triangles::Triangle*arr,const double* areaArr,int n){
    for(int i=0;i<n;i++){

        triangles::printTriangle(arr[i]);
        std::cout<<" Areas is:"<<areaArr[i];
    }
}

namespace areas{

    double findArea(const triangles::Triangle& triangle){
        double area;
        double side1= triangles::findSides(triangle.pt1,triangle.pt2);
        double side2= triangles::findSides(triangle.pt1,triangle.pt3);
        double side3= triangles::findSides(triangle.pt2,triangle.pt3);
        double halfPerimeter =side1+side2+side3;
        halfPerimeter/=2;

        area= sqrt(halfPerimeter*(halfPerimeter-side1)*(halfPerimeter-side2)*(halfPerimeter-side3));
        return area;
    }
    void fillArray(triangles::Triangle*arr,double *arrAreas,int n){
        for(int i=0;i<n;i++){
            arrAreas[i]= findArea(arr[i]);
        }
    }
}

void sortArrays(triangles::Triangle*arr, double *arrAreas,int n){

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arrAreas[i]>arrAreas[j]){
                std::swap(arrAreas[i],arrAreas[j]);
                std::swap(arr[i],arr[j]);
            }
        }
    }

}

int main(){

    int n;
    std::cin>>n;
    triangles::Triangle* arr = new triangles::Triangle[n];
    double *areasArr = new double [n];

    readArray(arr,n);
    areas::fillArray(arr,areasArr ,n);
    sortArrays(arr,areasArr,n);
    printArray(arr,areasArr,n);

    delete[] arr;
    delete[] areasArr;
    return 0;
}