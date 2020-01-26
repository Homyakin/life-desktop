#include "SimpleField.h"

SimpleField::SimpleField(int rows, int cols) {
    field = std::vector<std::vector<SimpleCell>>(rows);
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows; ++i) {
        std::vector<SimpleCell> row(cols);
        for (int j = 0; j < cols; ++j) {
            row.emplace_back(SimpleCell());
        }
        field.push_back(row);
    }
}

void SimpleField::fillRandom() {
    for (auto &row: field) {
        for (auto &i: row) {
            i = SimpleCell::getRandomState();
        }
    }
}

void SimpleField::updateState() {
    auto nextField = std::vector<std::vector<SimpleCell>>(rows);
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int liveNeighbors = countLiveNeighbors(row, col);
            if (field[row][col].isAlive()) {
                nextField[row][col].setAlive(liveNeighbors == 2 || liveNeighbors == 3);
            } else {
                nextField[row][col].setAlive(liveNeighbors == 3);
            }
        }
    }
    field = nextField;
}

int SimpleField::countLiveNeighbors(int row, int col) {
    auto neighbors = getNeighbors(row, col);
    int liveNeighbors = 0;
    for (const auto &i: neighbors) {
        if (i.isAlive()) ++liveNeighbors;
    }
    return liveNeighbors;
}

std::vector<SimpleCell> SimpleField::getNeighbors(int row, int col) {
    int up = row == 0 ? rows - 1 : row - 1;
    int right = col != cols - 1 ? row + 1 : 0;
    int down = row != rows - 1 ? row + 1 : 0;
    int left = col != 0 ? col - 1 : cols - 1;
    std::vector<SimpleCell> neighbors(8);

    neighbors.push_back(field[up][col]);
    neighbors.push_back(field[up][right]);
    neighbors.push_back(field[row][right]);
    neighbors.push_back(field[down][right]);
    neighbors.push_back(field[down][col]);
    neighbors.push_back(field[down][left]);
    neighbors.push_back(field[row][left]);
    neighbors.push_back(field[up][left]);

    return neighbors;
}

