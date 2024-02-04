#pragma once
#include"Bullet.h"

class Player : public Bullet
{



private:


	//Bullet* bullet_;
	
	int player_posX;
	int player_posY;
	int player_r;
	int player_speed;

	bool isDead;

public:

	int getPosX() { return player_posX; };
	int getPosY() { return player_posY; };
	int getRadius() { return player_r; };
	bool getIsDead() { return isDead; };

	void setIsDead(bool x) { isDead = x; };
	void setPosX(int x) { player_posX = x; };
	void setPosY(int y) { player_posY = y; };

	int getBulletPosX() { return Bullet_posX; };
	int getBulletPosY() { return Bullet_posY; };
	int getBulletRadius() { return Bullet_r; };


	Player();

	~Player();

	void Update(char* keys, char* preKeys);
	void Draw();

};


