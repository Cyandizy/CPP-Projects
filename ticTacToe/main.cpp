#include <iostream>
#include <vector>

std::string upper(std::string str) {
    std::string upperCased;
    for (char ch : str) {
        upperCased += static_cast<char>(toupper(ch));
    }
    upperCased;
    return upperCased;
}

bool keywordFound(std::string& str, std::string keyword) {
  return upper(str).find(upper(keyword)) != std::string::npos;
}

class TicTacToe {    
  private:
    bool quit;
    char player;
    std::vector<char> boardData;

  public:
    TicTacToe() {
      quit = false;
      player = 'X';
      boardData = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    }

    void startProgram() {
      gamePlayGuide();
      askIfStart();
    }

    void showBoard() {
      std::cout << boardData[0] << " " << boardData[1] << " " << boardData[2] << "\n" 
                << boardData[3] << " " << boardData[4] << " " << boardData[5] << "\n" 
                << boardData[6] << " " << boardData[7] << " " << boardData[8] << "\n";
    }

    void gamePlayGuide() {
      std::cout << "The positions are as follow\n";
      std::cout << 1 << " " << 2 << " " << 3 << "\n" 
                << 4 << " " << 5 << " " << 6 << "\n" 
                << 7 << " " << 8 << " " << 9 << "\n";
    }

    void askIfStart() {
      std::string userInput;
      std::cout << "Start? [Y/N]>";
      std::getline(std::cin, userInput);
      if (keywordFound(userInput, "y") || keywordFound(userInput, "yes")) {
        std::cout << "Starting...\n";
        showBoard();
        getPlayerMove();
      }
      else {
        std::cout << "Quitting the program.\n";
        quit = true;
      }
    }

    void getPlayerMove() {
      std::string inputPosition;
      std::cout << "--------------------------------\n";
      std::cout << "Current Player: " << player << "\n";
      std::cout << "Input Position>";
      std::getline(std::cin, inputPosition);
      bool inputValid = isValidInput(inputPosition);
      if (inputValid && !quit) {
        checkIfWon();
      }
      else if (!inputValid && !quit) {
        getPlayerMove();
      }
    }

    bool isValidInput(std::string& input) {
      if (keywordFound(input, "quit")) {
        std::cout << "Do you really want to quit? [Y/N]>";
        std::string userInput;
        std::getline(std::cin, userInput);
        if (keywordFound(userInput, "y")) {
          std::cout << "Program quit.\n";
          quit = true;
          return true;
        }
      }

      try {
        int actualPosition = 0;
        actualPosition = std::stoi(input) - 1;
        if (boardData[actualPosition] == '-') {
          boardData[actualPosition] = player;
          return true;
      }
        else {
          std::cout << "The position is occupied.\n";
          return false;
        }
      }
        catch (const std::invalid_argument) {
          std::cout << "Please enter correct inputs\n";
          return false;
      }   
    }

    void checkIfWon() {
      if (gameOver()) {
        showBoard();
        std::cout << "Player " << player << " won!\n";
      }
      else {
        switchPlayer();
        showBoard();
        getPlayerMove();
      }
    }

    bool gameOver() {
      return (boardData[0] == boardData[1] && boardData[1] == boardData[2] && boardData[0] != '-')
          || (boardData[3] == boardData[4] && boardData[4] == boardData[5] && boardData[3] != '-') 
          || (boardData[6] == boardData[7] && boardData[7] == boardData[8] && boardData[6] != '-') 
          || (boardData[0] == boardData[4] && boardData[4] == boardData[8] && boardData[0] != '-') 
          || (boardData[2] == boardData[4] && boardData[4] == boardData[6] && boardData[2] != '-')
          || (boardData[0] == boardData[3] && boardData[3] == boardData[6] && boardData[0] != '-')
          || (boardData[1] == boardData[4] && boardData[4] == boardData[7] && boardData[1] != '-')
          || (boardData[2] == boardData[5] && boardData[5] == boardData[8] && boardData[2] != '-');
    }

    void switchPlayer() {
      if (player == 'O') {
        player = 'X';
      }
      else if (player == 'X') {
        player = 'O';
      }
    }

    bool quitProgram() {
      return quit;
    }
};

int main() {
  std::cout << "TicTacToe V1.0 by lzys0\n";
  while (true) {
    TicTacToe game;
    game.startProgram();
    if (game.quitProgram()) {
      std::cout << "The program ended.";
      break;
    }
    std::string userInput;
    std::cout << "Do you want to restart? [Y/N]>";
    std::getline(std::cin, userInput);
    if (!keywordFound(userInput, "y")) {
      std::cout << "Play again sometimes!";
      break;
    }
  }

  return 0;
}
