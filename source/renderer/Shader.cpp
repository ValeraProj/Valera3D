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
		, m_data( nullptr )
	{
		m_type = EObjectType::eTypeShader;
	}

	CShader::~CShader()
	{
		if (m_data != nullptr)
		{
			delete m_data;
			m_data = nullptr;
		}
	}

	u32 CShader::getShaderID() const
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
}
}