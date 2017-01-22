//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CONTROLLER_H
#define ADVPRO01_CONTROLLER_H

#include "Point.h"
#include "TaxiCenter.h"
#include "Socket.h"
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
using namespace std;

extern int driverL ;
class Controller {
    /**
     * class to controller the input in front
     * of the main function
     */
private:
    boost::mutex mutex;
public:
    TaxiCenter *getCenter() ;

public:
    vector<int> busy;
    std::map<int,int> client_map;
    std::map<int,int> ID_map;
    TaxiCenter* center;
    int servertime;
    Socket* connection;
    Controller(const short unsigned int  &port);



    virtual ~Controller();//desrectir
    Controller();//consterctor
    void getCommend();//busy wating method to get num of commend
protected:
    static void* createPthread(void* parameters);
    //commend 9 wait for the right time and make move
    //when the right time comes
    bool CommendNine();
    //commend two that create a new ride
    bool CommendTwo();
    // commend 3 to create a new car with agrument
    bool CommendThree();
    //commend 4 is to get the current position of driver with
    //id given in cin>>id and print it to screen
    bool CommendFour();
    //run all current driver that have a trip to finish point
    bool CommendSix();
    bool runDriver();

    static void* getNewTrip(void* parameters);
    static void* runClient(void* par);
    void closeAllClients();

};

    /*
 * struct to hold the controller and the socket number for the client.
 */

    struct parameters{
        Controller *c;
        int client_sock;
        string str;
        int client_id;
    };


#endif //ADVPRO01_CONTROLLER_H
