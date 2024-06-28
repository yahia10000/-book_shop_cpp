//
// Created by asus on 2023-05-13.
//

#ifndef BOOK_SHOP_SETTINGS_SCREEN_H
#define BOOK_SHOP_SETTINGS_SCREEN_H

#include <iostream>
#include <unistd.h>
#include "../shared/sl.h"

using namespace std;

class SettingsScreen : public BaseScreen {
public:
    void display() override {
        printStringAnimated(sl.strings->settingLabel(), 1, 0.05);

        printStringAnimated(sl.strings->settingMenu(), 1, 0.05);
        int selectSetting = rangeSelector(0, 2, sl.strings->getOutOfRangeInput());

        if (selectSetting == 0) {
            sl.navigator->popScreen();
        } else if (selectSetting == 1) {
            string newUserName = readValue<string>(sl.strings->enterUserName());
            sl.repository->setUserName(newUserName);
            printStringAnimated(sl.strings->userNameChangesSuccessfully(), 1, 0.05);
            delay(1);
            SettingsScreen settingsScreen;
            sl.navigator->pushReplacement(&settingsScreen);

        } else if (selectSetting == 2) {
            printStringAnimated(sl.strings->languageMenu(), 1, 0.05);
            int selectLanguage = rangeSelector(1, 2, sl.strings->getOutOfRangeInput());
            if (selectLanguage == 1)
                sl.repository->setLanguage(1);
            else
                sl.repository->setLanguage(0);

            printStringAnimated(sl.strings->languageChangedSuccessfully(), 1, 0.05);
            delay(1);
            SettingsScreen settingsScreen;
            sl.navigator->pushReplacement(&settingsScreen);
        }
    }

};

#endif //BOOK_SHOP_SETTINGS_SCREEN_H
