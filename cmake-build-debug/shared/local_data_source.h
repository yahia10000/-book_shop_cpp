//
// Created by asus on 2023-05-11.
//

#ifndef BOOK_SHOP_LOCAL_DATA_SOURCE_H
#define BOOK_SHOP_LOCAL_DATA_SOURCE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "../models/book_model.h"
//#include "sl.h"

using namespace std;

/*
 * This File handle the data by getting it from text file then putting it
 * in model class then return it.
 *
 * The vector is like an array but has more feature like dynamic size
 * and ability to add or remove element from the vector.
 */

class LocalDataSource {
public:
    virtual vector<BookModel> getBooks() = 0;
};

class LocalDataSourceImpl : public LocalDataSource {
private:
    int numberOfBooks;
    string booksPath;
public:
    //constructor
    LocalDataSourceImpl(int numberOfBooks, string booksPath) {
        this->numberOfBooks = numberOfBooks;
        this->booksPath = booksPath;
    }

    vector<BookModel> getBooks() override {
        vector<BookModel> books;
        ifstream input;
        input.open(booksPath);

        for (int i = 0; i < numberOfBooks; i++) {
            string title, subtitle, author, publisher, language, desc, url;
            int pages, year, rating;
            double price;

            string rubbish;//used to skip the Hashes (#) in books text file

            input >> title;
            input >> subtitle;
            input >> author;
            input >> publisher;
            input >> language;
            input >> pages;
            input >> year;
            input >> rating;
            input >> desc;
            input >> price;
            input >> url;
            input >> rubbish;

            books.push_back(
                    BookModel(
                            title, subtitle, author, publisher, language, desc, url,
                            pages, year, rating,
                            price
                    )
            );
        }
        input.close();
        return books;
    }
};


#endif //BOOK_SHOP_LOCAL_DATA_SOURCE_H
