//
// Created by asus on 2023-05-11.
//

#ifndef BOOK_SHOP_SL_H
#define BOOK_SHOP_SL_H

#include "strings.h"
#include "app_prefs.h"
#include "constants.h"
#include "local_data_source.h"
#include "navigator.h"
#include "repository.h"

/*
 * This File is responsible to centralize objects from project classes
 * So ensure to avail one single object from each class
 * And don't repeat creating other objects
 */

//service locator
class SL {
public:

    Strings *strings = new Strings;

    Constants constants;

    AppPrefs *appPrefs = new AppPrefsImpl(
            constants.cashBasePath
    );

    LocalDataSource *localDataSource = new LocalDataSourceImpl(
            constants.numberOfBooks,
            constants.booksPath
    );

    Repository *repository = new RepositoryImpl(
            localDataSource,
            appPrefs,
            strings
    );

    Navigator *navigator = new NavigatorImpl();
};

SL sl;

//this function is supposed to ba called before displaying any screen.
void initApplication() {
    sl.strings->setLanguage(sl.repository->getLanguage());
}


#endif //BOOK_SHOP_SL_H
