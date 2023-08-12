#include <iostream>
#include <string>

class ToDoList {
    private:
        bool programRunning = true;

    public:
        void interface() {
            std::string userCommand;
            while (programRunning) {
                std::cin >> userCommand;
                if (userCommand.find("quit") != std::string::npos) {
                    std::clog << "The program has stopped.";
                    quitProgram();
                    break;
                }
                else {
                    std::clog << userCommand;
                }
            }
        }
        void quitProgram() {
            programRunning = false;
        }
};

int main() {
    ToDoList program;
    program.interface();

    return 0;
}