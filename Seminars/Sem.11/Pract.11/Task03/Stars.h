#pragma once
enum class Stars {
    one,
    two,
    three,
    four,
    five
};

void upgradeStars(Stars &stars) {
    if (stars == Stars::five) {
        return;
    }
    stars = (Stars) ((int) stars + 1);
}
