#include "headers/ResourceManager.h"

#include "headers/Logger.h"

namespace space
{

const sf::Texture &ResourceManager::getTexture(const std::filesystem::path &filepath)
{
    TexturesUnorderedMap::const_iterator it = m_textures.find(filepath.string());

    if (it == m_textures.end())
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
