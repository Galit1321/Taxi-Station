

#ifndef ADVPRO1_MATRIXLAYOUT_H
#define ADVPRO1_MATRIXLAYOUT_H
using  namespace std;
#include "ILayout.h"
#include "vector"
#include "map"
class MatrixLayout :public ILayout{
private:

    int** matrix;//2-d array of int
    int height;//height of the matrix
    int width;//width of matrix
public:
    Point* **getPNode() const;


private:
    Point** *pNode;

public:
    virtual ~MatrixLayout();//deconstuctor
    MatrixLayout();//default constructor
    int **getMatrix() const;//getter of matric
    int getHeight() const;//getter of height
    int getWidth() const;//getter of width
    bool canGo(Point* n, char d);//the implamention of the inteface
    MatrixLayout(int h, int w);//constuctor of sizes
    Point* getNode(int i,int j);
    MatrixLayout(int h,int w, vector<int>* obs);
};


#endif //ADVPRO1_MATRIXLAYOUT_H