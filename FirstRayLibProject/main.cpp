#include <iostream>
#include <raylib.h>
#include "Paddle.hpp"
#include "CpuPaddle.h"
#include "Ball.hpp"

constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 800;



Paddle player(SCREEN_WIDTH - player.GetWidth() - 10, SCREEN_HEIGHT / 2 - player.GetHeight() / 2, 25, 120, 6);
CpuPaddle cpu(10, SCREEN_HEIGHT / 2, 25, 120, 6);
Ball ball(GetScreenWidth() / 2, GetScreenHeight() / 2, 9, 9, 20, cpu, player);

int main()
{

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong Game");
	SetTargetFPS(60);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(BLACK);

		//Update

		int y_pos = ball.GetYPosition();
		ball.Update();
		player.Update();
		cpu.Update(y_pos);

		if (CheckCollisionCircleRec(Vector2{ ball.GetXPosition(), ball.GetYPosition() }, ball.GetRadius()
			,Rectangle{ player.GetXPosition(),player.GetYPosition(),player.GetWidth(),player.GetHeight() }))
		{
			int speed = ball.GetXSpeed();
			speed *= -1;
			ball.SetXSpeed(speed);
		}

		if (CheckCollisionCircleRec(Vector2{ ball.GetXPosition(),ball.GetYPosition() }, ball.GetRadius()
			,Rectangle{ cpu.GetXPosition(), cpu.GetYPosition(), cpu.GetWidth(), cpu.GetHeight() }))
	
		{
			int speed = ball.GetXSpeed();
			speed *= -1;
			ball.SetXSpeed(speed);
		}
	



		//Drawing

		DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);
		ball.Draw();
		cpu.Draw();
		player.Draw();

		DrawText(TextFormat("%i", cpu.GetScore()), SCREEN_WIDTH / 4 - 20, 20, 80,WHITE);
		DrawText(TextFormat("%i", player.GetScore()), 3 * SCREEN_WIDTH / 4 - 20, 20, 80,WHITE);

		EndDrawing();

	}

	CloseWindow();

	return EXIT_SUCCESS;
}
