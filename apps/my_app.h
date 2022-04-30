//
// Created by Yashovardhan maheshwari  on 29/04/22.
//

#ifndef FLAPPY_GAME_MY_APP_H
#define FLAPPY_GAME_MY_APP_H
#include <cinder/app/App.h>
#include "game_engine.h"
#include "obstacles.h"
#include "game_object.h"
using std::list;
using namespace flappygame;

namespace flappygameapp {
    class FlappyGame :  public cinder::app::App {
    public:
        FlappyGame();
        void setup() override;
        void update() override;
        void draw() override;
        void keyDown(cinder::app::KeyEvent) override;

    private:
        void GameEndDraw();
        void MainMenuDraw();
        bool ObjectCollide();
        void BackgroundDraw();
        void DrawGameScreen();
        list<Obstacles> obstacles_;
        GameObject object_;
        size_t score_;
        ObstacleGameEngine obs_engine_;
        bool game_ended_;
        bool game_main_menu_state_;
        size_t  playing_frames_;







    };

}
#endif //FLAPPY_GAME_MY_APP_H
