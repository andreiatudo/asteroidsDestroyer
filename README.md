# Description
This project simulates a resource mining mission from asteroids using rockets, each with its own characteristics and operational costs. The goal is to optimize resource usage and associated costs, maximizing profit from selling the extracted resources. This involves calculating fuel costs, gross and net profit, and evaluating each rocket's efficiency based on its performance in multiple missions.

# Requirements
## Reading Input Files:
The input files will contain information about rockets, asteroids, and market prices.

- **rockets.csv**: Details about rockets, including transport capacity, fuel consumption, available fuel, and fuel price.
- **asteroids.csv**: Information about asteroids, including available resources, total quantity, extraction yield, and distance to the asteroid.
- **market.csv**: Market prices for resources, including the minimum and maximum price per kilogram.

## Mission Calculations:
Rocket missions will be calculated for each asteroid, starting with extracting resources from the first asteroid and continuing with the second asteroid if necessary. For each mission, the following will be calculated:

- **Extracted quantity (kg)**: The amount of resource that the rocket can extract, based on yield and rocket capacity.
- **Fuel consumed (kg)**: The amount of fuel used to reach the asteroid and return, considering distance and consumption per 1000 km.
- **Fuel cost ($)**: The cost of fuel used in the mission, calculated based on price per kilogram.
- **Gross profit ($)**: The profit obtained from selling the extracted resources, calculated based on the current market price.
- **Net profit ($)**: The profit obtained after deducting the fuel cost from the gross profit.

## Total Profit Calculation per Rocket:
The total profit obtained by each rocket will be calculated based on completed missions, including gross profit, total fuel cost, and net profit.

## Profit Calculation per Resource:
Gross profit and total extracted quantity will be calculated for each resource separately (Gold, Iron, Copper).

## Rocket Ranking:
Rockets will be ranked based on the net profit obtained from missions, and the efficiency of each rocket will be evaluated based on the efficiency score (Net profit divided by the number of completed missions).

# FunctionsHelper

## **citireAsteroizi** (readAsteroids)

- Read the first line with the titles.
- Read line by line, separating based on the `;` delimiter.
- Functions used:
  - `linie.find` finds the first position of the `;` delimiter and continues as long as the delimiter exists.
  - `substr` provides a substring.
  - `stoi` converts a string to an integer.
  - `linie.erase(0, poz+1)` deletes characters from the beginning and removes the specified number of characters.
- Create the object and add it to the vector.

## **citireRachete** (readRockets) and **citirePiata** (readMarket)

- Structure similar to `citireAsteroizi`.
- The information follows the example from OCW.

## **calculareKgTotalePerAsteroid** (calculateTotalKgPerAsteroid)

- Calculates the total amount extracted from the asteroid.

## **distantePerAsteroid** (distancesPerAsteroid)

- Calculates the distances from each asteroid.

## **creareMisiuni** (createMissions)

- I apologize in advance for the fact that the function is so long; I know I could have split it into several subprograms.
- **Vectors used:**
  - The missions vector.
  - The vector with total kg per asteroid.
  - The vector with the rocket order.
  - The vector with distances per asteroid.

### **Steps:**

1. Traverse the `kgTotalePerAsteroid` vector.
2. Calculate the rocket with the minimum cost, based on the number of trips it would make and how much one trip costs.
3. Adjust the total kg vector for the asteroid.
4. Calculate the fuel cost.
5. Then I considered 3 cases:

   - **The case where the rocket's capacity is greater than the kg of a particular resource from the asteroid:**
     - It is divided into 2 sub-cases:
       1. If there are still resources on the asteroid, check if they fit in the rocket.
       2. If they don't fit, add as much as possible to the rocket and continue with the next trip.
       3. If everything fits, add all of the resource's amount.
       - In these 2 cases, adding two types of resources in the same rocket happens.

   - **The case where the rocket's capacity is less than the kg of a particular resource from the asteroid:**
     - In this case, fill the rocket, then move to the next one in the order vector.

6. Calculate the gross profit during this time.

