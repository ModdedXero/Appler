#pragma once

#include <xhash>

namespace Appler
{
	class UUID
	{
	public:
		UUID();
		UUID(uint64_t uuid);
		UUID(const UUID&) = default;

		operator uint64_t() const { return m_UUID; }

		bool operator ==(const UUID& other) const
		{
			return m_UUID == other.m_UUID;
		}
	private:
		uint64_t m_UUID;
	};
}

namespace std
{
	template<>
	struct hash<Appler::UUID>
	{
		std::size_t operator ()(const Appler::UUID& uuid) const
		{
			return hash<uint64_t>()((uint64_t)uuid);
		}
	};
}