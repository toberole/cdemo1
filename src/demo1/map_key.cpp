#include "demo1/map_key.h"

map_key::map_key(int n) : i(n) {

}

bool map_key::operator<(const map_key &k) const {
    return i < k.i;
}
