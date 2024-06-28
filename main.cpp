
#include <iostream>

#include "cmake-build-debug/shared/sl.h"
#include "cmake-build-debug/screens/splash_screen.h"

using namespace std;

int main() {
    initApplication();

    //an object from a class
    SplashScreen splashScreen;
    sl.navigator->pushScreen(&splashScreen);

    return 0;
}
