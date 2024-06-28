//
// Created by asus on 2023-05-12.
//

#ifndef BOOK_SHOP_REPOSITORY_H
#define BOOK_SHOP_REPOSITORY_H

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include "../models/book_model.h"
#include "local_data_source.h"

using namespace std;

//The repository file is a connection Ring between
//the local data source and app prefs on a side and the screens on other side

//The repository gets the data from local data source and app prefs then filter it
//or search on it then send it to screens

class Repository {
public:
    virtual vector<BookModel> getBooks() = 0;

    virtual vector<BookModel> searchBook(string searchKey) = 0;

    virtual vector<BookModel> getCartBooks() = 0;

    virtual void addCartBook(BookModel book) = 0;

    virtual void clearCartBook() = 0;

    virtual void setUserName(string userName) = 0;

    virtual string getUserName() = 0;

    virtual bool isSigned() = 0;

    virtual void setLanguage(bool isEn) = 0;

    virtual bool getLanguage() = 0;
};


class RepositoryImpl : public Repository {
private:
    const string userNameKey = "user_name";
    const string languageKey = "language";
    const string cartKey = "cart_books";

    LocalDataSource *localDataSource;
    AppPrefs *appPrefs;
    Strings *strings;

    string toLower(string value) {
        transform(value.begin(), value.end(), value.begin(),
                  ::tolower);
        return value;
    }

public:
    RepositoryImpl(LocalDataSource *localDataSource, AppPrefs *appPrefs, Strings *strings) {
        this->localDataSource = localDataSource;
        this->appPrefs = appPrefs;
        this->strings = strings;
    }

    vector<BookModel> getBooks() override {
        return localDataSource->getBooks();
    }

    void setUserName(string userName) override {
        appPrefs->setString(userNameKey, userName);
    }

    string getUserName() override {
        return appPrefs->getString(userNameKey);
    }

    bool isSigned() override {
        return appPrefs->containKey(userNameKey);
    }

    void setLanguage(bool isEnglish) override {
        appPrefs->setBool(languageKey, isEnglish);
        strings->setLanguage(isEnglish);
    }

    bool getLanguage() override {
        if (appPrefs->containKey(languageKey)) {
            return appPrefs->getBool(languageKey);
        } else {
            //default value is english
            return true;
        }
    }

    vector<BookModel> searchBook(string searchKey) override {
        vector<BookModel> result;

        searchKey = toLower(searchKey);

        vector<BookModel> books = localDataSource->getBooks();

        for (BookModel book: books) {
            if (toLower(book.getTitle()).contains(searchKey)) {
                result.push_back(book);
            }
            else if (toLower(book.getSubtitle()).contains(searchKey)) {
                result.push_back(book);
            }
            else if (toLower(book.getDesc()).contains(searchKey)) {
                result.push_back(book);
            }
        }

        return result;
    }

    vector<BookModel> getCartBooks() override {
        //the titles of cart books
        vector<string> titles = appPrefs->getVectorString(cartKey);

        //All Books in Our Library
        vector<BookModel> allBooks = getBooks();

        //The Cart Book Model Vector
        vector<BookModel> cartBooks;

        for (string title: titles) {
            for (BookModel book: allBooks) {
                if (book.getTitle() == title) {
                    cartBooks.push_back(book);
                    break;
                }
            }
        }

        return cartBooks;
    }

    void addCartBook(BookModel book) override {
        vector<string> cart = appPrefs->getVectorString(cartKey);
        cart.push_back(book.getTitle());
        appPrefs->setVectorString(cartKey, cart);
    }

    void clearCartBook() override {
        appPrefs->setVectorString(cartKey, vector<string>());
    }
};


#endif //BOOK_SHOP_REPOSITORY_H
