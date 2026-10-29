# Dealership Sales Contest Calculator 🚗💨

A robust, command-line tool written in C++ designed to automate monthly sales contest point calculations at an automotive dealership. It processes individual deal entries, applies dynamic gross profit and inventory age multipliers, and maintains a real-time leaderboard.

This project serves as a lightweight C++ prototype for testing complex dealership business logic before scaling to a full-stack web application.

---

## 🚀 Features

* **Flexible Deal Entry:** Supports single salespeople or split deals (50/50 point distribution between two representatives).
* **Smart Condition Rules:** Separate tier calculations for **New** and **Used** vehicle inventory.
* **Lease Incentives:** Automatically doubles total points for eligible new vehicle leases.
* **Real-Time Leaderboard:** Automatically sorts and ranks salespeople by total points using standard library algorithms.
* **Robust Input Sanitization:** Safely parses messy user inputs (stripping commas, dollar signs, and extra spaces) and handles invalid data gracefully without crashing.

---

## 📊 Point System & Rules

A deal's total score is calculated by combining **Gross Points** and **Inventory Age Points**, then applying any applicable multipliers.

### 1. Gross Points
Points are awarded per whole $1,000 of gross profit. Partial thousands and negative grosses (losses) earn 0 gross points.

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

---

## ⚙️ Build and Run

### Prerequisites
Requires a standard-compliant **C++17 compiler** (`g++`, `clang++`, or MSVC).

### Compilation & Execution (Linux / macOS / Git Bash)
```bash
g++ -std=c++17 -O3 contestcalc.cpp -o contest
./contest