/* 
 * File:   Pojemnik.h
 * Author: marcin
 *
 * Created on 11 marzec 2013, 12:26
 */
#include <iostream>
#include <stdarg.h>
#include "stdlib.h"

#ifndef POJEMNIK_H
#define	POJEMNIK_H

typedef enum Kolor {
    Cyan = 0, 
    Magenta = 1,
    Yellow = 2,
    Black = 3
} Kolor;


class Pojemnik {
public:
    
    Pojemnik();
    Pojemnik(Kolor nkolor);
    Pojemnik(int n);
    
    Kolor getKolor() const;
    bool operator==(const int &porownanie) const;
    bool operator!=(const int &porownanie) const;
    bool operator!=(const Pojemnik &porownanie) const;
    bool operator==(const Pojemnik &porownanie) const;
    bool operator<(const int &porownanie) const;
    friend std::ostream& operator<<(std::ostream& out, const Pojemnik& wkt);
    virtual ~Pojemnik();
private:
    Kolor kolor;

};

#endif	/* POJEMNIK_H */

