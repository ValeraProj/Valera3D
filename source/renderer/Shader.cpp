#include "Shader.h"

namespace v3d
{
namespace renderer
{
	CShader::CShader()
		: CObject()
		, m_shaderID( -1 )
		, m_shaderType( EShaderType::eTypeUnknown )
		, m_compileStatus( false )
		, m_data( NULL )
	{
		m_type = EObjectType::eTypeShader;
	}

	CShader::~CShader()
	{
		clearData();
	}

	u32 CShader::getShadeID() const
	{
		return m_shaderID;
	}

	EShaderType CShader::getShaderType() const
	{
		return m_shaderType;
	}

	bool CShader::getCompileStatus() const
	{
		return m_compileStatus;
	}

	void CShader::clearData()
	{
		if (m_data != NULL)
		{
			delete m_data;
			m_data = NULL;
		}
	}
}
}