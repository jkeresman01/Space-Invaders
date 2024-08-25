#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <filesystem>

namespace space
{

typedef std::vector<sf::IntRect> FramesT;

class Animation
{
  public:
    Animation() = default;

    Animation(uint32_t positionX, uint32_t positionY, uint32_t width, uint32_t height,
              uint32_t numberOfFrames, const std::filesystem::path &filepath);

    void applyToSprite(sf::Sprite &sprite) const;

    void update(float deltaTime);

  private:
    static constexpr float HOLD_TIME = 0.1f;

    FramesT m_frames;
    sf::Texture m_texture;
    int32_t m_currentFrame   = 0;
    int32_t m_numberOfFrames = 0;
    float m_elapsedTime;
};

} // namespace space
