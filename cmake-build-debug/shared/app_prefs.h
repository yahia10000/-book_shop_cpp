//
// Created by asus on 2023-05-11.
//

#ifndef BOOK_SHOP_APP_PREFS_H
#define BOOK_SHOP_APP_PREFS_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


/*
 * This file is used to cash the primitive data type(bool, int, string)
 * Also can get and set a value using a key
 * This file is based on files generated on "files/cashed/" folder
 */

//app preferences class
class AppPrefs {
public:
    virtual void setBool(string key, bool val) = 0;

    virtual bool getBool(string key) = 0;

    virtual void setString(string key, string val) = 0;

    virtual string getString(string key) = 0;

    virtual void setVectorString(string key, vector<string> val) = 0;

    virtual vector<string> getVectorString(string key) = 0;

    virtual bool containKey(string key) = 0;
};

class AppPrefsImpl : public AppPrefs {
private:
    //the path of generated files
    string basePath;

    //this method used to write to file
    //and Templates is used to make the method accept different parameter types
    template<class T>
    void writeToFile(string key, T val) {
        ofstream out;
        out.open(basePath + "/" + key + ".txt");
        out << val;
        out.close();
    }

    //this method used to read a file
    //and Templates is used to make the method return different types from the method
    template<class T>
    T readFromFile(string key) {
        ifstream in;
        in.open(basePath + "/" + key + ".txt");
        T data;
        in >> data;
        in.close();
        return data;
    }

public:
    //constructor
    AppPrefsImpl(string basePath) {
        this->basePath = basePath;
    }

    //this method ensure that a key is found or not
    //the method try to open the file then check if it exists
    bool containKey(string key) override {
        ifstream in;
        in.open(basePath + "/" + key + ".txt");

        if (in.is_open()) {
            in.close();
            return true;
        } else {
            return false;
        }
    }

    void setString(string key, string val) override {
        writeToFile<string>(key, val);
    }

    string getString(string key) override {
        return readFromFile<string>(key);
    }

    void setBool(string key, bool val) override {
        writeToFile(key, val);
    }

    bool getBool(string key) override {
        return readFromFile<bool>(key);

    }

    void setVectorString(string key, vector<string> val) override {
        ofstream out;
        out.open(basePath + "/" + key + ".txt");
        out << val.size() << endl;
        for (string s: val) {
            out << s << endl;
        }
        out.close();
    }

    vector<string> getVectorString(string key) override {
        int vectorSize = -1;
        ifstream in;
        in.open(basePath + "/" + key + ".txt");

        in >> vectorSize;

        vector<string> data;

        for (int i = 0; i < vectorSize; i++) {
            string element;
            in >> element;
            data.push_back(element);
        }

        in.close();

        return data;
    }
};

#endif //BOOK_SHOP_APP_PREFS_H
