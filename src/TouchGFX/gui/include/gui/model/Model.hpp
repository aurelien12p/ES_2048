#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void newTile();
    void resetGame();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void refresh();
    bool getIsGameRunning() { return isGameRunning; }
    void keepPlaying();
    int getScore() { return score; }
	int getHighScore() { return highScore; }

protected:
    ModelListener* modelListener;

    int board[4][4];
    bool compressAndMerge(int* line);
    bool hasMoved;
    bool isGameRunning;
    int score;
	int highScore;
	bool hasWon;
	bool checkGameOver();
};

#endif // MODEL_HPP
