
#include "Bullet.h"
#include "Enemy.h"
#include<Novice.h>

Bullet::Bullet()
{
	Bullet_posX = 0;
	Bullet_posY = 0;
	Bullet_speed = 10;
	Bullet_r = 10;
	isShot = 0;


}


void Bullet::BulletUpdate()
{
	if (isShot == 1) {

		Bullet_posY -= Bullet_speed;
	}
	if (Bullet_posY <= -Bullet_r) {
		isShot = 0;
	}

}

void Bullet::BulletDraw()
{
	if (isShot == 1) {
		Novice::DrawEllipse(Bullet_posX, Bullet_posY, Bullet_r, Bullet_r, 0.0f, 0xFF0000FF, kFillModeSolid);
	}

}

