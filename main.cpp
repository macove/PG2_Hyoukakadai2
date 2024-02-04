#include <Novice.h>
#include "Player.h"
#include"Enemy.h"
#include "Collision.h"

const char kWindowTitle[] = "GC1B_11_パク_イジュン_評価課題2";


enum Scene
{
	TITLE,
	GAME,
	OVER


};

Scene scene;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//Player* player = new Player();
	//Enemy* enemyA = new Enemy(100, 100,1);
	Collision* collision = new Collision();
	scene = TITLE;

	int titleImage = Novice::LoadTexture("./Image/title.png");
	int overImage = Novice::LoadTexture("./Image/over.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		//player->Update(keys, preKeys);
		//enemyA->Update();
		
		switch (scene)
		{
		case TITLE:

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = GAME;
	
			}

			break;
		case GAME:
			collision->Update(keys, preKeys);

			if (collision->playerA_->getIsDead() == true) {
				scene = OVER;
			}

			break;
		case OVER:
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {

				collision->playerA_->setIsDead(false);
				collision->playerA_->setPosX(500);
				collision->playerA_->setPosY(400);

				collision->enemyA_->setEnemyIsAlive(true);
				collision->enemyA_->setEnemyPosX(100);
				collision->enemyA_->setEnemyPosY(100);

				scene = TITLE;

			}



			break;
		default:
			break;
		}


		



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		//player->Draw();
		//enemyA->Draw();
		//if (enemyA->CheckCollisionWithEnemy()== 0) {
		//	enemyA->Draw();
		//	
		//}
		//if (enemyA->CheckCollisionWithEnemy() == 1) {
		//	Novice::ScreenPrintf(0, 0, "0");
		//}
		
		//Novice::ScreenPrintf(0, 0, "%d", enemyA->CheckCollisionWithEnemy());


		switch (scene)
		{
		case TITLE:

			Novice::DrawSprite(0, 0, titleImage, 1, 1, 0, 0xFFFFFFFF);

			break;
		case GAME:

			collision->Draw();
			
			break;
		case OVER:
			Novice::DrawSprite(0, 0, overImage, 1, 1, 0, 0xFFFFFFFF);
			break;
		default:
			break;
		}

		


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
