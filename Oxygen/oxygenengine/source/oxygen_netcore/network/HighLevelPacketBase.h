/*
*	Part of the Oxygen Engine / Sonic 3 A.I.R. software distribution.
*	Copyright (C) 2017-2021 by Eukaryot
*
*	Published under the GNU GPLv3 open source software license, see license.txt
*	or https://www.gnu.org/licenses/gpl-3.0.en.html
*/

#pragma once

#include <rmxbase.h>


namespace highlevel
{
	// All high-level packets are built upon "lowlevel::HighLevelPacket" as their shared header
	//  -> Yes, this sounds a bit dumb, bit it's a low-level packet after all...

	struct PacketBase
	{
	public:
		bool serializePacket(VectorBinarySerializer& serializer, uint8 protocolVersion)
		{
			serializeContent(serializer, protocolVersion);
			return !serializer.hasError();
		}

	public:
		virtual uint32 getPacketType() const = 0;

	protected:
		virtual void serializeContent(VectorBinarySerializer& serializer, uint8 protocolVersion) = 0;
	};

}


#define HIGHLEVEL_PACKET_DEFINE_PACKET_TYPE(_name_) \
	static inline const std::string PACKET_NAME = _name_; \
	static const constexpr uint32 PACKET_TYPE = rmx::compileTimeFNV_32(_name_); \
	virtual uint32 getPacketType() const override  { return PACKET_TYPE; }
