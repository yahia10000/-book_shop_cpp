cmake_minimum_required(VERSION 3.23)
project(book_shop)

set(CMAKE_CXX_STANDARD 23)

add_executable(book_shop main.cpp cmake-build-debug/shared/local_data_source.h cmake-build-debug/shared/app_prefs.h cmake-build-debug/shared/sl.h cmake-build-debug/shared/constants.h cmake-build-debug/shared/strings.h cmake-build-debug/models/book_model.h cmake-build-debug/screens/base_screen.h cmake-build-debug/screens/splash_screen.h cmake-build-debug/screens/home_screen.h cmake-build-debug/shared/navigator.h cmake-build-debug/shared/repository.h cmake-build-debug/screens/book_view_screen.h cmake-build-debug/screens/register_screen.h cmake-build-debug/screens/settings_screen.h cmake-build-debug/screens/book_detail_screen.h cmake-build-debug/screens/search_book_screen.h cmake-build-debug/screens/cart_screen.h)
