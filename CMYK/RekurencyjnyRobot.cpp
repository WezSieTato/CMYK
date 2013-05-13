/* 
 * File:   RekurencyjnyRobot.cpp
 * Author: marcin
 * 
 * Created on 18 marzec 2013, 18:08
 */

#include "RekurencyjnyRobot.h"

int RekurencyjnyRobot::posortuj(){
   
    for(int i = 0; i < iloscPojemnikow - 5; ++i)
        sprawdzGlebiej(i);
    
    for (list<int>::const_iterator iter = najlepszaKombinacja.begin(); 
            iter != najlepszaKombinacja.end(); ++iter){
        przesunPojemniki(*iter);
    }
    
    return licznikRuchow;
}

void RekurencyjnyRobot::sprawdzGlebiej(int pozycja){
//    cout << "sprawdzam" ;
     stanyPolek.push_back(*wirtualnaPolka);
    przesunPojemnikiNaWirtualnej(pozycja);
    
    if(!sprawdzCzyWarto() || sprawdzCzyWirtualnaPosortowana()
            || sprawdzCzyJuzBylo()) {
        
    }
    else{
        int ilosc = iloscPojemnikow - 4;
        int max = ilosc - 1;
        int swap, r;
        int *tablica = new int[ilosc];
        
        for (int i = 0; i < ilosc; ++i){
            tablica[i] = i;
        }
        
        for (int i = 0; i < ilosc - 1; ++i){
            r = rand()%max;
            swap = tablica[max];
            tablica[max] = tablica[r];
            tablica[r] = r;
            --max;
        }
        
            r = rand()%ilosc;
            swap = tablica[0];
            tablica[0] = tablica[r];
            tablica[r] = r;
        
        for (int i = 0; i < ilosc; i++)
            sprawdzGlebiej(tablica[i]);
        
        delete tablica;
    }
      stanyPolek.pop_back();
    cofnijPrzesuwanieNaWirtualnej();
        
}

bool RekurencyjnyRobot::przesunPojemnikiNaWirtualnej(Polka::iterator pozycjaRamy){
    return przesunPojemniki(pozycjaRamy, wirtualnaPolka);
}

bool RekurencyjnyRobot::przesunPojemnikiNaWirtualnej(int pozycjaRamy){
    listaRuchow.push_back(pozycjaRamy);
    return przesunPojemniki(pozycjaRamy, wirtualnaPolka);
}

void RekurencyjnyRobot::cofnijPrzesuwanieNaWirtualnej(){
    int ostatniRuch =  listaRuchow.back();
     Polka::iterator poczatekRamy(wirtualnaPolka->end());
     --------poczatekRamy;
     
     Polka ramieRobota;
     ramieRobota.insert(ramieRobota.end(), poczatekRamy, wirtualnaPolka->end() );
     wirtualnaPolka->erase(poczatekRamy, wirtualnaPolka->end());
     
     Polka::iterator miejsceOstatniegoRuchu(wirtualnaPolka->begin());
     
     for(int i = 0; i < ostatniRuch; ++i)
         ++miejsceOstatniegoRuchu;
     
     wirtualnaPolka->insert(miejsceOstatniegoRuchu, ramieRobota.begin(),
                                                ramieRobota.end());
     listaRuchow.pop_back();
}

bool RekurencyjnyRobot::sprawdzCzyWirtualnaPosortowana(){
    if (!czyPosortowane(wirtualnaPolka))
        return false;
    
    if (!znalezionoRozwiazanie)    
        znalezionoRozwiazanie = true;
        
    najlepszaKombinacja = listaRuchow;
    return true;
}

bool RekurencyjnyRobot::sprawdzCzyTakieSame(const Polka &polkaDoSprawdzenia) const{

   Polka::const_iterator ipolka(polkaDoSprawdzenia.begin()),
           iwirtualna(wirtualnaPolka->begin());
   for(int i = 0; i < iloscPojemnikow; ++i){

       if(!(*ipolka == *iwirtualna))
           return false;
       ++ipolka;
       ++iwirtualna;
   }
   return true;
}

bool RekurencyjnyRobot::czyTakieSame(const Polka& celA, const Polka& celB) const{
    return true;
}

bool RekurencyjnyRobot::sprawdzCzyJuzBylo() const{
    ListaPolek::const_iterator iteratorPoPolkach(stanyPolek.begin());
    ListaPolek::const_iterator koniec(stanyPolek.end());
    for(int i = 0; iteratorPoPolkach != koniec; ++iteratorPoPolkach){
        if(sprawdzCzyTakieSame(*iteratorPoPolkach)){
            
            return true;
        }
        ++i;
    }
    return false;
}

bool RekurencyjnyRobot::sprawdzCzyWarto() const{
    if (znalezionoRozwiazanie && 
            najlepszaKombinacja.size() == listaRuchow.size())
        return false;
    return true;
}

void RekurencyjnyRobot::drukujWirtualna() const{
    podajStanPolki(wirtualnaPolka);
}

list<int> RekurencyjnyRobot::getNajlepszaKombinacja() const{
    return najlepszaKombinacja;
}

RekurencyjnyRobot::~RekurencyjnyRobot() {
}

