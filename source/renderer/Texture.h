#ifndef _V3D_TEXTURE_H_
#define _V3D_TEXTURE_H_

#include "Object.h"
#include "stream/Resource.h"

namespace v3d
{
namespace renderer
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class ETextureTarget
	{
		eTargetUnknown = -1,
		eTargetTexture1D,
		eTargetTexture2D,
		eTargetTexture3D,
		eTargetTextureCubeMap,
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class ETextureFilter
	{
		eFilterNearest,
		eFilterLinear,
		
		eFilterNearestMipmapNearest,
		eFilterLinearMipmapNearest,
		eFilterNearestMipmapLinear,
		eFilterLinearMipmapLinear,
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class EImageType
	{
		eTypeByte,
		eTypeUnsignedByte,
		eTypeShort,
		eTypeUnsignedShort,
		eTypeInt,
		eTypeUnsignedInt,
		eTypeFloat,
		eTypeDouble,
		eTypeHalf,
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	enum class EImageFormat
	{
		eFormatColorIndex,
		eFormatAlpha,
		eFormatRGB,
		eFormatRGBA,
		eFormatBGR,
		eFormatBGRA,
		eFormatLumiance,
		eFormatLuminanceAlpha,
		eFormatDepthComponent,
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	enum ETextureLayer
	{
		eTextureLayer_0 = 0,
		eTextureLayer_1,
		eTextureLayer_2,
		eTextureLayer_3,

		eTextureLayerMax,
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	struct STextureData
	{
		u16				width;
		u16				height;
		u16				depth;
		EImageFormat	format;
		EImageType		type;
		void*			data;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	class CTexture : public stream::CResource
	{
	public:
						CTexture();
		virtual			~CTexture();

		virtual void	bind( s32 textureLayer )				= 0;
		virtual void	create( const std::string& file )		= 0;
		virtual void	create( const std::string* files[6] )	= 0;
		virtual void	destroy()								= 0;

		bool			init( stream::IStream* stream ) override { return false;};

		u32				getTextureID()	const;
		ETextureTarget	getTarget()		const;
		ETextureFilter	getMinFiler()	const;
		ETextureFilter	getMagFiler()	const;

		void			setFilterType( ETextureFilter minFilter, ETextureFilter magFilter );

	protected:

		u32				m_textureID;

		ETextureTarget	m_target;
		STextureData	m_data;

		ETextureFilter	m_minFilter;
		ETextureFilter	m_magFilter;

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////
}
}

#endif