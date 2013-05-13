/* 
 * File:   main.cpp
 * Author: marcin
 *
 * Created on 11 marzec 2013, 11:57
 */

#include <cstdlib>
//#include <bits/mathcalls.h>
#include "time.h"
#include "Controller.h"

using namespace std;


int main(int argc, char** argv) {
    srand(time(NULL));
    Polka polka;  
    std::string pierwszyArgument(argv[1]);
    if (pierwszyArgument == "1"){
        polka = Controller::wczytajPolke(argv[2]);
    } else if (pierwszyArgument == "2"){
        polka = Controller::losujPolke(atoi(argv[2]));
    }
    
    int algorytmy = 0;
    for(int i = 3; i < argc; ++i){
        std::string algorytm(argv[i]);
        if(algorytm == "wyb")
            algorytmy = algorytmy | WYB;
        else if (algorytm == "rek")
            algorytmy = algorytmy | REK;
        else if (algorytm == "los")
            algorytmy = algorytmy | LOS;
    }
    
    if (!algorytmy)
        algorytmy = 7;
    
    if (pierwszyArgument == "3"){
        int min = atoi(argv[2]);
        int max = atoi(argv[3]);
        int iloscProb = max - min;
        Controller *proby[100];
        for (int i = min; i < max; ++i){
            polka = Controller::losujPolke(i);
            proby[i - min] = new Controller(polka, algorytmy);
        }
        
        for(int i = 0; i < iloscProb; ++i){
            proby[i]->zaprezentujWynik();
            delete proby[i];
        }
    }else{ 
        Controller controller(polka, algorytmy);
        controller.zaprezentujWynik();
    }
    
    

    return 0;
}

