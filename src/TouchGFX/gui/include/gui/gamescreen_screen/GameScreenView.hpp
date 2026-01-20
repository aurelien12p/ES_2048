#ifndef GAMESCREENVIEW_HPP
#define GAMESCREENVIEW_HPP

#include <gui_generated/gamescreen_screen/GameScreenViewBase.hpp>
#include <gui/gamescreen_screen/GameScreenPresenter.hpp>

#include <gui/containers/TileContainer.hpp>
#include <gui/containers/PopUpGameOver.hpp>
#include <gui/containers/PopUpWin.hpp>

class GameScreenView : public GameScreenViewBase
{
public:
    GameScreenView();
    virtual ~GameScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void displayModel(int board[4][4]);
    void showGameOver();
    void showWin();
    void updateScore(int score, int highScore);

    void toggleTilesVisibility();

    void onRetryHandler();
    void onWinRetryHandler();
    void onWinContinueHandler();

protected:
    TileContainer* tilesArray[16];
    bool areTilesVisible;

    touchgfx::Callback<GameScreenView> retryCallback;
    touchgfx::Callback<GameScreenView> winRetryCallback;
    touchgfx::Callback<GameScreenView> winContinueCallback;
    touchgfx::Unicode::UnicodeChar myScoreBuffer[20];
	touchgfx::Unicode::UnicodeChar myBestScoreBuffer[20];
};

#endif
