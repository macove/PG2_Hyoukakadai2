#include "Collision.h"
#include <math.h>
void Collision::Update(char* keys, char* preKeys)
{
	playerA_->Update(keys, preKeys);

	enemyA_->Update();

	
	CheckCollisionWithEnemy();
	CheckCollisionWithPlayer();
}
void Collision::Draw()
{
	playerA_->Draw();

	enemyA_->Draw();
}
Collision::Collision()
{

	
	enemyA_ = new Enemy(100,100,1);
	playerA_ = new Player();

}

void Collision::CheckCollisionWithEnemy()
{
	float distance = sqrtf(float((enemyA_->getEnemyPosX() - playerA_->getBulletPosX()) * (enemyA_->getEnemyPosX() - playerA_->getBulletPosX()) +
		float((enemyA_->getEnemyPosY() - playerA_->getBulletPosY()) * (enemyA_->getEnemyPosY() - playerA_->getBulletPosY()))));
	float sumOfRad = float(enemyA_->getEnemyRadius()) + float(playerA_->getBulletRadius());
	if (distance <= sumOfRad) {
		enemyA_->setEnemyIsAlive(false);
	}


}

void Collision::CheckCollisionWithPlayer()
{
	float distance = sqrtf(float((enemyA_->getEnemyPosX() - playerA_->getPosX()) * (enemyA_->getEnemyPosX() - playerA_->getPosX()) +
		float((enemyA_->getEnemyPosY() - playerA_->getPosY()) * (enemyA_->getEnemyPosY() - playerA_->getPosY()))));
	float sumOfRad = float(enemyA_->getEnemyRadius()) + float(playerA_->getRadius());
	if (distance <= sumOfRad) {
		playerA_->setIsDead(true);
	}
}
