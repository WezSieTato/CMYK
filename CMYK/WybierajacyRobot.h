/* 
 * File:   WybierajacyRobot.h
 * Author: marcin
 *
 * Created on 3 kwiecień 2013, 21:17
 */

#ifndef WYBIERAJACYROBOT_H
#define	WYBIERAJACYROBOT_H

#include "Robot.h"

class WybierajacyRobot : public Robot {
public:
    WybierajacyRobot(Polka *npolka) : Robot(npolka) {};
    int posortuj();
    virtual ~WybierajacyRobot();
private:
    int iloscKoloru[4];
    int iloscUlozonych;
    Kolor szukanyKolor;
    /**
     * iterator na ostatnio ulozony pojemnik
     */
    Polka::iterator ostatnioUlozony;
    
    /**
     * funkcja aktualizujaca tablice z iloscia poszczegolnych kolorow
     */
    void przeliczKolory();
    
    /**
     * ustala jaki powinien byc aktualnie poszukiwany kolor i aktualizuje
     * zmienna szukanyKolor
     */
    void ustalSzukanyKolor();
    
    /**
     * ustala poczatek sortowania
     * @return true jesli poczatek sortowania sie zmienil
     */
    bool ustalPoczatekSortowania();
    
    /**
     * przenosi piaty od konca element o zadana ilosc razy
     * @param ileRazy
     */
    void przesunPiatke(int ileRazy);
    
    
    /**
     * znajduje nastepny element do posortowania i dosuwa
     * go do poczatku nieposortowanej czesci listy
     */
    void przesunJeden();
    
    /**
     * przesuwa zadana ilosc razy pojemnik z poczatku nieposortowanej
     * czesci listy
     * @param pozycja
     */
    void wybierz(int pozycja);
    
    /**
     * sortuje ostatnie 7 elementow za pomoca algorytmu
     * rekurencyjnej iteracji
     */
    void posortujRekurencyjnie();

};

#endif	/* WYBIERAJACYROBOT_H */

