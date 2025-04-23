#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Fork failed\n";
        return 1;
    } else if (pid == 0) {
        // Child process
        std::cout << "Child Process: Working..." << std::endl;
        sleep(2);  // Simulate task
        std::cout << "Child Process: Task finished." << std::endl;
    } else {
        // Parent process
        std::cout << "Parent Process: Waiting for child to finish..." << std::endl;
        wait(nullptr); // Wait for child
        std::cout << "Parent Process: Child finished, exiting now." << std::endl;
    }

    return 0;
}
