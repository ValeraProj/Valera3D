#ifndef _COBJECT_H_
#define _COBJECT_H_

#include "common.h"

namespace v3d
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class OBJECT_TYPE
	{
			OT_UNKNOWN,
			OT_NODE,
			OT_TEXTURE,
			OT_MATERIAL,
			OT_MESH,
			OT_SHADER,
			OT_SHADER_PROGRAM,

			OT_COUNT
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CObject
	{
	protected:
		s32					m_id;
		std::string			m_name;

		OBJECT_TYPE			m_type;

	public:
		CObject();
		~CObject();
		/*CObject(const CObject&) = delete;
		CObject(CObject&&) = delete;*/
		const s32			getID() const;
		const std::string	getName() const;
		const OBJECT_TYPE	getObjectType() const;

		void				setID( const s32 id );
		void				setName( const std::string& name );
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}

#endif