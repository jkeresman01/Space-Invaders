#pragma once

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>

#include <filesystem>
#include <unordered_map>

namespace space
{

typedef std::unordered_map<std::string, sf::Texture> TexturesUnorderedMap;
typedef std::unordered_map<std::string, sf::SoundBuffer> SoundBuffersUnorderedMapT;

class ResourceManager
{
  public:
    ResourceManager()                        = default;
    ResourceManager(const ResourceManager &) = delete;

    ResourceManager operator=(const ResourceManager &) = delete;

    static ResourceManager &Instance();

    const sf::Texture &getTexture(const std::filesystem::path &filepath);
    const sf::SoundBuffer &getSoundBuffer(const std::filesystem::path &filepath);

  private:
    void loadTexture(const std::filesystem::path &filepath);
    void loadSoundBuffer(const std::filesystem::path &filepath);

  private:
    TexturesUnorderedMap m_textures;
    SoundBuffersUnorderedMapT m_soundBuffers;
};

} // namespace space
