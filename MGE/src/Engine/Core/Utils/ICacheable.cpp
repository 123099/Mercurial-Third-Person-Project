#include <Utils\ICacheable.hpp>

std::string ICacheable::GetName()
{
	return m_name;
}

GUID ICacheable::GetGUID()
{
	return m_gid;
}

void ICacheable::SetGUID(GUID gid)
{
	m_gid = gid;
}
