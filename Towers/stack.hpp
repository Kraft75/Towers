//
//  stack.hpp
//  Towers
//
//  Created by MacJay on 04.03.24.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include <optional>

template <typename T>
class Stack {
public:
    
    virtual ~Stack() = default;
    
//    push fügt ein Element zum Container hinzu
    virtual void push(T item) = 0;
    
    /*
        pop gibt das oberste Element des Stapels zurück
        und entfernt gleichzeitig das Element aus dem Container
     */
    virtual std::optional<T> pop() = 0;
    
    /*
         peek gibt nur das oberste Element des Containers zurück,
         ohne das Element zu entfernen,
     */
    virtual std::optional<T> peek() = 0;
    
    /*
        isEmpty gibt true zurück, wenn der Container Elemente enthält.  
     */
    virtual const bool isEmpty() const = 0;



};
#endif /* stack_hpp */
