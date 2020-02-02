#include "SimpleField.h"

SimpleField::SimpleField(int rows, int cols) {
    field = std::vector<std::vector<SimpleCell>>();
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows; ++i) {
        field.emplace_back(std::vector<SimpleCell>(cols));
    }
}

void SimpleField::fill_random() {
    for (auto &row: field) {
        for (auto &i: row) {
            i = SimpleCell::get_random_state();
        }
    }
}

void SimpleField::change_cell(int row, int col) {
    if(row < rows && col < cols)
        field[row][col].set_alive(!field[row][col].is_alive());
}

void SimpleField::update_state() {
    auto nextField = std::vector<std::vector<SimpleCell>>();
    for (int i = 0; i < rows; ++i) {
        nextField.emplace_back(std::vector<SimpleCell>(cols));
    }
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int liveNeighbors = count_live_neighbors(row, col);
            if (field[row][col].is_alive()) {
                nextField[row][col].set_alive(liveNeighbors == 2 || liveNeighbors == 3);
            } else {
                nextField[row][col].set_alive(liveNeighbors == 3);
            }
        }
    }
    field = nextField;
}

int SimpleField::count_live_neighbors(int row, int col) {
    auto neighbors = get_neighbors(row, col);
    int liveNeighbors = 0;
    for (const auto &i: neighbors) {
        if (i.is_alive()) ++liveNeighbors;
    }
    return liveNeighbors;
}

std::vector<SimpleCell> SimpleField::get_neighbors(int row, int col) {
    int up = row != 0 ? row - 1 : rows - 1;
    int right = col != cols - 1 ? col + 1 : 0;
    int down = row != rows - 1 ? row + 1 : 0;
    int left = col != 0 ? col - 1 : cols - 1;
    std::vector<SimpleCell> neighbors{};

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

std::vector<sf::RectangleShape> SimpleField::render(int window_size_x, int window_size_y) const {
    int cell_size_x = window_size_x / cols;
    int cell_size_y = window_size_y / rows;
    std::vector<sf::RectangleShape> cells{};
    for (int row = 0; row < field.size(); ++row) {
        for (int col = 0; col < field[row].size(); ++col) {
            if (field[row][col].is_alive()) {
                sf::RectangleShape cell = field[row][col].render(cell_size_x, cell_size_y);
                cell.setPosition(col * cell_size_x, row * cell_size_y);
                cells.push_back(cell);
            }
        }
    }
    return cells;
}
