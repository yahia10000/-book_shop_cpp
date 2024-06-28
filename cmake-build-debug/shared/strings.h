//
// Created by asus on 2023-05-11.
//

#ifndef BOOK_SHOP_STRINGS_H
#define BOOK_SHOP_STRINGS_H

#include <iostream>

using namespace std;

/*
 * This File is used to handle the strings and translate the strings
 */

class Strings {
private:
    bool isEnglish = true;
public:
    void setLanguage(bool isEnglish) {
        this->isEnglish = isEnglish;
    }

    string welcomeDearClient() {
        if (isEnglish) {
            return "Welcome Dear Client";
        } else {
            return "Bienvenue Cher client";
        }
    }

    string teamNames() {
        if (isEnglish) {
            return "By:\tYoussef Samy\n"
                   "\tYousef Magdy\n"
                   "\tYahia Shaban Yahia\n"
                   "\tYahia Mohammed El-Saeed";
        } else {
            return "Par:\tYoussef Samy\n"
                   "\tYousef Magdy\n"
                   "\tYahia Shaban Yahia\n"
                   "\tYahia Mohammed El-Saeed";
        }
    }

    string getOutOfRangeInput() {
        if (isEnglish) {
            return "Wrong Input, Please Follow the Range *_*";
        } else {
            return "Mauvaise entrée, veuillez suivre la plage *_*";
        }
    }

    string enterUserName() {
        if (isEnglish) {
            return "Enter User Name: ";
        } else {
            return "Entrez le nom d’utilisateur: ";
        }
    }

    string userNameChangesSuccessfully() {
        if (isEnglish) {
            return "User name changed successfully ";
        } else {
            return "Nom d’utilisateur modifié avec succès";
        }
    }

    string registerSuccessfully() {
        if (isEnglish) {
            return "Signed successful ^_^";
        } else {
            return "Signé avec succès ^_^";
        }
    }

    string homeMenu() {
        if (isEnglish) {
            return "Select the number of screen\n"
                   "for view cart  (1) \n"
                   "for view search book  (2)\n"
                   "for books view (3)\n"
                   "for setting (4)\n"
                   "for exit (0)";
        } else {
            return "sélecteur du nombre d’écransn\n"
                   "Pour voir le panier (1) \n"
                   "Pour afficher le livre de recherche (2)\n"
                   "Pour la vue des livres (3)\n"
                   "pour le réglage (4)\n"
                   "pour à dos (0)";
        }
    }


    string noDataFound() {
        if (isEnglish) return "No Data Found *_*";
        return "Aucune donnée trouvée *_*";
    }

    string enterZeroToBack() {
        if (isEnglish) return "Enter 0 to back: ";
        return "Entrez 0 à la suite: ";
    }

    string arrow() {
        return "==> ";
    }

    string totalCost() {
        if (isEnglish) return "Total Cost: ";
        return "Coût total: ";
    }

    string dollarSign() {
        return " $";
    }

    string zeroToBackOneToPay() {
        if (isEnglish) return "0 to back, 1 to pay: ";
        return "0 à dos, 1 à payer: ";
    }

    string cartPaidSuccessfully() {
        if (isEnglish) return "Books Cart is Paid Successfully";
        return "Le panier de livres est payé avec succès";
    }

    string enterSearchKey() {
        if (isEnglish) return "Enter Search Key: ";
        return "Entrez la clé de recherche: ";
    }

    string selectTheBook() {
        if (isEnglish) return "Select the book or 0 to back: ";
        return "Sélectionnez le livre ou 0 à sauvegarder: ";
    }

    string settingLabel() {
        if (isEnglish) return "Settings List: ";
        return "Liste des paramètres :";
    }

    string settingMenu() {
        if (isEnglish) return "1 => Change username \n2 => Change Language \n0 => Back";
        return "1 => Changer le nom d’utilisateur \n"
               "2 => Changer de langue \n"
               "0 => Retour";
    }

    string languageMenu() {
        if (isEnglish) return "1 => English \n2 => French";
        return "1 => Anglais \n"
               "2 => Français";
    }

    string languageChangedSuccessfully() {
        if (isEnglish) return "Language changed Successfully";
        return "Changements de langue avec succès";
    }

    string addedToCartSuccessfully() {
        if (isEnglish) return "Added To Cart Successfully";
        return "Ajouté au panier avec succès";
    }

    string cartMenu() {
        if (isEnglish) return "Enter 0 to Back, Enter 1 to Add To Cart ";
        return "Entrez 0 à l’arrière, entrez 1 à ajouter au panier";
    }

    string title() {
        if (isEnglish) return "Title: ";
        return "Titre:";
    }

    string subtitle() {
        if (isEnglish) return "Subtitle: ";
        return "Sous-titre: ";
    }

    string author() {
        if (isEnglish) return "Author: ";
        return "Autrice: ";
    }

    string publisher() {
        if (isEnglish) return "Publisher: ";
        return "Éditrice: ";
    }

    string pages() {
        if (isEnglish) return "Pages: ";
        return "Pages: ";
    }

    string language() {
        if (isEnglish) return "Language: ";
        return "Langue: ";
    }

    string year() {
        if (isEnglish) return "Year: ";
        return "Année: ";
    }

    string rating() {
        if (isEnglish) return "Rating: ";
        return "Notation: ";
    }

    string description() {
        if (isEnglish) return "Description: ";
        return "Description: ";
    }

    string price() {
        if (isEnglish) return "Price: ";
        return "Prix: ";
    }

    string url() {
        if (isEnglish) return "URL: ";
        return "URL: ";
    }

    string loading() {
        if (isEnglish) return "Loading ...";
        return "Chargement ...";
    }
};

#endif //BOOK_SHOP_STRINGS_H
