#pragma once

#include "Player.h"

class PremiumPlayer : public Player {
    char *username;

    void free();

    void copyFrom(const PremiumPlayer &other);

    void moveFrom(PremiumPlayer &&other);

    void copyUsername(const char *username);

public:
    PremiumPlayer(unsigned id, const char *username);

    PremiumPlayer(const PremiumPlayer &other);

    PremiumPlayer(PremiumPlayer &&other) noexcept;

    PremiumPlayer &operator=(const PremiumPlayer &other);

    PremiumPlayer &operator=(PremiumPlayer &&other) noexcept;

    ~PremiumPlayer();

    const char *getUsername() const;

    void setUsername(const char *newUsername);

    bool levelUp() override;
};