#include "PremiumPlayer.h"
#include <cstring>

static const int THRESHOLD_STARS = 256;

PremiumPlayer::PremiumPlayer(const char *name)
{
    if (!name)
        return;

    size_t size = strlen(name);
    m_name = new char[size + 1];
    strcpy_s(m_name, size + 1, name);
}

bool PremiumPlayer::LevelUp()
{
    if (m_points >= THRESHOLD_STARS)
    {
        m_points -= THRESHOLD_STARS;
        switch (m_stars)
        {
            case PlayerStars::OneStar:
                m_stars = PlayerStars::TwoStars;
                break;
            case PlayerStars::TwoStars:
                m_stars = PlayerStars::ThreeStars;
                break;
            case PlayerStars::ThreeStars:
                m_stars = PlayerStars::FourStars;
                break;
            case PlayerStars::FourStars:
                m_stars = PlayerStars::FiveStars;
                break;
            case PlayerStars::FiveStars:
                break;
        }
        return true;
    }

    return false;
}

