#include <iostream>
#include <cstdio>

int main() {
    FILE* pipe = popen("gnome-calculator", "r"); // Execute "ls -l" command and open its output stream for reading
    if (!pipe) {
        std::cerr << "popen() failed!" << std::endl;
        return EXIT_FAILURE;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::cout << buffer;
    }

    pclose(pipe); // Close the pipe and wait for the child process to terminate
    return EXIT_SUCCESS;
}
