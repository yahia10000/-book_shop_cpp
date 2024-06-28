//
// Created by asus on 2023-05-13.
//

#ifndef BOOK_SHOP_BOOK_VIEW_SCREEN_H
#define BOOK_SHOP_BOOK_VIEW_SCREEN_H

#include <iostream>
#include <unistd.h>
#include "base_screen.h"
#include "book_detail_screen.h"


using namespace std;

class BookViewScreen : public BaseScreen {
public:
    void display() override {
        auto books = sl.repository->getBooks();
        for (int i = 0; i < books.size(); i++) {
            print(i + 1, false);
            print(sl.strings->arrow(), false);
            print(books[i].getTitle());
            delay(0.125);
        }
        print("\n" + sl.strings->selectTheBook(), false);

        int number = rangeSelector(0, books.size(), sl.strings->getOutOfRangeInput());

        if (number == 0) {
            sl.navigator->popScreen();
        } else {
            BookModel selectedBook = books[number - 1];

            BookDetailScreen r(&selectedBook);
            sl.navigator->pushScreen(&r);
        }
    }
};


#endif //BOOK_SHOP_BOOK_VIEW_SCREEN_H
