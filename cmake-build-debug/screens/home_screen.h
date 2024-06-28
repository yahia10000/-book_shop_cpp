//
// Created by asus on 2023-05-11.
//

#ifndef BOOK_SHOP_HOME_SCREEN_H
#define BOOK_SHOP_HOME_SCREEN_H

#include "book_view_screen.h"
#include "settings_screen.h"
#include "search_book_screen.h"
#include "cart_screen.h"

using namespace std;

class HomeScreen : public BaseScreen {
public:
    void display() override {
        printStringAnimated(sl.strings->homeMenu(), 1, 0.05);
        printStringAnimated(sl.strings->arrow(), 0, 0.05);
        int x = rangeSelector(0, 4, sl.strings->getOutOfRangeInput());

        if (x == 0) {
            exit(0);
        }
        if (x == 1) {
            CartScreen r;
            sl.navigator->pushScreen(&r);
        }
        if (x == 2) {
            SearchBookScreen r;
            sl.navigator->pushScreen(&r);
        }
        if (x == 3) {
            BookViewScreen r;
            sl.navigator->pushScreen(&r);
        }
        if (x == 4) {
            SettingsScreen r;
            sl.navigator->pushScreen(&r);
        }
    }
};

#endif //BOOK_SHOP_HOME_SCREEN_H
