#include "Enemy.h"




void Enemy::respawn()
{
	if (enemyIsAlive_ == 0) {
		enemyTimer_++;
	}
	if (enemyTimer_ == 120) {
		enemyIsAlive_ = 1;
		enemyTimer_ = 0;
	}
	
}

Enemy::Enemy(int enemy_posX, int enemy_posY, int enemyIsAlive)
	
{
	
	enemy_posX_ = enemy_posX;
	enemy_posY_ = enemy_posY;
	enemy_speed_ = 8;
	enemy_radius_ = 50;
	enemyIsAlive_ = enemyIsAlive;
	enemyTimer_ = 0;
	

}

void Enemy::Update()
{
	if (enemyIsAlive_ == 1) {
		enemy_posX_ += enemy_speed_;

		if (enemy_posX_ - enemy_radius_ <= 0 || enemy_posX_ + enemy_radius_ >= 1280) {
			enemy_speed_ *= -1;
		}
	}
	

	respawn();

}





void Enemy::Draw()
{
	if (enemyIsAlive_ == 1) {
		Novice::DrawEllipse(enemy_posX_, enemy_posY_, enemy_radius_, enemy_radius_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}
	

}

