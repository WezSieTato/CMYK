/* 
 * File:   BogoRobot1.h
 * Author: marcin
 *
 * Created on 11 marzec 2013, 21:03
 */

#ifndef BOGOROBOT1_H
#define	BOGOROBOT1_H

#include "Robot.h"

class BogoRobot1 : public Robot {
public:

    BogoRobot1(const list<Pojemnik> &npolka) : Robot(npolka){};
    int posortuj();
    void test();
    
    virtual ~BogoRobot1();
private:
    int licznikSortujacy[4];
    int iloscDoSortowania;
    bool start;
    void policzKolory();
    bool ustawPoczatekSortowania();
    list<Pojemnik>::iterator poczatekSortowania;


};

#endif	/* BOGOROBOT1_H */

