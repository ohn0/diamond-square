#include "diamondSquareGen.h"

diamondSquareGen::diamondSquareGen(int squareSize, float randVal)
{
    this.squareSize = squareSize;
    this.squareArray = new float*[squareSize];
    this.maxHeight = randVal;
    this.minHeight = -1.f * randVal;
    this.maxHeight = randVal;

    for(int i = 0; i < squareSize; i++){
        squareArray[i] = new float[squareSize];
    }
}

void diamondSquareGen::diamondStep()
{
    //Find each square's midpoint and set it to a random value, setting it
    //to the diamond's midpoint.
}

void diamondSquareGen::squareStep()
{
    //Find the corner's of each diamond's midpoint to generate squares.

}

void diamondSquareGen::reduceRange()
{
    maxHeight /= 2;
    minHeight /= 2;
    std::uniform_real_distribution<float> distribution(minHeight, maxHeight);
    return distribution(generator);
}

void diamondSquareGen::makePass()
{
    this.diamondStep();
    this.squareStep();
    this.reduceRange();
    iterations++;
}

void diamondSquareGen::setStartHeight(float startHeight)
{
    if(iterations == 0 && squareArray != NULL){
        squareArray[0][0] = startHeight;
        squareArray[0][squareSize] = startHeight;
        squareArray[squareSize][0] = startHeight;
        squareArray[squareSize][squareSize] = startHeight;
    }
    else{
        std::cout << "squareArray is NULL" << std::endl;
    }
    this.startHeight = startHeight;
}

diamondSquareGen::~diamondSquareGen()
{
    for(int i = 0; i < squareSize; i++){
        delete squareArray[i];
    }
    delete squareArray;
    //dtor
}
