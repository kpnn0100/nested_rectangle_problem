#include "util/util.h"

#include "solver/solver.h"

int main() {
    std::ifstream inputFile("rec.inp");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    int n; // Number of rectangles
    inputFile >> n;

    std::vector<Rectangle> rectangleList(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> rectangleList[i].x1 >> rectangleList[i].y1 >> rectangleList[i].x2 >> rectangleList[i].y2;
    }

    inputFile.close();

    int mostNestedCount = getMostNestedCount(rectangleList);
    std::cout<<mostNestedCount<<std::endl;
    std::ofstream outputFile("nested.out");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    outputFile << mostNestedCount << std::endl;
    outputFile.close();

    return 0;
}
