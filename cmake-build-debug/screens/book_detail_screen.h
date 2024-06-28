//
// Created by asus on 2023-05-14.
//

#ifndef BOOK_SHOP_BOOK_DETAIL_SCREEN_H
#define BOOK_SHOP_BOOK_DETAIL_SCREEN_H

#include <iostream>
#include <unistd.h>
#include "base_screen.h"
#include "home_screen.h"
#include "register_screen.h"

class BookDetailScreen : public BaseScreen {
private:
    BookModel *bookModel;

    const double lineDelay = 0.1;
public:
    BookDetailScreen(BookModel *bookModel) {
        this->bookModel = bookModel;
    }

    void display() override {
        print(sl.strings->title(), false);
        print(bookModel->getTitle());
        delay(lineDelay);

        print(sl.strings->subtitle(), false);
        print(bookModel->getSubtitle());
        delay(lineDelay);

        print(sl.strings->author(), false);
        print(bookModel->getAuthor());
        delay(lineDelay);

        print(sl.strings->publisher(), false);
        print(bookModel->getPublisher());
        delay(lineDelay);

        print(sl.strings->language(), false);
        print(bookModel->getLanguage());
        delay(lineDelay);

        print(sl.strings->pages(), false);
        print(bookModel->getPages());
        delay(lineDelay);

        print(sl.strings->year(), false);
        print(bookModel->getYear());
        delay(lineDelay);

        print(sl.strings->rating(), false);
        print(bookModel->getRating());
        delay(lineDelay);

        print(sl.strings->description(), false);
        print(bookModel->getDesc());
        delay(lineDelay);

        print(sl.strings->price(), false);
        print(bookModel->getPrice());
        delay(lineDelay);

        print(sl.strings->url(), false);
        print(bookModel->getUrl());
        delay(lineDelay);

        print("\n" + sl.strings->cartMenu(), false);
        int x = rangeSelector(0, 1, sl.strings->getOutOfRangeInput());

        if (x == 0) {
            sl.navigator->popScreen();
        } else {
            sl.repository->addCartBook(*bookModel);
            print(sl.strings->addedToCartSuccessfully());
            delay(1);
            sl.navigator->popScreen();
        }
    }

};

#endif //BOOK_SHOP_BOOK_DETAIL_SCREEN_H
