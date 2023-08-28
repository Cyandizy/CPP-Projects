#include <iostream>
#include <vector>

class ticTacToe {
  private:
    bool programRunning;
    char player;
    std::vector<char> boardData {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    
  public:
    void startProgram() {
      programRunning = true;
      showBoard();
    }

    void showBoard() {
      std::cout << boardData[0] << " " << boardData[1] << " " << boardData[2] << "\n" << boardData[3]<< " " << boardData[4]<< " " << boardData[5]<< "\n" << boardData[6]<< " " << boardData[7]<< " " << boardData[8] << "\n";
    }
};


int main() {
  ticTacToe game;
  game.startProgram();
  
  return 0;
}
