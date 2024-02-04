#include "Player.h"
#include<Novice.h>
#include "Bullet.h"

Player::Player()
{

	player_posX = 500;
	player_posY = 400;
	player_r = 30;
	player_speed = 10;

	
	isDead = false;
	
	

}

Player::~Player()
{
	

}

void Player::Update(char* keys, char* preKeys)
{

	if (keys[DIK_A]) {
		player_posX -= player_speed;
	}
	if (keys[DIK_D]) {
		player_posX += player_speed;
	}
	if (keys[DIK_W]) {
		player_posY -= player_speed;
	}
	if (keys[DIK_S]) {
		player_posY += player_speed;
	}

	
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && isShot==0) {
		Bullet_posX = player_posX;
		Bullet_posY = player_posY;
		isShot = 1;
	}
		

	

	
	BulletUpdate();
	

}

void Player::Draw()
{
	if (isDead == 0) {
		Novice::DrawEllipse(player_posX, player_posY, player_r, player_r, 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}
	
	
	BulletDraw();
	


}

