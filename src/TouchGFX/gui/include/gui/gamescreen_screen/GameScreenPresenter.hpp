#ifndef GAMESCREENPRESENTER_HPP
#define GAMESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class GameScreenView;

class GameScreenPresenter : public Presenter, public ModelListener
{
public:
    GameScreenPresenter(GameScreenView& v);

    virtual void activate();
    virtual void deactivate();

    virtual ~GameScreenPresenter() {};

    virtual void toggleAllTiles();
    virtual void updateBoardView(int board[4][4]);
    virtual void gameover();
    void retry();
    virtual void gameWon();
    virtual void keepPlaying();
    virtual void updateScore(int score, int highScore);

private:
    GameScreenPresenter();
    GameScreenView& view;
};

#endif // GAMESCREENPRESENTER_HPP
