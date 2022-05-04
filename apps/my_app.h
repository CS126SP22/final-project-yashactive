//
// Created by Yashovardhan maheshwari  on 29/04/22.
//
#pragma once
#ifndef FLAPPY_GAME_MY_APP_H
#define FLAPPY_GAME_MY_APP_H
#include <cinder/app/App.h>
#include "game_engine.h"
#include "obstacles.h"
#include "game_object.h"
using std::list;
using std::string;
using namespace flappygame;

namespace flappygameapp {
    class FlappyGame : public cinder::app::App {
    public:

        /**
         * Constructor to initialize the Game
         */
        FlappyGame();

        /**
         * Adds the Obstacles to the Game
         */
        void setup() override;

        /**
         * Changes the Position of the game object and Obstacle
         */
        void update() override;

        /**
         * Helps determine the controls of the game
         */
        void keyDown(cinder::app::KeyEvent) override;

        /**
         * Draws all the components of the game
         */
        void draw() override;

        /**
         * Draws the End screen of the game once the game has ended
         */
        void GameEndScreen();

        /**
         * Checks if the object has collided with any of the obstacle
         * @return True if the object has collided otherwise it returns false
         */
        bool CheckObjectCollision();

        /**
         * Draws the Background elements of the game
         */
        void GameBackground();

        /**
         * Draws the Main menu of the game
         */
        void MainMenuScreen();

        /**
         * Displays the current game screen with the game object and obstacles.
         */
        void GameScreen();

    private:
        /** A list of all the obstacles **/
        list<Obstacles> obstacles_;

        /** The Game Object **/
        GameObject object_;

        /** The score of the player **/
        size_t score_;

        /** The Game Engine Object **/
        ObstacleGameEngine obstacle_engine_;

        /** state displaying whether the game has ended or not */
        bool game_ended_state_;

        /** State depicting if the game is on the main menu **/
        bool game_main_menu_;

        /** Number of frames the player has played */
        size_t game_frames_count_;

        /** The number of obstacles added in the beginning frames **/
        const size_t kObstaclesCount_ = 5 * 1;

        /** The height of the ground in the game **/
        const size_t kHeightGround_ = 200 ;

        /** The number of beginning frames **/
        const size_t kStartingFramesCount_ = 150 * 1;

        /** The color White **/
        const cinder::Color kWhite_ = cinder::Color::white();

        /** The color Black **/
        const cinder::Color kBlack_ = cinder::Color::black();

        /** Helper variable to determine X coord of the position of score **/
        const double kScoreXCoordDeterminer_ = 2.0 * 1;

        /** Helper variable to determine Y coord of the position of score **/
        const double kScoreYCoordDeterminer_ = 8.7 * 1;

    };



}
#endif //FLAPPY_GAME_MY_APP_H
