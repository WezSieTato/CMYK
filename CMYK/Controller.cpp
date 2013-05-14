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
    algorytm = algorytmy;
    
    switch(algorytm){
        case WYB:
            robot = new WybierajacyRobot(&polka);
            break;
            
        case REK:
            robot = new RekurencyjnyRobot(&polka);
            break;
            
        case LOS:
            robot = new BogoRobot(&polka);
            break;
            
    }
    dzialaj();
}

void Controller::dzialaj(){
            robot->setView(&view);
            czas = clock();
            wynik = robot->posortuj();
            czas = clock() - czas;
            view.pokazPolke(robot->getPolka());
            view.pokazWynik(wielkoscPolki ,wynik, czas, algorytm); 
}

void Controller::zaprezentujWynik(){

                 view.pokazWynik(wielkoscPolki, wynik, czas, algorytm);

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
    delete robot;
}

