#include "Player.h"

static const int THRESHOLD_TWO_STARS = 256;
static const int THRESHOLD_THREE_STARS = 512;
static const int THRESHOLD_FOUR_STARS = 1024;
static const int THRESHOLD_FIVE_STARS = 2048;

Player::Player()
        : m_id(0), m_points(0), m_stars(PlayerStars::OneStar)
{
}
Player::Player(int id)
        : m_id(id), m_points(0), m_stars(PlayerStars::OneStar)
{
}
void Player::CompleteMission(size_t points)
{
    m_points += points;
}
bool Player::LevelUp()
{
    switch (m_stars)
    {
        case PlayerStars::OneStar:
            if (m_points >= THRESHOLD_TWO_STARS)
            {
                m_points -= THRESHOLD_TWO_STARS;
                m_stars = PlayerStars::TwoStars;
                return true;
            }
            break;
        case PlayerStars::TwoStars:
            if (m_points >= THRESHOLD_THREE_STARS)
            {
                m_points -= THRESHOLD_THREE_STARS;
                m_stars = PlayerStars::ThreeStars;
                return true;
            }
            break;
        case PlayerStars::ThreeStars:
            if (m_points >= THRESHOLD_FOUR_STARS)
            {
                m_points -= THRESHOLD_FOUR_STARS;
                m_stars = PlayerStars::FourStars;
                return true;
            }
            break;
        case PlayerStars::FourStars:
            if (m_points >= THRESHOLD_FIVE_STARS)
            {
                m_points -= THRESHOLD_FIVE_STARS;
                m_stars = PlayerStars::FiveStars;
                return true;
            }
            break;
        case PlayerStars::FiveStars:
            return true;
    }
    return false;
}
