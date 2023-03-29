//
// Created by grade on 29.3.2023 г..
//

#include "Magic.h"

Magic::Magic(const char *name, const char *effect, Type type) {
    strcpy(this->name, name);
    strcpy(this->effect, effect);
    this->type = type;
}

void Magic::delMagic() {
    name[0] = '\0';
    effect[0] = '\0';
    type = Type::undefined;
}