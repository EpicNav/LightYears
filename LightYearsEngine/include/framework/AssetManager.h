#pragma once
#include <string>

#include "Core.h"
#include "SFML/Graphics/Texture.hpp"

namespace ly
{
    class AssetManager
    {
    public:
        static AssetManager& Get();
        TSharedPtr<sf::Texture> LoadTexture(const std::string& path);
        void CleanCycle();
        void SetAssetRootDirectory(const std::string& directory) { m_root_directory_ = directory; }
    protected:
        AssetManager();

    private:
        static TUniquePtr<AssetManager> m_instance_;
        TMap<std::string, TSharedPtr<sf::Texture>> m_loaded_textures_;

        std::string m_root_directory_;
    };
}
