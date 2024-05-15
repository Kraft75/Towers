//
//  arrayStack.hpp
//  Towers
//
//  Created by MacJay on 04.03.24.
//

#ifndef arrayStack_hpp
#define arrayStack_hpp

#include <stdio.h>
#include "stack.hpp"
#include <deque>
#include <iostream>

template <typename T>
class ArrayStack : public Stack<T> {
    std::deque<T> container;
    
public:
    void push(T item) override {
        container.emplace_front(item);
    }
//----------------------------------------------------------------

    std::optional<T> pop() override {
        if (!container.empty()) {
    //        Letztes Element zwischengespeichert
            T item = container.front();
    //        Letztes Element löschen
            container.pop_front();
            
            return item;
        }
        return std::nullopt;
    }
//----------------------------------------------------------------
    std::optional<T> peek() override {
        if (!container.empty()) {
    //        Letztes Element wird ausgegeben
            return container.front();
        }
        return std::nullopt;
    }
//----------------------------------------------------------------

    const bool isEmpty() const override {
        return container.empty();
    }
//----------------------------------------------------------------

//    Default
    explicit ArrayStack() = default;
    ~ArrayStack() = default;
//----------------------------------------------------------------

//    Non-copyable
    ArrayStack(const ArrayStack&) = delete;
    ArrayStack& operator=(const ArrayStack&) = delete;
//----------------------------------------------------------------

//    Movable
    ArrayStack(ArrayStack&& other) : container(std::move(other.container)) {}
    ArrayStack& operator=(ArrayStack&& other) {
        container = std::move(other.container);
        return  *this;
    }
    
//----------------------------------------------------------------

//    Größe des Containers
    size_t containerSize() const {
        return container.size();
    }
//----------------------------------------------------------------

//    Überladung des <<-Operators
    std::ostream& print(std::ostream& os) const noexcept {
        for (int i = 0; i < container.size(); ++i) {
            os << container[i] << " ";
        }
        
        os << std::endl;
        
        return os;
    }
//----------------------------------------------------------------

//    print_Funktion
   /* friend std::ostream& operator<<(std::ostream& os, ArrayStack& as) {
        return as.print(os);
    }*/
//----------------------------------------------------------------
/*
    //    Überladung des ==-Operators
    friend bool operator==(const ArrayStack<T>& lhs, const ArrayStack<T>& rhs) {
//         Vergleichen der Größe der Stapel
            if (lhs.getSize() != rhs.getSize())
                return lhs.getSize() < rhs.getSize();
        
        // Vergleichen der Inhalte der Stapel
           auto lhsCopy = lhs;
           auto rhsCopy = rhs;
           while (!lhsCopy.isEmpty() && !rhsCopy.isEmpty()) {
               T lhsItem = lhsCopy.pop().value();
               T rhsItem = rhsCopy.pop().value();
               
               if (lhsItem != rhsItem)
                   return false;
           }
        // Falls Stapel gleiche Elemente enthalten

        return true;
    }
 */
};

 template<typename T>
  inline std::ostream& operator<<(std::ostream& os, const ArrayStack<T>& as) {
      return as.print(os);
  }
#endif /* arrayStack_hpp */
