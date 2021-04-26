#include "demo1/Anim.h"
#include <iostream>

Anim::Anim() {
    std::cout << "Anim()" << std::endl;
}

void Anim::eat() {
    std::cout << "eat()" << std::endl;
}

Anim::~Anim() {
    std::cout << "~Anim()" << std::endl;
}
