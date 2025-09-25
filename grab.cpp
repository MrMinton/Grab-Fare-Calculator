#include <iostream>
#include <cctype>
#include <iomanip>
#include <algorithm>
using namespace std;

bool cartype(const string& ride, double &base, double &perKm){
    string cartype[] = {"GRABCAR", "GRABBIKE", "GRABPREMIUM"};
    double baseFare[] = {3.0, 2.0, 5.0};
    double perKmFare[] = {1.5, 1.0, 2.0};

    int n = 3;
    for (int i = 0 ; i < n; i++){
        if (ride == cartype[i]){
            base = baseFare[i];
            perKm = perKmFare[i];
            return true;
        }
    }
    cout << "Please enter a valid choice!" << endl;
    return false;
}

bool getCashbackRate(const string &member, double &rate){
    string member_id []= {"NONE","SILVER","GOLD","PLATINUM"};
    double cashbackRate[]={0,0.02,0.05,0.08};
    int n = 4;

    for (int i = 0; i < n; i++){
        if (member == member_id[i]){
            rate = cashbackRate[i];
            return true;
        }
    }
    return false;
}

bool normalizePromo(string &promoUpper){
    for (int i = 0; i < promoUpper.length(); i++){
        promoUpper[i] = toupper(promoUpper[i]);
    }
    if (promoUpper.empty() || promoUpper == "NONE") return true;
    if (promoUpper == "GRAB10" || promoUpper == "STUDENT3" || promoUpper == "FREERIDE") return true;
    return false;
}

double applyPromo(const string &promo, double fare, double &discount){
    string p = promo;
    discount = 0.0;

    if (p == "GRAB10") {
        discount = min(fare * 0.10, 5.0); // 10% capped at RM5
        return fare - discount;
    }
    else if (p == "STUDENT3") {
        if (fare >= 8.0) {
            discount = 3.0;
            return fare - discount;
        }
    }
    else if (p == "FREERIDE") {
        if (fare <= 8.0) {
            discount = fare;
            return 0.0;
        } else {
            discount = 8.0;
            return fare - discount;
        }
    }
    return fare;
}

int main(){
    string ride, member, promo;
    double base, perKm, total_fare;

    cout << "======================================" << endl;
    cout << "    Welcome to Grab Fare Calculator" << endl;
    cout << "======================================" << endl;
    cout << "Available rides: GRABCAR | GRABBIKE | GRABPREMIUM" << endl;
    cout << "Available tiers : NONE | SILVER | GOLD | PLATINUM" << endl;
    cout << "Promo codes     : NONE | GRAB10 | STUDENT3 | FREERIDE" << endl;
    cout << "--------------------------------------" << endl;

    while (true){
        cout << "Enter ride type (GRABCAR / GRABBIKE / GRABPREMIUM): ";
        cin >> ride;
        for (int i = 0; i < ride.length(); i++){
            ride[i] = toupper(ride[i]);
        }
        if (cartype(ride, base, perKm)){
            break;
        }
    }

    double km;
    while (true){
        cout << "Enter distance (km): ";
        if (cin >> km && km >= 0.0){
            break;
        }
        cout << "Invalid number. Please enter a non-negative value." << endl;
        cin.clear();
        cin.ignore();
    }

    double cbRate;
    while (true){
        cout << "Enter membership tier (NONE / SILVER / GOLD / PLATINUM): ";
        cin >> member;
        for (int i = 0; i < member.length(); i++){
            member[i] = toupper(member[i]);
        }
        if (getCashbackRate(member, cbRate)){
            break;
        }
        cout << "Invalid membership tier. Try again." << endl;
    }

    cout << "Enter promo code (press Enter to skip): ";
    cin.ignore(); // clear leftover newline
    getline(cin, promo);
    for (int i = 0; i < promo.length(); i++){
        promo[i] = toupper(promo[i]);
    }
    bool promoValid = normalizePromo(promo);
    if (!promoValid){
        cout << "Note: Invalid promo code entered. It will be ignored." << endl;
        promo = "NONE";
    }

    total_fare = base + perKm * km;

    double promoDiscount = 0.0;
    double fareAfterPromo = applyPromo(promo, total_fare, promoDiscount);

    double cashbackAmount = fareAfterPromo * cbRate;
    double finalCost = fareAfterPromo - cashbackAmount;
    if (finalCost < 0) finalCost = 0.0;

    cout << "\n=========== Fare Details =============" << endl;
    cout << fixed << setprecision(2);
    cout << "Car type                : " << ride << endl;
    cout << "Distance                : " << km << " km" << endl;
    cout << "Base fare               : RM " << base << endl;
    cout << "Per km rate             : RM " << perKm << endl;
    cout << "--------------------------------------" << endl;
    cout << "Total fare (pre-promo)  : RM " << total_fare << endl;
    cout << "Promo code              : " << promo << (promoValid ? "" : " (invalid ignored)") << endl;
    cout << "Promo discount          : RM " << promoDiscount << endl;
    cout << "Fare after promo        : RM " << fareAfterPromo << endl;
    cout << "Membership              : " << member << " (" << cbRate * 100 << "% cashback)" << endl;
    cout << "Cashback amount         : RM " << cashbackAmount << endl;
    cout << "--------------------------------------" << endl;
    cout << "FINAL COST              : RM " << finalCost << endl;
    cout << "======================================" << endl;

    return 0;
}
