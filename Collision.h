#pragma once
#include"Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include<Novice.h>
class Collision
{

public:

	
	Enemy* enemyA_;
	Player* playerA_;

	void Update(char* keys, char* preKeys);
	void Draw();
public:

	Collision();

	void CheckCollisionWithEnemy();

	void CheckCollisionWithPlayer();

};

