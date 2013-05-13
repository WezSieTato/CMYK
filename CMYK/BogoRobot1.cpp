/* 
 * File:   BogoRobot1.cpp
 * Author: marcin
 * 
 * Created on 11 marzec 2013, 21:03
 */

#include "BogoRobot1.h"

int BogoRobot1::posortuj(){
    
          unsigned int ilosc = polka.size();
      ilosc -= 5;
     licznikRuchow = 0;
     if (Robot::czyPosortowane())
         return licznikRuchow;
     while (true){
                 przesunPojemniki(rand()%ilosc);
                 ++licznikRuchow;
                 if (Robot::czyPosortowane()){
                     cout << "Posortowano w : " << licznikRuchow <<  " ruchach \n";
                     return licznikRuchow;
                 }
         }
}
    
//      unsigned int ilosc = polka.size();
//     licznikRuchow = 0;
//     policzKolory();
//     iloscDoSortowania = polka.size();
//     poczatekSortowania = polka.begin();
//     start = true;
//     ustawPoczatekSortowania();
//     
//     if (czyPosortowane())
//         return licznikRuchow;
//     while (true){
//         list<Pojemnik>::iterator iter;
//         if (start)
//             iter = polka.begin();
//         else 
//             iter = poczatekSortowania;
//         for(; iter != polka.end(); ++iter){
//             if((rand()%iloscDoSortowania) == 0){
//                 przesunPojemniki(iter);
//                 ++licznikRuchow;
//                 ustawPoczatekSortowania();
//                 if (czyPosortowane()){
//                     cout << "Ilosc do sortowania: " << iloscDoSortowania << "\n";
//                     cout << "Posortowano w : " << licznikRuchow <<  " ruchach \n";
//                     return licznikRuchow;
//                 }
//             }
//         }
//     }


void BogoRobot1::policzKolory(){
    for(int i = 0; i < 4; ++i){
        licznikSortujacy[i] = 0;
    }
    
    for(list<Pojemnik>::iterator iter = polka.begin(); iter != polka.end(); ++iter){
        ++licznikSortujacy[iter->getKolor()];
    }
    
    cout << "Liczniki kolorow ";
    for(int i = 0; i < 4; ++i){
        cout << ": " << licznikSortujacy[i] ;
    }
    cout << "\n";
}
bool BogoRobot1::ustawPoczatekSortowania(){
    Kolor szukanyKolor;
    for(int i = 0; i < 4; ++i){
        if(!licznikSortujacy[i])
            szukanyKolor = (Kolor)i;
    }
    
    if (start){
        if( *(polka.begin()) == szukanyKolor){
            poczatekSortowania = polka.begin();
            ++poczatekSortowania;
            start = false;
                    
            --licznikSortujacy[szukanyKolor];
            --iloscDoSortowania;
            
            return true;
        }
        return false;
    }
   
    list<Pojemnik>::iterator tmp(poczatekSortowania);
    ++tmp;
    if (*tmp == szukanyKolor){
        poczatekSortowania = tmp;
        --licznikSortujacy[szukanyKolor];
        --iloscDoSortowania;
        
        return true;
    }
    
    return false;
}
void BogoRobot1::test(){

    cout << "Posortowano w : " << posortuj() <<  " ruchach \n";
}

BogoRobot1::~BogoRobot1() {
}