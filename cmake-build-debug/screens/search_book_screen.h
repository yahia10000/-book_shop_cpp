//
// Created by asus on 2023-05-14.
//

#ifndef BOOK_SHOP_SEARCH_BOOK_SCREEN_H
#define BOOK_SHOP_SEARCH_BOOK_SCREEN_H

//#include <iostream>
//#include <vector>
//#include "base_screen.h"
//#include "../models/book_model.h"
//#include "../shared/sl.h"

using namespace std;

class SearchBookScreen : public BaseScreen {
    string searchKey;
public:
    void display() override {
        searchKey = readValue<string>(sl.strings->enterSearchKey());
        vector<BookModel> books = sl.repository->searchBook(searchKey);

        if (books.size() == 0) {
            printStringAnimated(sl.strings->noDataFound(), 1, 0.05);

            printStringAnimated("\n" + sl.strings->enterZeroToBack(), false, 0.05);
            rangeSelector(0, 0, sl.strings->getOutOfRangeInput());
            sl.navigator->popScreen();
        } else {
            for (int i = 0; i < books.size(); i++) {
                print(i + 1, false);
                printStringAnimated(sl.strings->arrow(), false, 0.05);
                printStringAnimated(books[i].getTitle(), 1, 0.05);
            }
            printStringAnimated("\n" + sl.strings->selectTheBook(), false, 0.05);

            int number = rangeSelector(0, books.size(), sl.strings->getOutOfRangeInput());

            if (number == 0) {
                sl.navigator->popScreen();
            } else {
                BookModel selectedBook = books[number - 1];

                BookDetailScreen r(&selectedBook);
                sl.navigator->pushScreen(&r);
            }
        }

    }
};


#endif //BOOK_SHOP_SEARCH_BOOK_SCREEN_H
