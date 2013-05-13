/* 
 * File:   BogoRobot.h
 * Author: marcin
 *
 * Created on 11 marzec 2013, 20:48
 */

#ifndef BOGOROBOT_H
#define	BOGOROBOT_H

#include "Robot.h"

class BogoRobot : public Robot {
public:

    BogoRobot(Polka *npolka) : Robot(npolka){};
    int posortuj();
    
//    virtual ~BogoRobot();
private:


};

#endif	/* BOGOROBOT_H */

