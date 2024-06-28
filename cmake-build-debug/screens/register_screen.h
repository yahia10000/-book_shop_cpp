//
// Created by asus on 2023-05-13.
//

#ifndef BOOK_SHOP_REGISTER_SCREEN_H
#define BOOK_SHOP_REGISTER_SCREEN_H

#include <iostream>
#include "base_screen.h"
#include "home_screen.h"
#include "../shared/sl.h"

using namespace std;

class RegisterScreen : public BaseScreen {
public:
    void display() override {
        string userName = readValue<string>(sl.strings->enterUserName());
        sl.repository->setUserName(userName);
        printStringAnimated(sl.strings->registerSuccessfully(), 1, 0.2);

        delay(1);

        HomeScreen *home = new HomeScreen();
        sl.navigator->pushScreen(home);
    }
};

#endif //BOOK_SHOP_REGISTER_SCREEN_H
