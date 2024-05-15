//
//  main.cpp
//  Towers
//
//  Created by MacJay on 04.03.24.
//

//#include <iostream>
//#include "arrayStack.hpp"
#include "TowerOfHanoi.hpp"
#include <string>

bool selectTower(size_t);
//------------------------------------------------------------------------
int main(int argc, const char * argv[]) {
    std::cout << "**Towers of Hanoi**\n\n";
    
    size_t size = 0;
    std::cout << "Bestimme die Größe des Stapels: ";
    std::cin >> size;
    std::cout << "Stapel 0 bis 2, " << size << " Scheiben\n";
    std::cout << "m StapelA StapelB: bewegt eine Scheibe von A nach B\n\n";
    TowerOfHanoi<size_t> hanoi(size);
    
    std::cout << std::endl;
    
    std::string input;
    size_t from = 0;
    size_t to = 0;
    int counter = 0;
//    Spielaufbau
    while (input != "q") {
        std::cout << hanoi;
        std::cout << "Eingabe? m -> bewegen, q -> Programm beenden: ";
        bool chooseMode = true;
        
        while (chooseMode) {
            std::cin >> input;
            if (input == "q" || input == "m") {
                chooseMode = false;
            } else {
                std::cout << "Eingabe von q oder m erforderlich.\n";
            }
            
        }
        
        std::cout << std::endl;
        
        if (input == "m") {
            bool move = true;
            while (move) {
//                Auswahl der Türme
                
                bool chooseFrom = true;
                while (chooseFrom) {
                    std::cout << "Wahl von Stapel A: ";
                    std::cin >> from;
                    chooseFrom = selectTower(from);
                    
                }
                bool chooseTo = true;
                while (chooseTo) {
                    std::cout << "Wahl von Stapel B: ";
                    std::cin >> to;
                    chooseTo = selectTower(to);
                }
                    
                
               
                std::cout << std::endl;
   //            Spielzug
               if (hanoi.move(from, to)) {
                   std::cout << "Spielzug erfolgreich\n";
                   std::cout << "Versuche: " << ++counter << std::endl;
                   move = false;
               } else {
                   std::cout << "Spielzug widerspricht den Spielregeln. Eingabe bitte wiederholen.\n";
                   continue;
               }
            } // while

        } // if
        
//        Abbruch bei Sieg
        if (hanoi.isWin()) {
            std::cout << "Win!\n";
            input = "q";
        }
        
    } // while
    
    
    
    return 0;
}
//------------------------------------------------------------------------
bool selectTower(size_t from) {
    if (from == 0 || from == 1 || from == 2) {
        return false;
        
    } else {
        std::cout << "Werte zwischen 0 und 2 erlaubt\n";
        return true;
    }
}
