/* 
 * File:   Pojemnik.cpp
 * Author: marcin
 * 
 * Created on 11 marzec 2013, 12:26
 */

#include "Pojemnik.h"






Pojemnik::Pojemnik() {
    kolor = (Kolor)(rand()%4);
}

Pojemnik::Pojemnik(Kolor nkolor) {
    kolor = nkolor;
}

Pojemnik::Pojemnik(int n) {
    kolor = (Kolor)(n);
}

Kolor Pojemnik::getKolor() const{
    return kolor;
}

bool Pojemnik::operator==(const int &porownanie) const{
    return (this->kolor == porownanie);
}

bool Pojemnik::operator!=(const int &porownanie) const{
    return (this->kolor != porownanie);
}

bool Pojemnik::operator!=(const Pojemnik &porownanie) const{
    return (this->kolor != porownanie.kolor);
}

bool Pojemnik::operator==(const Pojemnik &porownanie) const{
    return (this->kolor == porownanie.kolor);
}

bool Pojemnik::operator<(const int &porownanie) const{
    return (this->kolor < porownanie);
}

std::ostream& operator<<(std::ostream& out, const Pojemnik& wkt)
{
    switch (wkt.kolor){
        case Cyan:
            out << "C";
            break;
            
        case Magenta:
            out << "M";
            break;
            
        case Yellow:
            out << "Y";
            break;
            
        case Black:
            out << "K";
            break;
            
        default:
            out << "nieznany_kolor";
            break;
    }
	return out;
}



Pojemnik::~Pojemnik() {
}

