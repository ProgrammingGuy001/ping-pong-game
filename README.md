# Ping Pong Game

This is a simple Ping Pong game built using the Raylib library in C++. The game includes a player-controlled paddle and an AI-controlled paddle. The objective is to hit the ball past the opponent's paddle to score points.

## Features

- Player-controlled paddle using `W` and `S` keys.
- AI-controlled paddle that follows the ball.
- Score tracking for both the player and the AI.
- Simple collision detection and response.

## Requirements

- C++ Compiler
- Raylib library

## Installation

### 1. Install Raylib

Before running the game, you need to install the Raylib library. Follow the instructions on the official [Raylib GitHub page](https://github.com/raysan5/raylib) to install Raylib for your operating system.

### 2. Clone the repository

```bash
git clone https://github.com/ProgrammingGuy001/ping-pong-game.git
cd ping-pong-game
```

### 3. Compile the game

Make sure you have a C++ compiler installed. You can compile the game using the following command:

```bash
g++ -o pingpong main.cpp -lraylib
```

### 4. Run the game

After compiling, you can run the game using the following command:

```bash
./pingpong
```

## Controls

- `W` - Move the player paddle up
- `S` - Move the player paddle down

## Game Mechanics

- The ball starts at the center of the screen and moves in a random direction.
- The player can move their paddle up and down using the `W` and `S` keys.
- The AI paddle automatically follows the ball's vertical position.
- The ball bounces off the top and bottom edges of the screen.
- If the ball passes the player's paddle, the AI scores a point.
- If the ball passes the AI's paddle, the player scores a point.
- The game keeps track of the scores and displays them on the screen.

## License

This project is licensed under the MIT License. 

---

Enjoy playing the Ping Pong game! Feel free to contribute and improve the game by submitting pull requests.
