#define IMM2D_IMPLEMENTATION

#define IMM2D_WIDTH 400
#define IMM2D_HEIGHT 300
#define IMM2D_SCALE 2

#include "immediate2d.h"


class Scratchcard
{
public:
	Scratchcard ();
	~Scratchcard ();
	void Run ();
	void Init ();
	void Check ();

private:
	bool done;
	int radius;
	Image money;
	Color* pictureData;

};

Scratchcard::Scratchcard ()
{
	done = false;
	pictureData = new Color[Width * Height];
	radius = 16;
	money = LoadImage ("money.jpg");
	Init ();
}

Scratchcard::~Scratchcard ()
{
	delete[] pictureData;
}

void Scratchcard::Init ()
{
	done = false;
	Clear (White);
	if (RandomInt (0, 10) < 7) {
		DrawImage (Width / 4 - ImageWidth (money) / 4, Height / 3 - ImageHeight (money) / 4, money);
		DrawImage (Width / 4 * 3 - ImageWidth (money) / 4, Height / 3 - ImageHeight (money) / 4, money);
		DrawImage (Width / 4 - ImageWidth (money) / 4, Height / 3 * 2 - ImageHeight (money) / 4, money);
		DrawImage (Width / 4 * 3 - ImageWidth (money) / 4, Height / 3 * 2 - ImageHeight (money) / 4, money);
		DrawString (Width / 2, Height / 2, "You won!", "", 16, Green, true);
	} else {
		DrawString (Width / 2, Height / 2, "You lost!", "", 16, Red, true);
	}

	for (int j = 0; j < Height; j++) {
		for (int i = 0; i < Width; i++) {
			pictureData[j * Width + i] = ReadPixel (i, j);
		}
	}
	Clear (Black);
	DrawString (Width / 2, Height / 2, "Use mouse to scratch!", "", 16, Yellow, true);
}


void Scratchcard::Run ()
{
	if (done && LastKey () == 'r') {
		Init ();
	}

	int x = MouseX ();
	int y = MouseY ();
	
	bool mouseOffScreen = x < 0 || y < 0 || x > Width || y > Height;
	if (!mouseOffScreen && LeftMousePressed ()) {
		for (int i = -radius/2; i < radius/2; i++) {
			for (int j = -radius / 2; j < radius / 2; j++) {
				bool offscrean = (x +i) < 0 || (y+j) < 0 || (x + i) > Width || (y + j) > Height;
				if (!offscrean)
					DrawPixel ((x + i), (y + j), pictureData[(y + j) * Width + (x + i)]);
			}
		}
	}
	Check ();
}
void Scratchcard::Check ()
{
	int counter = 0;
	for (int j = Height/3; j < Height/3*2; j++) {
		for (int i = Width/3; i < Width/3*2; i++) {
			if (ReadPixel (i, j) == pictureData[j * Width + i])
				counter++;
		}
	}
	if (float(counter) / (Height / 3 * Width / 3) > .9) {
		DrawString (Width / 2, Height / 3*2, "Scratch again by pressing R!", "", 16, LightGray, true);
		done = true;
	}
	
}


void run ()
{
	Scratchcard card;
	while (true) {
		Wait (5);
		card.Run ();
	}
}