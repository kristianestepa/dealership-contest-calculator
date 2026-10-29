Dealership Sales Contest Calculator

A command-line tool for calculating monthly sales contest points at a car dealership. Enter each deal, and the program works out the points for each salesperson and keeps a running leaderboard.

This is a C++ prototype for testing the point logic. A web version is planned.

Features
* Add deals for one or two salespeople (split deals)
* Separate point rules for new and used vehicles
* Lease deals (new vehicles only) earn double points
* Running leaderboard sorted by total points
* Input handling for formatted numbers such as 2,700 or $2,700
* Build and Run

Requires a C++17 compiler (g++, clang++, or MSVC).

bash
cd cpp-prototype
g++ -std=c++17 -o contestcalc contestcalc.cpp
./contestcalc

On Windows, run contestcalc.exe instead of ./contestcalc.

How to Use
=== DEALERSHIP CONTEST SYSTEM ===
1. Add New Deal Entry
2. View Current Leaderboard
3. Exit

When adding a deal, the program asks for:

Salesperson name
Whether there is a second salesperson (y/n)
New or used
Whether it is a lease (new vehicles only)
Total gross
Vehicle age
Point Rules

| Vehicle Condition | Points per $1,000 Gross |
| :--- | :--- |
| **New Vehicles** | 5 points |
| **Used Vehicles** | 8 points |

*Example:* `$6,372` gross on a new vehicle = `30 points` ($6k × 5).

---

### 2. Inventory Age Points
Older inventory earns higher bonus points to encourage aged unit sales.

#### New Vehicles
| Days in Inventory (Age) | Points |
| :--- | :--- |
| Under 25 days | 5 |
| 25 – 49 days | 10 |
| 50 – 74 days | 15 |
| 75 – 99 days | 20 |
| 100 – 124 days | 25 |
| 125 – 149 days | 35 |
| 150 – 174 days | 45 |
| 175+ days | 65 |

#### Used Vehicles
| Days in Inventory (Age) | Points |
| :--- | :--- |
| Under 20 days | 5 |
| 20 – 29 days | 10 |
| 30 – 39 days | 20 |
| 40 – 49 days | 30 |
| 50 – 59 days | 40 |
| 60 – 69 days | 50 |
| 70+ days | 60 |

---

### 3. Multipliers & Splits
* **Lease Bonus (New Vehicles Only):** Total points are **multiplied by 2**.
* **Split Deals:** Total points are **divided by 2**, and each participating salesperson receives the split amount.

> **Calculation Example:** 
> * New vehicle, Lease, Single salesperson
> * Gross: `$2,700` | Age: `150` days
> * **Gross points:** $2,000 / $1,000 = 2 \times 5 =$ `10`
> * **Age points:** (150 falls in 150–174 tier) $=$ `45`
> * **Subtotal:** $10 + 45 =$ `55`
> * **Lease Bonus:** $55 \times 2 =$ `110 points`

Changing the Rules

All point tiers and multipliers are defined in small functions near the top of cpp-prototype/contestcalc.cpp (newGrossPoints, usedGrossPoints, newAgePoints, usedAgePoints), so contest rules can be updated in one place.

Limitations
Leaderboard data is held in memory only and is lost when the program closes.
Salesperson names are case-sensitive, so "Alex" and "alex" are tracked separately.
Roadmap
Web-based version with dropdown salesperson selection and live point preview
Saved deal history
Export to a spreadsheet file for Excel
