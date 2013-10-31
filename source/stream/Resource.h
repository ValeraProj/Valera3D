#ifndef _V3D_RESOURCE_H_
#define _V3D_RESOURCE_H_

#include "common.h"
#include "Object.h"
#include "stream/IStream.h"

namespace v3d
{
namespace stream
{
	class CResource : public CObject
	{
	public:

		CResource();
		virtual ~CResource();

		virtual bool init( IStream* stream ) = 0;

	private:

	};
}
}

#endif