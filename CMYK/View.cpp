/* 
 * File:   View.cpp
 * Author: marcin
 * 
 * Created on 30 kwiecień 2013, 16:26
 */

#include "View.h"
#include "Controller.h"

#define FAST false



View::View() {
}

void View::pokazPrzesuniecie(int pozycjaPrzesuniecia, const Polka* polka){
    if(FAST)
        return;
    
        for (int i = 0; i < pozycjaPrzesuniecia; ++i){
        cout << " ";
    }
    cout << "|\n";
    for (int i = 0; i < pozycjaPrzesuniecia; ++i){
        cout << " ";
    }
    cout << "V";
    if (DEBUG_MODE){
        cout << "Wielkosc Polki: " << polka->size();
    }
    
    cout << endl;
    pokazPolke(polka);

}

void View::pokazWynik(int wielkosc, int wynik,clock_t czas , int algorytm){
    std::string alg;
    switch (algorytm){
        case WYB:
            alg = "wybierajacym";
            break;
            
        case REK:
            alg = "rekurencyjnym";
            break;
            
        case LOS:
            alg = "losujacym";
            break;
    }
//    czas /= 1000l;
    cout << "\n************************************************************ \n";
    cout << "Polke " << wielkosc << " elementowa posortowano algorytmem "
            << alg << endl << "W "  << wynik << " ruchach\n";
    cout << "W czasie :" << czas << " mili sekund\n";
    cout << "************************************************************ \n";
}

void View::pokazPolke(const Polka *polka){
    Polka::const_iterator koniec = polka->end();
    for (Polka::const_iterator iter = polka->begin(); iter != koniec;
            ++iter){
        
        cout << *iter;
    }
    cout << "\n";
}

View::~View() {
}

