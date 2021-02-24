#include <iostream>
#include <stdio.h>

enum CODES{
    SUCCESS,
    FAILED,
    PROGRESS,
    SOLVED,
    DEFAULT
};

void debug(bool enabled, CODES code=DEFAULT){
    if(!enabled){ return; }
    switch(code){
        case PROGRESS:
            std::cout << "I JUST PISSED MYSELF" << std::endl;
            break;
        case FAILED:
            std::cout << "Mission Failed!" << std::endl;
            break;
        case SUCCESS:
            std::cout << "Mission Success!" << std::endl;
            break;
        case SOLVED:
            std::cout << "Just another day for the SURVEY CORP!" << std::endl;
            break;
        default:
            std::cout << "Erwin's Failsafe Plan: ";  
    }
}