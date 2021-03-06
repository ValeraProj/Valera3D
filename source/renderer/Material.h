#ifndef _V3D_MATERIAL_H_
#define _V3D_MATERIAL_H_

#include "Texture.h"
#include "ShaderProgram.h"

namespace v3d
{
namespace renderer
{
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	struct SMaterialData
	{
		core::Vector3D		ambient;
		core::Vector3D		diffuse;
		core::Vector3D		specular;
		core::Vector3D		emission;
		f32					shininess;
		f32					transparency;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	typedef std::shared_ptr<CTexture>		TexturePtr;
	typedef std::vector<TexturePtr>			TextureList;

	class CMaterial : public CObject 
	{
	public:
						CMaterial();
						~CMaterial();
		
		void			setAmbientColor ( const core::Vector3D& color );
		void			setDiffuseColor ( const core::Vector3D& color );
		void			setSpecularColor( const core::Vector3D& color );
		void			setEmissionColor( const core::Vector3D& color );
		void			setShininess    ( f32 value );
		void			setTransparency ( f32 value );

		core::Vector3D	getAmbientColor()  const;
		core::Vector3D	getDiffuseColor()  const;
		core::Vector3D	getSpecularColor() const;
		core::Vector3D	getEmissionColor() const;
		f32				getShininess()     const;
		f32				getTransparency()  const;

		void			setTexture( const u32 layer, const std::string& file     );
		void			setTexture( const u32 layer, const std::string* files[6] );
		void			setTexture( const u32 layer, TexturePtr texture          );

		TexturePtr		getTexture( const u32 layer ) const;
		u32				getTextureCount() const;

		void			destroyTexture( u32 layer );

		void			bind();
	
	protected:

		SMaterialData	m_materialData;
		
		TextureList		m_texture;
		
		/*CRenderTechnique*/

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
#endif