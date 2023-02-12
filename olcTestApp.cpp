#define OLC_PGE_APPLICATION
#include "external/olcPixelGameEngine/olcPixelGameEngine.h"

class TictacToeWindow : public olc::PixelGameEngine
{
public:
	TictacToeWindow() {
		sAppName = "TictacToe";
	}

	bool OnUserCreate() override {
    // Set up the initial state of the game
    // ...

    // Draw the lines for the 3x3 grid
	draw_grid_lines();

    return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
    // Handle user input and update the game state
		if(p1_turn) {
			color = olc::RED;
		}
		else {
			color = olc::BLUE;
		}

		change_tile_color(color);
		return true;
	}

	private:
	bool p1_turn = true;
	olc::Pixel color {};

	void draw_grid_lines() {
		int w = ScreenWidth() / 3;
    	int h = ScreenHeight() / 3;

    	for (int i = 1; i < 3; i++) {
        	DrawLine(i * w, 0, i * w, ScreenHeight(), olc::WHITE);
        	DrawLine(0, i * h, ScreenWidth(), i * h, olc::WHITE);
    	}
	}

	void change_tile_color(olc::Pixel color) {
		if (GetMouse(0).bPressed) {
			// Calculate which square was clicked
			int x = GetMouseX() / (ScreenWidth() / 3);
			int y = GetMouseY() / (ScreenHeight() / 3);
			// Change the color of the clicked square
			FillRect(x * (ScreenWidth() / 3), y * (ScreenHeight() / 3), ScreenWidth() / 3, ScreenHeight() / 3, color);
			p1_turn = !p1_turn;
		}
		draw_grid_lines();
	}
};


int main() {
	TictacToeWindow demo;
	if (demo.Construct(240, 240, 4, 4))
		demo.Start();

	return 0;
}
