/* 
 * File:   Robot.cpp
 * Author: marcin
 * 
 * Created on 11 marzec 2013, 12:12
 */

#include "Robot.h"
#include "View.h"

Robot::Robot(const Polka &npolka) {
    polka = npolka;
    iloscPojemnikow = polka.size();
    licznikRuchow = 0;
    view = NULL;
}

void Robot::podajStanPolki() const{
    podajStanPolki(polka);
}

void Robot::podajStanPolki(const Polka &celSkanowania) const{
    cout << "Stan polki: ";
    Polka::const_iterator koniec = celSkanowania.end();
    for (Polka::const_iterator iter = celSkanowania.begin(); iter != koniec;
            ++iter){
        
        cout << *iter;
    }
    cout << "\n";
}

bool Robot::czyPosortowane() const{
    return czyPosortowane(polka);
}

bool Robot::czyPosortowane(const Polka &celSortowania) const{
    Kolor start = Cyan;
    Polka::const_iterator koniec = celSortowania.end();
    
    for(Polka::const_iterator iter = celSortowania.begin(); iter != koniec; ++iter){
        if (*iter < start)
            return false;
        start = iter->getKolor();
    }
    return true;
}

bool Robot::przesunPojemniki(Polka::iterator pozycjaRamy){
    ++licznikRuchow;
    return przesunPojemniki(pozycjaRamy, polka);
}

bool Robot::przesunPojemniki(list<Pojemnik>::iterator pozycjaRamy, Polka &cel){
    Polka::iterator koniecRamy(pozycjaRamy);
    Polka::iterator koniecPolki(cel.end());
    
    if(koniecRamy == koniecPolki)
            return false;
    
    for(int i = 0; i < 4; ++i){
        if(++koniecRamy == koniecPolki)
            return false;
    }
    
    Polka ramieRobota;
    ramieRobota.insert(ramieRobota.end(), pozycjaRamy, koniecRamy);
    cel.erase(pozycjaRamy, koniecRamy);
    cel.insert(cel.end(), ramieRobota.begin(), ramieRobota.end());
    
//    podajStanPolki();
    return true;
    
}

bool Robot::przesunPojemniki(int pozycjaRamy){
    if(view)
        view->pokazPrzesuniecie(pozycjaRamy, polka);
    ++licznikRuchow;
    return przesunPojemniki(pozycjaRamy, polka);
}

bool Robot::przesunPojemniki(int pozycjaRamy, Polka &cel){
    Polka::iterator iter = cel.begin();
    for(int i = 0; i < pozycjaRamy; ++i){
        ++iter;
    }
    return przesunPojemniki(iter, cel);
}

void Robot::setView(View* nview){
    view = nview;
    view->pokazPolke(polka);
}

Polka Robot::getPolka() const{
    return polka;
}

//Robot::~Robot() {
//  //  polka.clear();
//}

