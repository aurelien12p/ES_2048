#include <gui/gamescreen_screen/GameScreenView.hpp>
#include <gui/gamescreen_screen/GameScreenPresenter.hpp>

GameScreenPresenter::GameScreenPresenter(GameScreenView& v)
    : view(v)
{
}

void GameScreenPresenter::activate()
{
	model->resetGame();
    view.updateScore(model->getScore(), model->getHighScore());
}

void GameScreenPresenter::retry()
{
    model->resetGame();
}

void GameScreenPresenter::deactivate()
{
}

void GameScreenPresenter::toggleAllTiles()
{
    view.toggleTilesVisibility();
}

void GameScreenPresenter::updateBoardView(int board[4][4])
{
    view.displayModel(board);
}

void GameScreenPresenter::gameover()
{
    view.showGameOver();
}

void GameScreenPresenter::gameWon()
{
    view.showWin();
}

void GameScreenPresenter::keepPlaying()
{
    model->keepPlaying();
}

void GameScreenPresenter::updateScore(int score, int highScore)
{
    view.updateScore(score, highScore);
}
