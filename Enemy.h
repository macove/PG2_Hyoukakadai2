
#pragma once
#include "Bullet.h"
#include "Novice.h"
#include <math.h>


class Enemy
{
public:

	int getEnemyPosX() { return enemy_posX_; };
	int getEnemyPosY() { return enemy_posY_; };
	int getEnemyRadius() { return enemy_radius_; };
	int getEnemyIsAlive() { return enemyIsAlive_; };

	void setEnemyIsAlive(bool x) { enemyIsAlive_ = x; };
	void setEnemyPosX(int x) { enemy_posX_ = x; };
	void setEnemyPosY(int y) { enemy_posY_ = y; };

	void respawn();

private:

	

	int enemy_posX_;
	int enemy_posY_;
	int enemy_speed_;
	int enemy_radius_;
	int enemyIsAlive_;
	int enemyTimer_;


public:
	Enemy(int enemy_posX, int enemy_posY, int enemyIsAlive);

	void Update();
	void Draw();

};

