

#ifndef ADVPRO1_MATRIXLAYOUT_H
#define ADVPRO1_MATRIXLAYOUT_H
using  namespace std;
#include "ILayout.h"
#include "vector"
#include "map"
class MatrixLayout :public ILayout{
private:

    int** matrix;
public:
    int **getMatrix() const;

    void setMatrix(int **matrix);

private:
//2-d array of int
    int height;//height of the matrix
    int width;//width of matrix
    Point** *pNode;

public:
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version);
    virtual ~MatrixLayout();//deconstuctor
    MatrixLayout();//default constructor
    bool canGo(Point* n, char d);//the implamention of the inteface
    MatrixLayout(int h, int w);//constuctor of sizes
    Point* getNode(int i,int j);//getter of node
    MatrixLayout(int h,int w, vector<int>* obs);//constructor
    MatrixLayout* doplicate();

    int getHeight() const;

    void setHeight(int height);

    int getWidth() const;

    void setWidth(int width);
};


#endif //ADVPRO1_MATRIXLAYOUT_H