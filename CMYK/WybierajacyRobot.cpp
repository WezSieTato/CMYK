/* 
 * File:   WybierajacyRobot.cpp
 * Author: marcin
 * 
 * Created on 3 kwiecień 2013, 21:17
 */

#include "WybierajacyRobot.h"
#include "RekurencyjnyRobot.h"
#include "View.h"

int WybierajacyRobot::posortuj(){
    szukanyKolor = Cyan;
    przeliczKolory();
    ustalSzukanyKolor();
    iloscUlozonych = 0;
    while(ustalPoczatekSortowania());
    
    while(iloscPojemnikow - iloscUlozonych > 4){
        przesunJeden();
        while(ustalPoczatekSortowania());
    }
 
    if(iloscPojemnikow - iloscUlozonych){
        posortujRekurencyjnie();
    }
    
    return licznikRuchow;
}

void WybierajacyRobot::posortujRekurencyjnie(){
    
    if( DEBUG_MODE)
        cout << "Posortuj rekurencyjnie!" << endl;
    
    Polka malaPolka;
    Polka::iterator poczN(polka->end());
    Polka::iterator konN(polka->end());
    --------------poczN;
    malaPolka.insert(malaPolka.begin(),poczN,konN);
    
    RekurencyjnyRobot robotPomocniczy(&malaPolka);
    robotPomocniczy.posortuj();
        
    if(DEBUG_MODE)
        cout << "Ukladanie wg listy!" << endl;
        
    list<int> ruchy(robotPomocniczy.getNajlepszaKombinacja());
    int przesuniecie = iloscPojemnikow - 7;
    for (list<int>::const_iterator iter = ruchy.begin(); 
            iter != ruchy.end(); ++iter){
        przesunPojemniki(*iter + przesuniecie);
    }
}


void WybierajacyRobot::przeliczKolory(){
    for (int i = 0; i < iloscPojemnikow; ++i)
        iloscKoloru[i] = 0;
    Polka::const_iterator koniec = polka->end();
    for (Polka::iterator iter = polka->begin(); iter != koniec;++iter){
        ++iloscKoloru[(int)(iter->getKolor())];
    }
}

void WybierajacyRobot::ustalSzukanyKolor(){
    while(!(iloscKoloru[szukanyKolor])){
        if (szukanyKolor == Black)
            return;
        szukanyKolor = (Kolor)((int)szukanyKolor + 1);
    }
}

bool WybierajacyRobot::ustalPoczatekSortowania(){
    Polka::iterator tmp;

    if (!iloscUlozonych){
        tmp = polka->begin();
    }
    else{
        tmp = ostatnioUlozony;
        ++tmp;
    }
    
    if (tmp == polka->end())
        return false;
   
    if (*tmp == szukanyKolor){
        ostatnioUlozony = tmp;
        ++iloscUlozonych;
        --iloscKoloru[szukanyKolor];
        ustalSzukanyKolor();
        return true;
    }
    
    return false;
}

void WybierajacyRobot::przesunJeden(){
    Polka::iterator iter;
    int pozycjaIterator = 0;
    
    if(DEBUG_MODE)
        cout << "Poczatek sortowania: " << iloscUlozonych << endl;
    
    if (!iloscUlozonych)
        iter = polka->begin();
    else{
        iter = ostatnioUlozony;
        ++iter;
    }
    
    while(*iter != szukanyKolor){
        ++iter;
        ++pozycjaIterator;
        
    }
    if (pozycjaIterator%4 == 0){
        wybierz(pozycjaIterator);     
    }
    else{
        int pozycjaRobocza;
        int iloscDoSortowania = iloscPojemnikow - iloscUlozonych;
        int reszta = iloscDoSortowania % 4;
        int delta = (reszta ? (4 - reszta) : 0);
        int przesuniecieKoncone = iloscDoSortowania - (reszta ? reszta : 4);
        pozycjaRobocza = pozycjaIterator - delta;

        if(pozycjaRobocza >= 0/* && pozycjaRobocza < iloscDoSortowania - 4 */ ){
            if(pozycjaRobocza  < iloscDoSortowania - 4){
                
                if(DEBUG_MODE)
                    cout << "Przypadek numer 1" << endl;
                
                przesunPojemniki(iloscUlozonych + pozycjaRobocza);
                wybierz(przesuniecieKoncone); 
                return;
                
            }else{
                //przypadek 2
                
                if(DEBUG_MODE)
                    cout << "Przypadek numer 2" << endl;
                
                przesunPojemniki(iloscUlozonych + pozycjaIterator - 4);
                przesunPojemniki(iloscUlozonych - 4 + pozycjaRobocza);
                
                
                
                wybierz(przesuniecieKoncone); 
                return;
            }
            
        } else{
            //przypadek 3
            
            if(DEBUG_MODE)
                cout << "Przypadek numer 3" << endl;
            
            if(DEBUG_MODE){
                cout << "Pozycja robocza " << pozycjaRobocza << endl;
                cout << "Pozycja Iterator " << pozycjaIterator << endl;
                cout << "reszta" << reszta << endl;

            }            
            
            // pozycja szukanego wzgledem ostatnich 4
            int pozycjaCzworkowa;
            if (pozycjaIterator < iloscDoSortowania - 4){
//                if(DEBUG_MODE)
//                        cout << "Przypadek A" << endl;
                przesunPojemniki(iloscUlozonych + pozycjaIterator);
                pozycjaCzworkowa = 0;
            }
            else{
                if(DEBUG_MODE)
                        cout << "Przypadek B" << endl;
                
                pozycjaCzworkowa = 4 - (iloscDoSortowania - pozycjaIterator);
                
            }
            
            if(DEBUG_MODE){
                cout << "Pozycja czworkowa " << pozycjaCzworkowa << endl;
            }
            
            przesunPiatke(4  - reszta - pozycjaCzworkowa);
            wybierz(przesuniecieKoncone);
            return;
        }
    }
}

void WybierajacyRobot::wybierz(int pozycja){
    int iloscWybran;
    iloscWybran = pozycja / 4;

    for (int i = 0; i < iloscWybran; ++i){
            przesunPojemniki(iloscUlozonych);
        }
}

void WybierajacyRobot::przesunPiatke(int ileRazy){
    for(int i = 1; i <= ileRazy; ++i){
        przesunPojemniki(iloscPojemnikow - 5);
    }
}

WybierajacyRobot::~WybierajacyRobot() {
}

