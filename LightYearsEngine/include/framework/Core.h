#pragma once

#include <map>
#include <memory>
#include <stdio.h>
#include <unordered_map>

namespace ly
{
    template<typename T>
    using TUniquePtr = std::unique_ptr<T>;

    template<typename T>
    using TSharedPtr = std::shared_ptr<T>;

    template<typename T>
    using TWeakPtr = std::weak_ptr<T>;

    template<typename T>
    using TArray = std::vector<T>;

    template<typename keyType, typename valueType, typename Pr = std::less<keyType>>
    using TMap = std::map<keyType, valueType, Pr>;

    template<typename keyType, typename valueType, typename Hasher = std::hash<keyType>>
    using TUMap = std::unordered_map<keyType, valueType, Hasher>;
    
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}
