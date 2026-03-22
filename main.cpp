#include <iostream>
#include <string>
#include "slau_solution.h"
#include "experiments.h"

int main(int argc, char* argv[]) {
    std::string arg = (argc > 1) ? argv[1] : "exp1";
    if (arg == "exp1") timeComparison();
    else if (arg == "exp2") multipleAnswers();
    else if (arg == "exp3") illConditionedMatrices();
    return 0;
}
