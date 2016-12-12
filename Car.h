//
// Created by michal on 12/1/16.
//

#ifndef EX2_CAR_H
#define EX2_CAR_H
enum  Color{RED = 0, BLUE =1, GREEN =2, PINK =3, WHITE =4};
 enum   Manufacturer{HONDA = 0, SUBARO =1, TESLA =2, FIAT =3};

class Car {
protected:
    int id ;
    int mileage;
    Color color;
    Manufacturer manufacturer;
public:
    //defult constructor
    Car();
    //set the id of the car
    void setId(int id);
    // return the mileage that have passed
    void setMileage(int mileage);
    void setColor(Color color);
    // set the manufacture of the car
    void setManufacturer(Manufacturer manufacturer);
    //return the id of the car
    int getId() const;
    // get the mileage of the car
    int getMileage() const;
    // get the color of the car
    Color getColor() const;
    // get the manufacture of the car
    Manufacturer getManufacturer() const;
    //make one move
   virtual  void  move()=0;
    //compare between two cars
    bool operator==(const Car &car) const;
};


#endif //EX2_CAR_H
