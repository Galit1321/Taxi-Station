//
// Created by galit on 23/11/16.
//

#include "MatrixLayout.h"
/**
 * decounstructor
 */
MatrixLayout::~MatrixLayout() {
    for(int i = 0; i < height; ++i){
        for (int j=0; j<width; j++){
            delete  pNode[i][j];
        }
        delete [] pNode[i];
    delete[] matrix[i];
    }
    delete[] matrix;
    delete[] pNode;
}
MatrixLayout::MatrixLayout() {

}
/**
 * constructor
 * @param sizes string of the sizes, and
 * a vector of obstecals
 * @return
 */
MatrixLayout::MatrixLayout(int h,int w, vector<int>* obs){
    height=h;
    width=w;
    matrix = new int*[height];
    pNode=new Point**[height];
    for(int i = 0; i < height; ++i){
        matrix[i] = new int[width];
        pNode[i]=new Point*[width];
    }

    if(height)
        for (int i=0;i<height;i++){
            for (int j=0;j<width;j++){
                pNode[i][j]=new Point(i,j);
                matrix[i][j]=0;
            }
        }

    for (vector<int>::iterator iterator1=obs->begin();iterator1!=obs->end();iterator1++){
        int i=*iterator1;
        iterator1++;
        int j=*iterator1;
        matrix[i][j]=1;
    }
}
/**
 * constructor
 * @param sizes string of the sizes
 * @return
 */
MatrixLayout::MatrixLayout(int h,int w){
    height=h;
    width=w;
    matrix = new int*[height];
    pNode=new Point**[height];
    for(int i = 0; i < height; ++i){
       matrix[i] = new int[width];
        pNode[i]=new Point*[width];
    }

    if(height)
        for (int i=0;i<height;i++){
                for (int j=0;j<width;j++){
                    pNode[i][j]=new Point(i,j);
                    matrix[i][j]=0;
                }
        }
}
/**
 * return if we can move to direction d
 * 1 in the matrix will mark an obstacle
 * @param n the cheack node
 * @param d the direction we need to go
 * @return true if we can else false
 */
bool MatrixLayout::canGo(Point* n, char d) {
    //  AbsLayout::canGo(n,d)
    if((n->getJ()>0)&&(d=='l')&&(matrix[n->getI()][n->getJ()]!=1)){
        return true;
    }else if ((n->getI()<height-1)&&(d=='u')&&(matrix[n->getI()+1][n->getJ()]!=1)){
        return true;
    }
    else if ((n->getJ()<width-1)&&(d=='r')&&(matrix[n->getI()][n->getJ()+1]!=1)){
        return true;
    } else if((n->getI()>0)&&( d=='d')&&(matrix[n->getI()-1][n->getJ()]!=1)){
        return true;
    }
    return false;
}

/**
 * getter of node by index
 * @return node
 */
Point* MatrixLayout::getNode(int i,int j){
        if((i>height)||(j>width)||(i<0)||(j<0)){
            return NULL;
        } else{
            return pNode[i][j];

}
}

MatrixLayout* MatrixLayout::doplicate(){
    MatrixLayout* matrixLayout=new MatrixLayout();
    matrixLayout->height=this->height;
    matrixLayout->width=this->width;
    matrixLayout->matrix = new int*[matrixLayout->height];
    matrixLayout->pNode=new Point**[matrixLayout->height];
    for(int i = 0; i < matrixLayout->height; ++i){
        matrixLayout->matrix[i] = new int[ matrixLayout->width];
        matrixLayout->pNode[i]=new Point*[matrixLayout->width];
    }
    if(this-height)
        for (int i=0;i<height;i++){
            for (int j=0;j<width;j++){
                matrixLayout->pNode[i][j]=new Point(i,j);
                matrixLayout->matrix[i][j]=this->matrix[i][j];
            }
        }
    return  matrixLayout;
}

int MatrixLayout::getHeight() const {
    return height;
}

void MatrixLayout::setHeight(int height) {
    MatrixLayout::height = height;
}

int MatrixLayout::getWidth() const {
    return width;
}

void MatrixLayout::setWidth(int width) {
    MatrixLayout::width = width;
}

int **MatrixLayout::getMatrix() const {
    return matrix;
}

void MatrixLayout::setMatrix(int **matrix) {
    MatrixLayout::matrix = matrix;
}
