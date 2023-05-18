#pragma once

#include "User.h"

class PremiumUser : User {
private:
    char *username;

    unsigned getPointsNeeded() const override;

public:
    PremiumUser(unsigned, const char *, const char *);

    void setUsername(const char *);

    const char *getUsername() const;

    void sendMessage(const char *) const;

private:
    void free();

    void copyFrom(const PremiumUser &);

    void moveFrom(PremiumUser &&);

public:
    PremiumUser(const PremiumUser &);

    PremiumUser(PremiumUser &&);

    PremiumUser &operator=(const PremiumUser &);

    PremiumUser &operator=(PremiumUser &&);

};
