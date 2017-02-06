#pragma once
#include <string>
#include <rpc.h>

class ICacheable
{
public:
	std::string GetName();
	GUID GetGUID();
	void SetGUID(GUID gid);
protected:
	std::string m_name;
	GUID m_gid;
};