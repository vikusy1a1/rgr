#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

// Структура для хранения координат
struct Coordinate {
    int x;
    int y;
};

// Проверка, находится ли король под атакой ферзя
bool isKingAttackedByQueen(Coordinate king, Coordinate queen) {
    return king.x == queen.x || king.y == queen.y ||
        abs(king.x - queen.x) == abs(king.y - queen.y);
}

// Проверка, находится ли король под атакой коня
bool isKingAttackedByKnight(Coordinate king, Coordinate horse) {
    return (abs(king.x - horse.x) == 1 && abs(king.y - horse.y) == 2) ||
        (abs(king.x - horse.x) == 2 && abs(king.y - horse.y) == 1);
}

// Автоматическое заполнение поля фигурами
void fillBoard(vector<vector<char>>& board, int numQueens, int numHorse, Coordinate king) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 7);

    // Размещение ферзей
    for (int i = 0; i < numQueens; i++) {
        int x = dist(gen);
        int y = dist(gen);
        while (board[x][y] != ' ' || (x == king.x && y == king.y)) {
            x = dist(gen);
            y = dist(gen);
        }
        board[x][y] = 'Q';
    }

    // Размещение коней
    for (int i = 0; i < numHorse; i++) {
        int x = dist(gen);
        int y = dist(gen);
        while (board[x][y] != ' ' || (x == king.x && y == king.y)) {
            x = dist(gen);
            y = dist(gen);
        }
        board[x][y] = 'H';
    }
    //размещение короля
    board[king.x][king.y] = 'K';
}

// Вывод шахматной доски
void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Создание шахматной доски
    vector<vector<char>> board(8, vector<char>(8, ' '));
    Coordinate king;

    cout << "Enter the coordinates king (x, y): ";
    cin >> king.x >> king.y;

   

    fillBoard(board, 6, 2, king);

    // Определение координат ферзей и коней, атакующих короля
    vector<Coordinate> attackingQueens;
    vector<Coordinate> attackingKnights;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'Q' && isKingAttackedByQueen(king, { i, j })) {
                attackingQueens.push_back({ i, j });
            }
            else if (board[i][j] == 'H' && isKingAttackedByKnight(king, { i, j })) {
                attackingKnights.push_back({ i, j });
            }
        }
    }

    cout << "desk:" << endl;
    printBoard(board);

    cout << "The queen: ";
    for (auto queen : attackingQueens) {
        cout << "[" << queen.x << ", " << queen.y << "] ";
    }
    cout << endl;

    cout << "Horses: ";
    for (auto knight : attackingKnights) {
        cout << "[" << knight.x << ", " << knight.y << "] ";
    }
    cout << endl;

    return 0;
}