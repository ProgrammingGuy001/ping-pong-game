#include <iostream>
#include <raylib.h>
#include <cstdlib> // for rand and srand
#include <ctime>   // for seeding srand

using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;
Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

int main()
{
    // Initialization
    InitWindow(screenWidth, screenHeight, "ping pong game");
    SetTargetFPS(60);

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Ball starting position and velocity
    float ballX = screenWidth / 2.0f;
    float ballY = screenHeight / 2.0f;
    float velocityX = 5.0f;
    float velocityY = 5.0f;
    int playerScore = 0;
    int AIScore = 0;

    // Player paddle
    const int playerBoardX = 0;
    int playerBoardY = screenHeight / 2 - 50;
    const int playerBoardWidth = 15;
    const int playerBoardHeight = 100;

    // AI paddle
    const int AIBoardX = screenWidth - 15;
    int AIBoardY = screenHeight / 2 - 50;
    const int AIBoardWidth = 15;
    const int AIBoardHeight = 100;

    // Erratic movement and miss chance variables
    int missChance = 10; // Adjust this for frequency of misses (e.g., 10 for 10% chance)
    bool shouldMiss = false;
    int erraticMovement = 0; // To store random "wobble" direction

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update ball position based on velocity
        ballX += velocityX;
        ballY += velocityY;

        // Randomly decide if AI should miss or move erratically
        shouldMiss = (rand() % 100 < missChance); // Chance to miss the ball
        erraticMovement = (rand() % 3) - 1; // -1, 0, or +1 for slight movement variance

        // Update AI paddle position with chance of missing and erratic movement
        if (!shouldMiss)
        {
            if (ballY < AIBoardY + AIBoardHeight / 2 && AIBoardY > 0)
            {
                AIBoardY -= (5 + erraticMovement); // Move up with random fluctuation
            }
            else if (ballY > AIBoardY + AIBoardHeight / 2 && AIBoardY < screenHeight - AIBoardHeight)
            {
                AIBoardY += (5 + erraticMovement); // Move down with random fluctuation
            }
        }

        // Check for collision with the player paddle
        if (ballX <= playerBoardX + playerBoardWidth &&
            ballY >= playerBoardY && ballY <= playerBoardY + playerBoardHeight)
        {
            velocityX = -velocityX;
            ballX = playerBoardX + playerBoardWidth; // Prevent the ball from getting stuck
        }

        // Check for collision with the AI paddle
        if (ballX >= AIBoardX - AIBoardWidth &&
            ballY >= AIBoardY && ballY <= AIBoardY + AIBoardHeight)
        {
            velocityX = -velocityX;
            ballX = AIBoardX - AIBoardWidth; // Prevent the ball from getting stuck
        }

        // Check for collision with the right edge of the screen
        if (ballX >= screenWidth)
        {
            ballX = screenWidth / 2;
            ballY = screenHeight / 2;
            playerScore++;
        }

        // Check for collision with the left edge of the screen (missed by the player)
        if (ballX <= 0)
        {
            ballX = screenWidth / 2;
            ballY = screenHeight / 2;
            AIScore++;
        }

        // Check for collision with the top and bottom edges of the screen
        if (ballY <= 0 || ballY >= screenHeight)
        {
            velocityY = -velocityY;
        }

        // Check for W and S key presses
        if (IsKeyDown(KEY_W) && playerBoardY > 0)
        {
            playerBoardY -= 10;
        }
        if (IsKeyDown(KEY_S) && playerBoardY < screenHeight - playerBoardHeight)
        {
            playerBoardY += 10;
        }

        // Draw everything
        BeginDrawing();
        ClearBackground(Dark_Green);
        DrawRectangle(screenWidth / 2, 0, screenWidth / 2, screenHeight, Green);
        DrawCircle(screenWidth / 2, screenHeight / 2, 150, Light_Green);
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        
        // Draw the ball
        DrawCircle(static_cast<int>(ballX), static_cast<int>(ballY), 20, YELLOW);
        // Draw the player paddle
        DrawRectangle(playerBoardX, playerBoardY, playerBoardWidth, playerBoardHeight, WHITE);
        // Draw the AI paddle
        DrawRectangle(AIBoardX, AIBoardY, AIBoardWidth, AIBoardHeight, WHITE);
        
        // Draw the scores
        DrawText(TextFormat("Player Score: %d", playerScore), 10, 50, 20, BLACK);
        DrawText(TextFormat("AI Score: %d", AIScore), screenWidth - 150, 50, 20, BLACK);
        
        EndDrawing();
    }

    // De-initialization
    CloseWindow();
    return 0;
}
