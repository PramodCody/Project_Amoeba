//pragma once has been removed.
#pragma once

class Graphics {
public:
	Graphics();
	int InitX, InitY;
	int SetInitialPosition(int x, int y);
	void DrawRect(int RelativePosition);
};
