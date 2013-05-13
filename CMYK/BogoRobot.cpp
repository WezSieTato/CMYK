/* 
 * File:   BogoRobot.cpp
 * Author: marcin
 * 
 * Created on 11 marzec 2013, 20:48
 */

#include "BogoRobot.h"

int BogoRobot::posortuj(){
     if (czyPosortowane())
         return licznikRuchow;
     int maxLosuj = iloscPojemnikow - 4;
     while (true){
          przesunPojemniki(rand() % maxLosuj);       
          if (czyPosortowane()){
                return licznikRuchow;
             }
         }
}

//BogoRobot::~BogoRobot() {
//}