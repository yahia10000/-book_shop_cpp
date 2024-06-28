//
// Created by asus on 2023-05-11.
//

#ifndef BOOK_SHOP_SPLASH_SCREEN_H
#define BOOK_SHOP_SPLASH_SCREEN_H

#include <iostream>
//#include "home_screen.h"
#include "register_screen.h"
//#include "home_screen.h"


using namespace std;

class SplashScreen : public BaseScreen {
public:
    void display() override {
        printStringAnimated(sl.strings->welcomeDearClient(), true, 0.2);
        printStringAnimated(sl.strings->teamNames(), 1, 0.05);

        print('\n');
        printStringAnimated(sl.strings->loading(), 1, 0.1);

        delay(3);

        if (sl.repository->isSigned()) {
            HomeScreen h;
            sl.navigator->pushScreen(&h);
        } else {
            RegisterScreen r;
            sl.navigator->pushScreen(&r);
        }
    }
};


#endif //BOOK_SHOP_SPLASH_SCREEN_H
