//
// Created by asus on 2023-05-11.
//

#ifndef BOOK_SHOP_CONSTANTS_H
#define BOOK_SHOP_CONSTANTS_H

#include <iostream>

using namespace std;

/*
 * This File is used to centralize the constants data.
 */

class Constants {
public:
    const string websiteUrl = "https://api.itbook.store/";
    const string cashBasePath = "files/cashed";
    const int numberOfBooks = 19;
    const string booksPath = "files/assets/books.txt";
};

#endif //BOOK_SHOP_CONSTANTS_H
