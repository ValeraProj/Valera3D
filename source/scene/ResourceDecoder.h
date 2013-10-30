#ifndef _V3D_RESOURCE_DECODER_H_
#define _V3D_RESOURCE_DECODER_H_

#include "common.h"
#include "stream/IStream.h"
#include "stream/Resource.h"

namespace v3d
{
namespace scene
{
	class CResourceDecoder
	{
		public:
	
			CResourceDecoder();
			virtual ~CResourceDecoder();

			virtual stream::CResource* decode( stream::IStream& stream ) = 0;
	};
}
}

#endif