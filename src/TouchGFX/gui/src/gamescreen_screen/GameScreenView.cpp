#include <gui/gamescreen_screen/GameScreenView.hpp>

GameScreenView::GameScreenView() :
    areTilesVisible(true),
    retryCallback(this, &GameScreenView::onRetryHandler),
    winRetryCallback(this, &GameScreenView::onWinRetryHandler),
    winContinueCallback(this, &GameScreenView::onWinContinueHandler)
{
}

void GameScreenView::setupScreen()
{
    GameScreenViewBase::setupScreen();

    tilesArray[0] = &tile11; tilesArray[1] = &tile12; tilesArray[2] = &tile13; tilesArray[3] = &tile14;
    tilesArray[4] = &tile21; tilesArray[5] = &tile22; tilesArray[6] = &tile23; tilesArray[7] = &tile24;
    tilesArray[8] = &tile31; tilesArray[9] = &tile32; tilesArray[10] = &tile33; tilesArray[11] = &tile34;
    tilesArray[12] = &tile41; tilesArray[13] = &tile42; tilesArray[14] = &tile43; tilesArray[15] = &tile44;

    for(int i = 0; i < 16; i++)
    {
        if(tilesArray[i] != 0)
        {
            tilesArray[i]->setVisible(false);
            tilesArray[i]->invalidate();
        }
    }

    popUpGameOver1.setVisible(false);
    popUpGameOver1.setRetryCallback(retryCallback);
    popUpGameOver1.invalidate();

    popUpWin1.setVisible(false);
    popUpWin1.setResetCallback(winRetryCallback);
    popUpWin1.setContinueCallback(winContinueCallback);
    popUpWin1.invalidate();

    currentScore.setWildcard(myScoreBuffer);
	bestScore.setWildcard(myBestScoreBuffer);
}

void GameScreenView::tearDownScreen()
{
    GameScreenViewBase::tearDownScreen();
}

void GameScreenView::toggleTilesVisibility()
{
    areTilesVisible = !areTilesVisible;

    for(int i = 0; i < 16; i++)
    {
        if(tilesArray[i] != 0)
        {
            tilesArray[i]->setVisible(areTilesVisible);
            tilesArray[i]->invalidate();
        }
    }
}

void GameScreenView::displayModel(int board[4][4])
{
    int index = 0;
    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            int value = board[row][col];
            TileContainer* tile = tilesArray[index];

            if(tile != 0)
            {
                if(value == 0)
                {
                    tile->setVisible(false);
                }
                else
                {
                    tile->setVisible(true);
                    tile->setVal(value);
                }
                tile->invalidate();
            }
            index++;
        }
    }
}


void GameScreenView::showGameOver()
{
    popUpGameOver1.setVisible(true);
    popUpGameOver1.invalidate();
}

void GameScreenView::onRetryHandler()
{
    presenter->retry();
    popUpGameOver1.setVisible(false);
    popUpGameOver1.invalidate();
}


void GameScreenView::showWin()
{
    popUpWin1.setVisible(true);
    popUpWin1.invalidate();
}

void GameScreenView::onWinRetryHandler()
{
    presenter->retry();
    popUpWin1.setVisible(false);
    popUpWin1.invalidate();
}

void GameScreenView::onWinContinueHandler()
{
    presenter->keepPlaying();
    popUpWin1.setVisible(false);
    popUpWin1.invalidate();
}

void GameScreenView::updateScore(int score, int highScore)
{
    Unicode::snprintf(myScoreBuffer, 16, "%d", score);

    currentScore.resizeToCurrentText();
    currentScore.invalidate();

    Unicode::snprintf(myBestScoreBuffer, 16, "%d", highScore);

    bestScore.resizeToCurrentText();
    bestScore.invalidate();
}
