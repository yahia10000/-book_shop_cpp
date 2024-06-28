//
// Created by asus on 2023-05-15.
//

#ifndef BOOK_SHOP_CART_SCREEN_H
#define BOOK_SHOP_CART_SCREEN_H

#include "base_screen.h"
#include "../shared/sl.h"

class CartScreen : public BaseScreen {
public:
    void display() override {
        auto cart = sl.repository->getCartBooks();
        if (cart.empty()) {
            printStringAnimated(sl.strings->noDataFound(), 1, 0.05);
            printStringAnimated(sl.strings->enterZeroToBack(), 0, 0.05);

            rangeSelector(0, 0, sl.strings->getOutOfRangeInput());
            sl.navigator->popScreen();

        } else {
            double cost = 0;
            for (int i = 0; i < cart.size(); i++) {
                cost += cart[i].getPrice();
                printStringAnimated(sl.strings->arrow(), 0, 0.05);
                printStringAnimated(cart[i].getTitle(), 1, 0.05);

            }
            printStringAnimated("\n" + sl.strings->totalCost(), 0, 0.05);
            print(cost, 0);
            printStringAnimated(sl.strings->dollarSign(), 1, 0.05);

            printStringAnimated(sl.strings->zeroToBackOneToPay(), 1, 0.05);

            int select = rangeSelector(0, 1, sl.strings->getOutOfRangeInput());
            if (select == 0) {
                sl.navigator->popScreen();
            } else {
                sl.repository->clearCartBook();
                printStringAnimated(sl.strings->cartPaidSuccessfully(), 1, 0.05);
                delay(1);
                sl.navigator->popScreen();
            }

        }

    }

};

#endif //BOOK_SHOP_CART_SCREEN_H
