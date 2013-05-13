/* 
 * File:   RekurencyjnyRobot.h
 * Author: marcin
 *
 * Created on 18 marzec 2013, 18:08
 */

#ifndef REKURENCYJNYROBOT_H
#define	REKURENCYJNYROBOT_H
#include "Robot.h"


class RekurencyjnyRobot : public Robot {
public:
    RekurencyjnyRobot(const Polka &npolka) : Robot(npolka){
        wirtualnaPolka = npolka;
        znalezionoRozwiazanie = false;
    };
    
    int posortuj();
    list<int> getNajlepszaKombinacja() const;
    virtual ~RekurencyjnyRobot();
private:
    list<int> listaRuchow, najlepszaKombinacja;
    Polka wirtualnaPolka;
    ListaPolek stanyPolek;
    bool znalezionoRozwiazanie;
    
    /**
     * funkcja rekurencyjna wyszukujaca najlepsze rozwiazanie
     * @param pozycja od ktorej ma zaczac wyszukiwac
     */
    void sprawdzGlebiej(int pozycja);
    
    bool przesunPojemnikiNaWirtualnej(Polka::iterator pozycjaRamy);
    bool przesunPojemnikiNaWirtualnej(int pozycjaRamy);
    void cofnijPrzesuwanieNaWirtualnej();
    bool sprawdzCzyWirtualnaPosortowana();
    
    /**
     * 
     * @param celA
     * @param celB
     * @return true jesli celA i celB jest taki sam strukturowo
     */
    bool czyTakieSame(const Polka &celA, const Polka &celB) const;
    /**
     * 
     * @param polkaDoSprawdzenia
     * @return true jesli wirtualnaPolka i polkaDoSprawdzenia
     *  sa takie same strukturowo
     */
    bool sprawdzCzyTakieSame(const Polka &polkaDoSprawdzenia) const;
    
    /**
     * sprawdza czy aktualny stan polki powtorzyl 
     * sie we wczesniejszych iteracjach
     * @return true jesli byl
     */
    bool sprawdzCzyJuzBylo() const;
    
    /**
     * sprawdza czy nie bylo rozwiazania na mniejszej glebokosci drzewa
     * @return  true jesli bylo
     */
    bool sprawdzCzyWarto() const;
    void drukujWirtualna() const;
    
};

#endif	/* REKURENCYJNYROBOT_H */

