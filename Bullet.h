#pragma once

class Bullet
{
public:

	int Bullet_posX;
	int Bullet_posY;
	int Bullet_speed;
	int Bullet_r;
	int isShot;


	

public:

	Bullet();

	void BulletUpdate();
	void BulletDraw();


};

