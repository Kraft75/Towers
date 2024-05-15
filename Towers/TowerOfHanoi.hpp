//
//  TowerOfHanoi.hpp
//  Towers
//
//  Created by MacJay on 04.03.24.
//

#ifndef TowerOfHanoi_hpp
#define TowerOfHanoi_hpp

#include <stdio.h>
#include "arrayStack.hpp"

template <typename T>
class TowerOfHanoi {
    ArrayStack<T> first;
    ArrayStack<T> second;
    ArrayStack<T> third;
    T maxSize;
    
public:
//    Konstruktor
    TowerOfHanoi(T m) : maxSize(m) {
//        Ersten Stapel mit Scheiben belegen
        for (T i = maxSize; i > 0; --i) {
            first.push(i);
        }
        
    }
//-----------------------------------------------------------------------
    
//    Non-copyable
    TowerOfHanoi(const TowerOfHanoi&) = delete;
    TowerOfHanoi& operator=(const TowerOfHanoi&) = delete;
//-----------------------------------------------------------------------

//    Movable
    TowerOfHanoi(TowerOfHanoi&& other) noexcept :
    first(std::move(other.first)),
    second(std::move(other.second)),
    third(std::move(other.third)),
    maxSize(std::move(other.maxSize)) {}
    
    TowerOfHanoi& operator=(TowerOfHanoi&& other) noexcept {
        first = std::move(other.first);
        second = std::move(other.second);
        third = std::move(other.third);
        maxSize = std::move(other.maxSize);
        
        return *this;
    }
//-----------------------------------------------------------------------

//    Überladung des <<-Operators
     std::ostream& print(std::ostream& os) const noexcept {
        os << "0: " << first << std::endl;
        os << "1: " << second << std::endl;
        os << "2: " << third << std::endl;
        
        return os;
    }
//-----------------------------------------------------------------------

//    print_Funktion
    friend std::ostream& operator<<(std::ostream& os, const TowerOfHanoi& t) {
        return t.print(os);
    }
//-----------------------------------------------------------------------

    /*
         Die Methode gibt true zurück, wenn rhs leer ist, false, wenn lhs leer ist,
         oder andernfalls den Vergleich zwischen dem Peek von lhs und rhs
         (entsprechend der Spielregel). Diese Methode kann auch als Überladung
         des Operators < in der Klasse ArrayStack implementiert werden.
    */
    [[nodiscard]] const bool compare(ArrayStack<T>& lhs, ArrayStack<T>& rhs) const noexcept {
        if (rhs.isEmpty()) {
            return true;
        }
        
        if (lhs.isEmpty()) {
            return false;
        }
        
        return lhs.peek().value() < rhs.peek().value();
    }
//-----------------------------------------------------------------------
    /*
        bewegt ein Element von einem Stapel auf einen anderen,
        wenn dies nach den Spielregeln erlaubt ist.
     */
    const bool move(size_t from, size_t to) noexcept {
        ArrayStack<T>& source = (from == 0) ? first : (from == 1) ? second : third;
        ArrayStack<T>& dest = (to == 0) ? first : (to == 1) ? second : third;

        if (compare(source, dest)) {
            std::optional<T> toMove = source.pop();
            if (toMove.has_value()) {
                dest.push(toMove.value());
                return true;
            }
        }
        
        return false;
         
    }
    
//-------------------------------------------------------------------------------------    -----
    /*
        liefert true, wenn alle Elemente vom linken in den
        rechten Stack erfolgreich übertragen wurden.

     */
    [[nodiscard]] const bool isWin() const noexcept {
        if (first.isEmpty() && second.isEmpty() && third.containerSize() == maxSize) {
            return true;
        }
        
        return false;
    }
    


};


#endif /* TowerOfHanoi_hpp */
