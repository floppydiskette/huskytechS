#pragma once
class Room
{
public:
	Room(int s_x, int s_y);

	int GetSizeX();
	int GetSizeY();

private:
	int size_x = 1; //how big this room is (how many tiles)
	int size_y = 1;
};

