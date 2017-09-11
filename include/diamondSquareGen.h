#ifndef DIAMONDSQUAREGEN_H
#define DIAMONDSQUAREGEN_H
#include <cstdlib>
#include <random>

class diamondSquareGen
{
    int squareSize = 0;
    int iterations = 0;
    float** squareArray = NULL;
    float minHeight;
    float maxHeight;
    float startHeight;
    std::default_random_engine generator;
    public:
        diamondSquareGen(int, float);
        void diamondStep();
        void squareStep();
        void reduceRange();
        void setStartHeight(float);
        void makePass();
        virtual ~diamondSquareGen();


    protected:

    private:
};

#endif // DIAMONDSQUAREGEN_H
