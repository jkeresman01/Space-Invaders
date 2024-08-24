#include "headers/ResourceManager.h"

#include "headers/Logger.h"

namespace space
{

const sf::SoundBuffer &ResourceManager::getSoundBugffer(const std::filesystem::path &filepath)
{
    SoundBuffersUnorderedMap::const_iterator it;
    if (it = m_soundBuffers.find(filepath.string()); it == m_soundBuffers.end())
    {
        loadSoundBuffer(filepath);
        it = m_soundBuffers.find(filepath);
    }
    return it->second;
}

void ResourceManager::loadSoundBuffer(const std::filesystem::path &filepath)
{
    sf::SoundBuffer soundBuffer;

    bool isSoundBufferLoadedSuccssfully = soundBuffer.loadFromFile(filepath);

    if (!isSoundBufferLoadedSuccssfully)
    {
        LOG_ERROR("Failed to load sound buffer from " << filepath.string() << "!");
        return;
    }

    m_soundBuffers.emplace(filepath.string(), soundBuffer);
}

const sf::Texture &ResourceManager::getTexture(const std::filesystem::path &filepath)
{
    TexturesUnorderedMap::const_iterator it;
    if (it = m_textures.find(filepath.string()); it == m_textures.end())
    {
        loadTexture(filepath);
        it = m_textures.find(filepath);
    }
    return it->second;
}

void ResourceManager::loadTexture(const std::filesystem::path &filepath)
{
    sf::Texture texture;

    bool isTextureLoadedSuccessfully = texture.loadFromFile(filepath);

    if (!isTextureLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load texture from " << filepath.string() << "!");
        return;
    }

    m_textures.emplace(filepath.string(), texture);
}

ResourceManager &ResourceManager::Instance()
{
    static ResourceManager instance;
    return instance;
}

} // namespace space
