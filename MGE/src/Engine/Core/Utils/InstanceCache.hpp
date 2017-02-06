#pragma once
#include <string>
#include <unordered_map>
#include <algorithm>
#include <Utils\ICacheable.hpp>

//Inject GUID hash into the std namespace to be able to use it with unordered_map
namespace std
{

	template<>
	struct hash<GUID>
	{
		size_t operator()(const GUID& gid) const
		{
			GUID gidCopy = gid;
			RPC_STATUS status;
			return UuidHash(&gidCopy, &status);
		}
	};
}

template <typename T>
class InstanceCache
{
private:
	using cacheMap = std::unordered_map<GUID, T*>;
	cacheMap m_cache;
public:
	InstanceCache() 
	{
		static_assert(std::is_base_of<ICacheable, T>(), "Instance type must be an ICacheable!");
	}

	void AddValue(T* value)
	{
		//Generate a GUID for the value
		GUID gid;
		CoCreateGuid(&gid);

		//Store value with GUID as key
		m_cache[gid] = std::move(value);
	}

	bool HasValue(const std::string& key)
	{
		return std::find_if(m_cache.begin(), m_cache.end(), [&](const auto& pair) {return m_cache[pair.first]->GetName() == key; }) != m_cache.end();
	}

	void RemoveValue(const std::string& key)
	{
		for (const auto& pair : m_cache)
		{
			if (m_cache[pair.first]->GetName() == key)
			{
				m_cache.erase(pair.first);
				return;
			}
		}

		//m_cache.erase(std::remove_if(m_cache.begin(), m_cache.end(), [&](const auto& pair) {return m_cache[pair.first]->GetName() == key; }));
	}

	T* GetValue(const std::string& key)
	{
		return std::find_if(m_cache.begin(), m_cache.end(), [&](const auto& pair) {return m_cache[pair.first]->GetName() == key; })->second;
	}

	const cacheMap& GetCache()
	{
		return m_cache;
	}
};
