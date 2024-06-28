//
// Created by asus on 2023-05-11.
//

#ifndef BOOK_SHOP_BOOK_MODEL_H
#define BOOK_SHOP_BOOK_MODEL_H

#include <iostream>

using namespace std;

/*
 * This file contain the class model that store the data of each book.
 * This file contain the class itself, Constructor, Getters and private variables.
*/
class BookModel {
private:
    string title, subtitle, author, publisher, language, desc, url;
    int pages, year, rating;
    double price;

public:
    BookModel(
            string title, string subtitle, string author, string publisher, string language, string desc, string url,
            int pages, int year, int rating,
            double price
    ) {
        this->title = title;
        this->subtitle = subtitle;
        this->author = author;
        this->publisher = publisher;
        this->language = language;
        this->pages = pages;
        this->year = year;
        this->rating = rating;
        this->desc = desc;
        this->price = price;
        this->url = url;
    }

    string getTitle() {
        return title;
    }

    string getSubtitle() {
        return subtitle;
    }

    string getAuthor() {
        return author;
    }

    string getPublisher() {
        return publisher;
    }

    string getLanguage() {
        return language;
    }

    string getDesc() {
        return desc;
    }


    string getUrl() {
        return url;
    }

    int getPages() {
        return pages;
    }

    int getYear() {
        return year;
    }

    int getRating() {
        return rating;
    }

    double getPrice() {
        return price;
    }
};

#endif //BOOK_SHOP_BOOK_MODEL_H
