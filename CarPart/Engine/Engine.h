#include "../CarPart.h"

class Engine : CarPart {
    unsigned int horsePower = 0;
public:
    Engine() = default;
    Engine(int id, const char *name, const char *description, unsigned int horsePower);
    friend std::ostream& operator<<(std::ostream& os, const Engine& engine);
};
