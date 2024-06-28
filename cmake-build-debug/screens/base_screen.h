//
// Created by asus on 2023-05-11.
//

#ifndef BOOK_SHOP_BASE_SCREEN_H
#define BOOK_SHOP_BASE_SCREEN_H


#include <unistd.h>

/*
 * This file contain the abstract class which all screens must inherit from.
 * Also, the [BaseScreen] class avail the necessary methods to the child classes.
 */

class BaseScreen {
protected:
    template<class T>
    void print(T value, bool endLine = true) {
        cout << value;
        if (endLine) cout << endl;
    }

    template<class T>
    T readValue(string label) {
        cout << label;
        T value;
        cin >> value;
        return value;
    }

    void delay(double seconds) {
        usleep(seconds * 1000000);//seconds to micro
    }

    int rangeSelector(int minVal, int maxVal, string fallbackMsg) {
        int val;
        try {
            do {
                cin >> val;
                if (val < minVal || val > maxVal) {
                    cout << fallbackMsg << endl;
                }
            } while (val < minVal || val > maxVal);
        } catch (string e) {

        }
        return val;
    }

    void printStringAnimated(string value, bool endLine = true, double delay = 0.4) {
        for (char c: value) {
            cout << c;
            usleep(delay * 1000000); //convert seconds to microsecond
        }
        if (endLine) cout << endl;
    }

public:
    virtual void display() = 0;
};

#endif //BOOK_SHOP_BASE_SCREEN_H
