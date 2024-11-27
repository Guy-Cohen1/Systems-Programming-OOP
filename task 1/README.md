# C Programming Assignments

This repository contains solutions to three C programming assignments, each focusing on different concepts such as arrays, strings, and simulation of smart systems.

## Table of Contents
1. [Treasure Hunt Game](#treasure-hunt-game)
2. [Elevator Simulation](#elevator-simulation)
3. [Smart Home System Simulation](#smart-home-system-simulation)

---

## Treasure Hunt Game

### Description
This is a simple console-based game where the player tries to find treasures in a 3x3 grid. The grid contains randomly placed treasures, and the player must move around to collect them using a limited number of moves. The game ends when the player finds all the treasures or runs out of moves.

### Features
- 3x3 grid representation using a 2D array.
- Random placement of treasures (`T`) and empty spaces (`_`).
- Player starts at a random location and can move up (`U`), down (`D`), left (`L`), or right (`R`).
- Tracks the number of treasures found.
- Ends the game when the player either finds all treasures or runs out of moves.

### Key Functions
- **initializeGame()**: Sets up the game grid and randomizes treasure locations.
- **movePlayer()**: Handles player movement and checks if a treasure is found.
- **printGrid()**: Displays the current state of the grid after each move.

---

## Elevator Simulation

### Description
This program simulates an elevator that moves between floors in a building. It uses strings to represent the floor numbers, and the user can request the elevator to move up or down.

### Features
- A string array represents the building floors.
- The user can input a floor number to request the elevator to move to that floor.
- The program displays the requested floor number in textual format (e.g., "Seventh floor").
- Error handling for invalid floor numbers and inputs.

### Key Functions
- **moveElevator()**: Moves the elevator based on user input and prints the current floor.
- **printRequestedFloor()**: Displays the requested floor number as a string (e.g., "First floor").
- **validateInput()**: Ensures that the user input is valid (e.g., no out-of-range floor numbers).

---

## Smart Home System Simulation

### Description
This program simulates a smart home system, allowing control and monitoring of basic home devices like lamps and temperature. The system allows the user to interact with the devices and visualizes the current state of the home.

### Features
- Three lamps with adjustable dimmer levels.
- A temperature control with adjustable levels.
- Visualization of the smart home system state (lamp status and temperature).
- Simulates different scenarios and updates the home state in real-time.

### Key Functions
- **initializeSmartHome()**: Initializes the home state with default values.
- **updateLighting()**: Simulates changes in lamp status and dimmer levels.
- **updateTemperature()**: Adjusts the temperature level.
- **printSmartHomeState()**: Displays the current state of the smart home.
- **drawRoom()**: Provides a visual representation of the room based on the current smart home state.
