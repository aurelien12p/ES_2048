#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "cmsis_os.h"
#include <cstdlib>

extern "C" {
    extern osMessageQueueId_t inputQueueHandle;
    extern uint32_t uwTick;
}

Model::Model() : modelListener(0), score(0), highScore(0), hasWon(false)
{
    std::srand(uwTick);
    resetGame();
}

void Model::tick()
{
    if (inputQueueHandle != NULL)
    {
        uint8_t receivedMsg = 0;
        if (osMessageQueueGet(inputQueueHandle, &receivedMsg, 0, 0) == osOK)
        {
            if(isGameRunning)
            {
                if(receivedMsg == 1) moveUp();
                else if(receivedMsg == 2) moveDown();
                else if(receivedMsg == 3) moveLeft();
                else if(receivedMsg == 4) moveRight();
                else if(receivedMsg == 5) // CHEAT CODE VICTOIRE (PA0)
                {
                    if(isGameRunning)
                    {
                        isGameRunning = false;
                        if(modelListener) modelListener->gameWon();
                    }
                }

                if (hasMoved)
                {
                    newTile();
                    modelListener->updateBoardView(board);
                    modelListener->updateScore(score, highScore);

                    if(checkGameOver())
                    {
                        isGameRunning = false;
                        if(modelListener) modelListener->gameover();
                    }

                    hasMoved = false;
                }
            }
        }
    }
}
void Model::resetGame()
{
	score = 0;
	hasWon = false;
	isGameRunning = true;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            board[i][j] = 0;

    newTile();
    newTile();

    if(modelListener)
	{
		modelListener->updateBoardView(board);
		modelListener->updateScore(score, highScore);
	}
}

void Model::newTile()
{
    int emptyCells[16][2];
    int count = 0;

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(board[i][j] == 0) {
                emptyCells[count][0] = i;
                emptyCells[count][1] = j;
                count++;
            }
        }
    }

    if(count > 0) {
        int r = std::rand() % count;
        int row = emptyCells[r][0];
        int col = emptyCells[r][1];

        board[row][col] = (std::rand() % 10 == 0) ? 4 : 2;
    }
}

bool Model::compressAndMerge(int* line) {
    bool changed = false;
    int temp[4] = {0};
    int cursor = 0;

    for (int i = 0; i < 4; i++) {
        if (line[i] != 0) {
            temp[cursor++] = line[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (temp[i] != 0 && temp[i] == temp[i+1]) {
            temp[i] *= 2;
            score += temp[i];
			if (score > highScore)
			{
				highScore = score;
			}
			if (temp[i] == 2048 && !hasWon)
			{
				hasWon = true;
				isGameRunning = false;
				if(modelListener) modelListener->gameWon();
			}
            temp[i+1] = 0;
            i++;
            changed = true;
        }
    }

    int finalLine[4] = {0};
    cursor = 0;
    for (int i = 0; i < 4; i++) {
        if (temp[i] != 0) {
            finalLine[cursor++] = temp[i];
        }
    }

    for (int i = 0; i < 4; i++) {
        if (line[i] != finalLine[i]) {
            changed = true;
            line[i] = finalLine[i];
        }
    }
    return changed;
}

void Model::moveLeft() {
    hasMoved = false;
    for (int i = 0; i < 4; i++) {
        if (compressAndMerge(board[i])) hasMoved = true;
    }
}

void Model::moveRight() {
    hasMoved = false;
    for (int i = 0; i < 4; i++) {
        int temp[4];
        for(int j=0; j<4; j++) temp[j] = board[i][3-j];

        if (compressAndMerge(temp)) {
            hasMoved = true;
            for(int j=0; j<4; j++) board[i][3-j] = temp[j];
        }
    }
}

void Model::moveUp() {
    hasMoved = false;
    for (int j = 0; j < 4; j++) {
        int temp[4];
        for(int i=0; i<4; i++) temp[i] = board[i][j];

        if (compressAndMerge(temp)) {
            hasMoved = true;
            for(int i=0; i<4; i++) board[i][j] = temp[i];
        }
    }
}

void Model::moveDown() {
    hasMoved = false;
    for (int j = 0; j < 4; j++) {
        int temp[4];
        for(int i=0; i<4; i++) temp[i] = board[3-i][j];

        if (compressAndMerge(temp)) {
            hasMoved = true;
            for(int i=0; i<4; i++) board[3-i][j] = temp[i];
        }
    }
}

void Model::refresh()
{
    if (modelListener)
    {
        modelListener->updateBoardView(board);
    }
}

bool Model::checkGameOver()
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            if(board[i][j] == 0) return false;

    for(int i=0; i<4; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] == board[i][j+1]) return false;

    for(int j=0; j<4; j++)
        for(int i=0; i<3; i++)
            if(board[i][j] == board[i+1][j]) return false;

    return true;
}

void Model::keepPlaying()
{
    isGameRunning = true;
}
