#include "headers/Animation.h"

#include "headers/ResourceManager.h"

namespace space
{

Animation::Animation(uint32_t positionX, uint32_t positionY, uint32_t width, uint32_t height,
                     uint32_t numberOfFrames, const std::filesystem::path &filepath)
    : m_numberOfFrames(numberOfFrames)
{
    m_texture = ResourceManager::Instance().getTexture(filepath);

    for (size_t i = 0; i < m_numberOfFrames; ++i)
    {
        m_frames.emplace_back(positionX + i * width, positionY, width, height);
    }
}

void Animation::update(float deltaTime)
{
    m_elapsedTime += deltaTime;

    while (m_elapsedTime >= HOLD_TIME)
    {
        m_elapsedTime -= HOLD_TIME;
        if (++m_currentFrame >= m_numberOfFrames)
        {
            m_currentFrame = 0;
        }
    }
}

void Animation::applyToSprite(sf::Sprite &sprite) const
{
    sprite.setTexture(m_texture);
    sprite.setTextureRect(m_frames[m_currentFrame]);
}

} // namespace space
