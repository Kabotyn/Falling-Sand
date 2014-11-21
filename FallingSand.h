#include <iostream>
#include <vector>

class FallingSand {

private:
    int N; // number of falling sand box (N x N)
    std::vector<std::string> falling_sand_box; // each line of sand box in each vector element
    bool no_more_steps; // if there is no more steps to fall sand this is true otherwise false
    const char sand_char = '.'; // char for representing sand
    const char stone_char = '#'; // like above but for stone;

    void readInputFile(std::string);
    void printSandBox(void);
    void nextStep(void);
    void clearConsole(void);

public:
    FallingSand(std::string);
    FallingSand(std::string, int);

};
