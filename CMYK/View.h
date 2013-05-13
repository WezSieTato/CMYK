/* 
 * File:   View.h
 * Author: marcin
 *
 * Created on 30 kwiecień 2013, 16:26
 */

#ifndef VIEW_H
#define	VIEW_H

#include "Robot.h"
#define DEBUG_MODE false

class View {
public:
    View();
    
    void pokazPrzesuniecie(int pozycjaPrzesuniecia, const Polka &polka);
    void pokazWynik(int wielkosc, int wynik,clock_t czas, int algorytm);
    void pokazPolke(const Polka &polka);
    
    
    virtual ~View();
private:

};

#endif	/* VIEW_H */

