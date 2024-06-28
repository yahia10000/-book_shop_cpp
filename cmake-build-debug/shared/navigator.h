//
// Created by asus on 2023-05-11.
//

#ifndef BOOK_SHOP_NAVIGATOR_H
#define BOOK_SHOP_NAVIGATOR_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include "../screens/base_screen.h"

/*
 * This file used to handle navigation (transition) between screens
 * and store it to be able to remove the last screen
 * and show the screen under it.
 */

class Navigator {
public:
    virtual void pushScreen(BaseScreen *screen) = 0;

    virtual void pushReplacement(BaseScreen *screen) = 0;

    virtual void popScreen() = 0;
};

class NavigatorImpl : public Navigator {
private:
    vector<BaseScreen *> screensStack;


    void getNavigationPath() {
        string res = "";
        for (BaseScreen *e: screensStack) {
            res += typeid(*e).name();
            res += " > ";
        }
        cout << res << "\n\n";
    }

public:
    void pushScreen(BaseScreen *screen) override {
        system("cls");
        screensStack.push_back(screen);
        getNavigationPath();
        screen->display();
    }

    void popScreen() override {
        system("cls");
        screensStack.pop_back();
        getNavigationPath();
        if (screensStack.empty() == false) {
            screensStack.back()->display();
        }
    }

    void pushReplacement(BaseScreen *screen) override {
        system("cls");
        screensStack.pop_back();
        screensStack.push_back(screen);
        getNavigationPath();
        screen->display();
    }
};

#endif //BOOK_SHOP_NAVIGATOR_H
