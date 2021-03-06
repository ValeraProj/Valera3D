#include "Material.h"

namespace v3d
{
namespace renderer
{
	CMaterial::CMaterial()
		: CObject()
	{
		m_type = EObjectType::eTypeMaterial;

		m_materialData.ambient		= core::Vector3D(0.2f, 0.2f, 0.2f);
		m_materialData.diffuse		= core::Vector3D(0.2f, 0.2f, 0.2f);
		m_materialData.specular		= core::Vector3D(1.0f, 1.0f, 1.0f);
		m_materialData.emission		= core::Vector3D(0.0f, 0.0f, 0.0f);
		m_materialData.shininess	= 128U;
		m_materialData.transparency	= 1.0f;

	}

	CMaterial::~CMaterial()
	{
	}

	void CMaterial::setAmbientColor( const core::Vector3D& color )
	{
		m_materialData.ambient = color;
	}
		
	void CMaterial::setDiffuseColor( const core::Vector3D& color )
	{
		m_materialData.diffuse = color;
	}

	void CMaterial::setSpecularColor( const core::Vector3D& color )
	{
		m_materialData.specular = color;
	}

	void CMaterial::setEmissionColor( const core::Vector3D& color )
	{
		m_materialData.emission = color;
	}

	void CMaterial::setShininess( const f32 value )
	{
		m_materialData.shininess = value;
	}
		
	core::Vector3D CMaterial::getAmbientColor() const
	{
		return m_materialData.ambient;
	}

	core::Vector3D CMaterial::getDiffuseColor() const
	{
		return m_materialData.diffuse;
	}

	core::Vector3D CMaterial::getSpecularColor() const
	{
		return m_materialData.specular;
	}

	core::Vector3D	CMaterial::getEmissionColor() const
	{
		return m_materialData.emission;
	}

	f32 CMaterial::getShininess() const
	{
		return m_materialData.shininess;
	}
		
	void CMaterial::bind()
	{
		//TODO: do somethig)
	}

	TexturePtr CMaterial::getTexture( const u32 layer ) const
	{
		if ( layer >= ETextureLayer::eTextureLayerMax)
		{
			//ASSERT  "invalid texture layer" ;
			return nullptr;
		}

		return m_texture[layer];
	}
		
	u32 CMaterial::getTextureCount() const
	{
		return m_texture.size();
	}
		
	void CMaterial::setTexture( const u32 layer, const std::string& file )
	{
		if ( layer >= ETextureLayer::eTextureLayerMax )
		{
			//ASSERT "Texture Layer range out";
			return;
		}

		TexturePtr oldTexture = m_texture[layer];
		//TODO: del old texture if will not need more
		
		//TexturePtr newTexture = std::make_shared<CTexture>();
		//TODO: need lower name file
		//newTexture->create(file);

		//m_texture[layer] = newTexture;
	}

	void CMaterial::setTexture( const u32 layer, const std::string* files[6] )
	{
		if ( layer >= ETextureLayer::eTextureLayerMax )
		{
			//ASSERT "Texture Layer range out";
			return;
		}

		TexturePtr oldTexture = m_texture[layer];
		//TODO: del old texture if will not need more
		
		//TexturePtr newTexture = std::make_shared<CTexture>();
		//TODO: need lower name file
		//newTexture->create(files);

		//m_texture[layer] = newTexture;
	}

	void CMaterial::destroyTexture( u32 layer )
	{
		if ( layer >= ETextureLayer::eTextureLayerMax )
		{
			//ASSERT "Texture Layer range out";
			return;
		}

		TexturePtr oldTexture = m_texture[layer];
		//TODO: del old texture if will not need more

		m_texture[layer] = nullptr;

	}

	void CMaterial::setTexture( const u32 layer, TexturePtr texture )
	{
		if ( layer >= ETextureLayer::eTextureLayerMax )
		{
			//ASSERT "Texture Layer range out";
			return;
		}

		TexturePtr oldTexture = m_texture[layer];
		//TODO: del old texture if will not need more
		
		m_texture[layer] = texture;

	}

	void CMaterial::setTransparency( const f32 value )
	{
		m_materialData.transparency = (value > 1.0f) ? 1.0f : value;
	}

	float CMaterial::getTransparency() const
	{
		return m_materialData.transparency;
	}
}
}