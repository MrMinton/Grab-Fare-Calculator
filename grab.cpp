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
    cout<< "Please enter a valid choice!"<<endl;
    return false;
}

double cashback(const string &member ,const double &total_fare ){
    string member_id []= {"NONE","SILVER","GOLD","PLATINUM"};
    double cashbackRate[]={0,0.02,0.05,0.08};
    int n =4;

    for(int i =0 ; i<n ; i++){
        if(member == member_id[i]){
            return total_fare * cashbackRate[i];
        }
    }
    throw runtime_error("Try again");
}

// applyPromo now also outputs discount value
double applyPromo(const string &promo, double fare, double &discount) {
    string p = promo;
    for (char &c : p) c = toupper(c);
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
    // invalid or NONE
    return fare;
}

int main(){
    string ride, member, promo;
    double base, perKm,total_fare;

    cout << "======================================" << endl;
    cout << "    Welcome to Grab Fare Calculator" << endl;
    cout << "======================================" << endl;
    cout << "Available rides: GRABCAR | GRABBIKE | GRABPREMIUM" << endl;
    cout << "=================================================" << endl;
    cout << "Available member: NONE | SILVER | GOLD | PLATINUM" << endl;
    cout << "--------------------------------------" << endl;

    while (true) {
        cout << "Enter ride type (GRABCAR / GRABBIKE / GRABPREMIUM): ";
        cin >> ride;
        for (int i = 0 ; i < ride.length(); i++){
            ride[i] = toupper(ride[i]);
        }
        if (cartype(ride, base, perKm)){
            break;
        }
    }

    cout << "Enter membership tier (NONE / SILVER / GOLD / PLATINUM): ";
    cin >> member;
    for (int i = 0; i < member.length(); i++) {
        member[i] = toupper(member[i]);
    }

    cout << "Enter promo code (press Enter to skip): ";
    cin.ignore(); // clear leftover newline
    getline(cin, promo);

    if (promo.empty()) {
        promo = "NONE";
    }

    for (int i = 0; i < promo.length(); i++) {
        promo[i] = toupper(promo[i]);
    }

    try{
        total_fare = base * perKm;

        double cashbackAmount = cashback(member , total_fare);

        double promoDiscount = 0.0;
        double fareAfterPromo = applyPromo(promo, total_fare, promoDiscount);

        double finalCost = fareAfterPromo - cashbackAmount;
        if (finalCost < 0) finalCost = 0; // prevent negative

        cout << "\n=========== Fare Details =============" << endl;
        cout << "Car type    : " << ride << endl;
        cout << "Base fare   : RM " << fixed << setprecision(2) << base << endl;
        cout << "Per km rate : RM " << fixed << setprecision(2) << perKm << endl;
        cout << "Membership  : " << member << endl;
        cout << "Promo code  : " << promo << endl;
        cout << "--------------------------------------" << endl;
        cout << "Total fare (before promo): RM " << total_fare << endl;
        cout << "Promo discount           : RM " << promoDiscount << endl;
        cout << "Fare after promo         : RM " << fareAfterPromo << endl;
        cout << "Cashback                 : RM " << cashbackAmount << endl;
        cout << "Final Cost               : RM " << finalCost << endl;
        cout << "======================================" << endl;

    }catch(const exception &e){
        cout << "Error: " << e.what() << endl;
        cout << "Please enter a valid membership tier next time." << endl;
    }

    return 0;
}
