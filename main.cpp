
#include "Mode.h"

int main() {

    char response = 'y';
    while(response == 'y') {

        std::cout<<"Hello, please choose the mode\n"
                   "0 - demo\n"
                   "1 - benchmark\n";
        char key;
        std::cin>>key;
        if(key == '0')
            Mode::demo();
        if(key == '1')
            Mode::benchmark();
        std::cout<<"If you want to execute another mode press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}