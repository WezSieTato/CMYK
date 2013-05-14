/* 
 * File:   Robot.h
 * Author: marcin
 *
 * Created on 11 marzec 2013, 12:12
 */

#ifndef ROBOT_H
#define	ROBOT_H

#include <list>
#include <iostream>
#include <cstddef>
#include "Pojemnik.h"

class View;

using namespace std;

typedef list<Pojemnik> Polka;
typedef list< Polka > ListaPolek;

class Robot {
public:
    Robot(Polka *npolka);
    
    void podajStanPolki() const;
    
    virtual int posortuj() = 0;
    
    void setView(View *nview);
    Polka* getPolka() const;
    
//    virtual ~Robot();
protected:
    Polka *polka;
    int licznikRuchow, iloscPojemnikow;
    bool czyPosortowane() const;
    bool czyPosortowane(Polka *celSortowania) const;
    
    void podajStanPolki(Polka *celSkanowania) const;
    
    bool przesunPojemniki(Polka::iterator pozycjaRamy);
    bool przesunPojemniki(Polka::iterator pozycjaRamy, Polka *cel);
    
    bool przesunPojemniki(int pozycjaRamy);
    bool przesunPojemniki(int pozycjaRamy, Polka *cel);

private:
    View *view;
    
    
    

};

#endif	/* ROBOT_H */

