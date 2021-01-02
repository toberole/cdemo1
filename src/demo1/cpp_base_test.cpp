#include "demo1/cpp_base_test.h"
#include <variant>
#include <string>

void variant_demo() {
    std::variant<int,std::string> v1{"hello"};
}
