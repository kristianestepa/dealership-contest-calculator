# Auto Retail Sales Contest & Points Engine

> A C++ CLI engine designed to automate point calculations for dealership monthly sales contests.

---

## 📌 Overview

At automotive dealerships, receptionists and desk managers often process deal sheets manually. Calculating monthly contest points requires cross-referencing physical cheat sheets (accounting for vehicle type, lease multipliers, inventory age brackets, and split sales) and manually populating and re-sorting Excel spreadsheets after every single turn-in. 

This project automates that entire process into a centralized, error-free calculation engine, reducing processing time and eliminating human math errors.

---

## 🎯 Features

* **Automated Point Logic:** Automatically applies point calculations based on deal variables:
  * **Gross Performance:** Calculates linear point scaling based on total front-end gross ($5\text{ pts per } \$1\text{K}$ for New, $8\text{ pts per } \$1\text{K}$ for Used).
  * **Inventory Age Multipliers:** Automatically assigns bonus point tiers based on days in inventory.
  * **Deal Types & Splits:** Handles lease multipliers ($2\times$) and evenly divides accumulated points across secondary salespeople for split deals.
* **Real-Time Standings:** Ranks salespeople automatically from highest total points to lowest.
* **CLI Interface:** Light-weight, zero-dependency C++ console tool for high-speed terminal execution.

---

## 🧮 Contest Calculation Logic

The engine executes business rules using the following matrix:

| Factor | New Vehicles | Used Vehicles |
| :--- | :--- | :--- |
| **Gross Multiplier** | 5x points per $1,000 | 8x points per $1,000 |
| **Lease Multiplier** | $2\times\text{ total deal points}$ | N/A |
| **Split Sales** | Points divided by 2 per rep | Points divided by 2 per rep |

### Inventory Age Brackets

```text
New Vehicles:
  - Age < 25 days   : +5 pts
  - 25 - 49 days    : +10 pts
  - 50 - 74 days    : +15 pts
  - 75 - 99 days    : +20 pts
  - 100 - 124 days  : +25 pts
  - 125 - 149 days  : +35 pts
  - 150 - 174 days  : +45 pts
  - 175+ days       : +65 pts

Used Vehicles:
  - Age < 20 days   : +5 pts
  - 20 - 29 days    : +10 pts
  - 30 - 39 days    : +20 pts
  - 40 - 49 days    : +30 pts
  - 50 - 59 days    : +40 pts
  - 60 - 69 days    : +50 pts
  - 70+ days        : +60 pts
