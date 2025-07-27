#include "framework/AssetManager.h"

namespace ly
{
    TUniquePtr<AssetManager> AssetManager::m_instance_(nullptr);
    AssetManager& AssetManager::Get()
    {
        if (!m_instance_)
        {
            m_instance_ = TUniquePtr<AssetManager>(new AssetManager());
        }

        return *m_instance_;
    }

    TSharedPtr<sf::Texture> AssetManager::LoadTexture(const std::string& path)
    {
        auto found = m_loaded_textures_.find(path);
        if (found != m_loaded_textures_.end())
        {
            return found->second;
        }

        TSharedPtr<sf::Texture> newTexture{new sf::Texture};
        if (newTexture->loadFromFile(m_root_directory_ + path))
        {
            m_loaded_textures_.insert({path, newTexture});
            return newTexture;
        }

        return TSharedPtr<sf::Texture> {nullptr};
    }

    void AssetManager::CleanCycle()
    {
        for (auto itr = m_loaded_textures_.begin(); itr != m_loaded_textures_.end();)
        {
            if (!itr->second->isRepeated())
            {
                LOG("Cleaning texture %s", itr->first.c_str());
                itr = m_loaded_textures_.erase(itr);
            } else
            {
                ++itr;
            }
        }
    }

    AssetManager::AssetManager()
        : m_root_directory_()
    {
    }
}
