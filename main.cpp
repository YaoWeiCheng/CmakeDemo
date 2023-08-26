#include <iostream>
#include "hello.hpp"
#include <glad/glad.h>
#include <glm/glm.hpp>

int main() {

    Hello hello;

    hello.say();
    GLfloat time = 0.1;
    glm::vec2 value(1,2);
    std::cout << value.x << std::endl;
    return 0;
}
