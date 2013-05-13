/* 
 * File:   Controller.h
 * Author: marcin
 *
 * Created on 30 kwiecień 2013, 20:43
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H
#include "Robot.h"
#include "View.h"

#define WYB 1
#define REK 2
#define LOS 4

class Controller {
public:
        
    static Polka losujPolke(int wielkosc);
    static Polka wczytajPolke(
    const char* polka);
    Controller(Polka polka, int algorytmy);
    
    
    void zaprezentujWynik();
    
    virtual ~Controller();
private:
     View view;
    int wielkoscPolki;
    int wyniki[3];
    clock_t czasy[3];
    bool alg[3];

};

#endif	/* CONTROLLER_H */

