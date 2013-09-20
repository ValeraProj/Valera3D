#ifndef _V3D_SHADER_H_
#define _V3D_SHADER_H_

#include "Object.h"

namespace v3d
{
namespace renderer
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class EShaderType
	{
		eTypeUnknown = -1,
		eTypeVertex,
		eTypeFragment,
		eTypeGeometry,
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CShader : public CObject
	{
	public:
						CShader();
		virtual			~CShader();

		virtual void	create( const std::string& file )	= 0;
		virtual void	destroy()							= 0;

		u32				getShadeID()		const;
		EShaderType		getShaderType()		const;
		bool			getCompileStatus()	const;

	protected:

		void			clearData();

		u32				m_shaderID;

		EShaderType		m_shaderType;
		bool			m_compileStatus;
		void*			m_data;

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif