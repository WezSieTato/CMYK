/* 
 * File:   Controller.cpp
 * Author: marcin
 * 
 * Created on 30 kwiecień 2013, 20:43
 */

#include "Controller.h"
#include "WybierajacyRobot.h"
#include "RekurencyjnyRobot.h"
#include "BogoRobot.h"
#include <ctime>
#include <math.h>
#include <cmath>

Controller::Controller(Polka polka, int algorytmy) {
    wielkoscPolki = polka.size();
//    this->algorytmy = algorytmy;
    Robot *roboty[3];
    WybierajacyRobot r0(polka);
    RekurencyjnyRobot r1(polka);
    BogoRobot r2(polka);
    roboty[0] = &r0;
    roboty[1] = &r1;
    roboty[2] = &r2;
    

        for (int i = 0; i < 3 ; ++i){
        if ((algorytmy & (int)pow(2,i)) == (int)pow(2,i)){
            alg[i] = true;
        } else
            alg[i] = false;
    }
    
//    if(alg[0])
//        roboty[0] = new WybierajacyRobot(polka);
//    if(alg[1])
//        roboty[1] = new RekurencyjnyRobot(polka);
//    if(alg[2])
//        roboty[3] = new BogoRobot(polka);
               
    
    for (int i = 0; i < 3 ; ++i){
        if (alg[i]){
            roboty[i]->setView(&view);
            czasy[i] = clock();
            wyniki[i] = roboty[i]->posortuj();
            czasy[i] = clock() - czasy[i];
            view.pokazPolke(roboty[i]->getPolka());
            view.pokazWynik(wielkoscPolki ,wyniki[i], czasy[i], i); 
        }
    }
    
        
//    if(alg[0])
//        delete roboty[0];
//    if(alg[1])
//        delete roboty[1];
//    if(alg[2])
//        delete roboty[3];
   // zaprezentujWynik();
}

void Controller::zaprezentujWynik(){
       for (int i = 0; i < 3 ; ++i){
           if (alg[i]){
                 view.pokazWynik(wielkoscPolki, wyniki[i], czasy[i], i);
           }
       }
}

Polka Controller::losujPolke(int wielkosc){

    Polka polka;
    for (int i = 0; i < wielkosc; ++i){
        Pojemnik nowy;
        polka.push_back(nowy);
    }
    return polka;

}

Polka Controller::wczytajPolke(const char* polka){
    std::string spolka(polka);
    int size = spolka.size();
    Polka ret;
    cout << "wielkosc polki : " << size <<endl;
    for(int i = 0; i < size; ++i){
        if (spolka[i] == 'C'){
            ret.push_back(Cyan);
        } else if (spolka[i] == 'M'){
            ret.push_back(Magenta);
        } else if (spolka[i] == 'Y'){
            ret.push_back(Yellow);
        } else if (spolka[i] == 'K'){
            ret.push_back(Black);
        }
    }
    
    return ret;
}

Controller::~Controller() {
}

