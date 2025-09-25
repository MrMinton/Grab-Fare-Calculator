# 🚖 Grab Fare Calculator

A simple **C++ console program** that simulates a Grab ride fare calculator.  
The program calculates the total fare based on ride type, travel distance, a fixed service fee, available promo codes, and membership cashback tiers.

---

## ✨ Features

- Choose from **3 ride types**:
  - GrabCar
  - GrabBike
  - GrabPremium
- Enter travel **distance in km**
- Automatic addition of a fixed **service fee (RM0.50)**
- Apply **promo codes** for discounts:
  - `GRAB10` → 10% off (max RM5)
  - `STUDENT3` → RM3 off (min fare RM8)
  - `FREERIDE` → Free ride up to RM8
- Select **membership tier** for cashback:
  - `NONE` → 0%
  - `SILVER` → 2%
  - `GOLD` → 5%
  - `PLATINUM` → 8%
- Displays a **fare breakdown**: gross fare, discount, payable amount, cashback earned, and effective net cost
