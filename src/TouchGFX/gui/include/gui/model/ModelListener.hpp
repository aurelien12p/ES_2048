#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}
    virtual void toggleAllTiles() {}

    virtual void updateBoardView(int board[4][4]) {}
    virtual void gameover() {}
    virtual void gameWon() {}
    virtual void updateScore(int score, int highScore) {}

    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
