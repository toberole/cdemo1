#pragma once

#include <cstdio>
#include <string>

namespace util {
    template<typename... Args>
    std::string sformat(const std::string &fmt, Args &&... args) {
        auto size = snprintf(nullptr, 0, fmt.c_str(), std::forward<Args>(args)...);
        std::string str(size, 0);
        snprintf(&str[0], size + 1, fmt.c_str(), std::forward<Args>(args)...);
        return str;
    }

}
