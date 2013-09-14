#ifndef _V3D_NODE_H_
#define _V3D_NODE_H_

#include "Object.h"

namespace v3d
{
namespace scene
{
	class CNode : public CObject
	{
	public:
							CNode();
		virtual				~CNode();
	
		void				setPosition			( const core::Vector3D& position );
		void				setRotation			( const core::Vector3D& rotation );
		void				setScale			( const core::Vector3D& scale );
		void				setTransform		( const core::Matrix4D& transform );
	
		void				move				( const core::Vector3D& deltaPosition );
		void				rotate				( const core::Vector3D& deltaRotation );
	
		void				setParrentNode		( CNode* parrentNode );
		void				attachChildNode		( CNode* childNode );
		void				dettachChildNode	( CNode* childNode );
	
		core::Vector3D		getPosition			()							const;
		core::Vector3D		getRotation			()							const;
		core::Vector3D		getScale			()							const;
		core::Matrix4D		getTransform		()							const;
		core::Matrix4D		getAbsTransform		()							const;
	
		CNode*				getParrentNode		()							const;
		CNode*				getChildNodeByID	( u32 childNodeID )			const;
		CNode*				getChildNodeByName  ( const std::string& name ) const;

	protected:

		CNode*				m_parrentNode;
		std::vector<CNode*>	m_childNodes;
		core::Matrix4D		m_transform;
	};
}
}

#endif