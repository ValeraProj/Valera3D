#include "Object.h"

namespace v3d
{
	CObject::CObject()
		: m_name("")
		, m_id(-1)
		, m_type(OBJECT_TYPE::OT_UNKNOWN)
		{
		}


	CObject::~CObject()
	{
	}

	const std::string CObject::getName() const
	{
		return m_name;
	}

	void CObject::setName( const std::string& name )
	{
		m_name = name;
	}

	const OBJECT_TYPE CObject::getObjectType() const
	{
		return m_type;
	}

	const s32 CObject::getID() const
	{
		return m_id;
	}

	void CObject::setID( const s32 id )
	{
		m_id = id;
	}
}