Dealership Sales Contest Calculator

A command-line tool for calculating monthly sales contest points at a car dealership. Enter each deal, and the program works out the points for each salesperson and keeps a running leaderboard.

This is a C++ prototype for testing the point logic. A web version is planned.

Features
Add deals for one or two salespeople (split deals)
Separate point rules for new and used vehicles
Lease deals (new vehicles only) earn double points
Running leaderboard sorted by total points
Input handling for formatted numbers such as 2,700 or $2,700
Build and Run

Requires a C++17 compiler (g++, clang++, or MSVC).

bash
g++ -std=c++17 -o contest contest.cpp
./contest

On Windows, run contest.exe instead of ./contest.

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

Points for a deal are the gross points plus the age points.

Gross Points

Points are awarded per whole $1,000 of gross. Partial thousands are not counted.

Vehicle	Points per $1,000
New	5
Used	8

Any gross under $1,000, including a negative gross, earns 0 gross points.

Examples: $6,372 on a new vehicle = 30 points. $7,200 on a used vehicle = 56 points.

Age Points (New Vehicles)
Age	Points
Under 25	5
25 to 49	10
50 to 74	15
75 to 99	20
100 to 124	25
125 to 149	35
150 to 174	45
175+	65
Age Points (Used Vehicles)
Age	Points
Under 20	5
20 to 29	10
30 to 39	20
40 to 49	30
50 to 59	40
60 to 69	50
70+	60
Multipliers
Lease (new vehicles only): total points are doubled.
Split deal: total points are divided by 2, and each salesperson receives that amount.
Example

New vehicle, lease, one salesperson (no split), gross $2,700, age 150:

Gross points: 2 x 5            = 10
Age points:   150 falls in 150-174 = 45
Subtotal:     10 + 45          = 55
Lease:        55 x 2           = 110

The salesperson receives 110 points.

Changing the Rules

All point tiers and multipliers are defined in small functions near the top of contest.cpp (newGrossPoints, usedGrossPoints, newAgePoints, usedAgePoints), so contest rules can be updated in one place.

Limitations
Leaderboard data is held in memory only and is lost when the program closes.
Salesperson names are case-sensitive, so "Alex" and "alex" are tracked separately.
Roadmap
Web-based version with dropdown salesperson selection and live point preview
Saved deal history
Export to a spreadsheet file for Excel