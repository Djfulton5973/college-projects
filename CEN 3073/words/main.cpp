#include <iostream>
#include <string>

int main() {
    std::string words[] {"Egg", "Cheese", "Milk", "Egg", "Bacon", "Egg"};
    for(int i = 0; i < 6; i++) {
        int count = 0;
        for (int j = 0; j < 6; j++) {
            if (words[i] == words[j]) {
                if (j < i) {
                    break;
                }
                count++;
            }
        }
        std::cout << words[i] << ": " << count << std::endl;
    }


    return 0;
}
