#include "Node.h"

using namespace scene;
using namespace core;

CNode::CNode() : m_parrentNode( nullptr )
{

}

CNode::~CNode()
{
	if( m_parrentNode )
	{
		m_parrentNode->dettachChildNode( this );
	}

	for( CNode* node : m_childNodes )
	{
		node->setParrentNode( nullptr );
	}

	m_childNodes.clear(); 
}

void CNode::setPosition( const Vector3D& position )
{
	m_transform.setTranslation( position );
}

void CNode::setRotation( const Vector3D& rotation )
{
	m_transform.setRotation( rotation );
}

void CNode::setScale( const Vector3D& scale )
{
	m_transform.setScale( scale );
}

void CNode::move( const Vector3D& deltaPosition )
{
	const Vector3D position = m_transform.getTranslation();
	m_transform.setTranslation( position + deltaPosition );
}

void CNode::rotate( const Vector3D& deltaRotation )
{
	const Vector3D rotation = m_transform.getRotation();
	m_transform.setRotation( rotation + deltaRotation );
}

void CNode::setTransform( const Matrix4D& transform )
{
	m_transform = transform;
}

void CNode::setParrentNode( CNode* parrentNode )
{
	if( m_parrentNode )
	{
		m_parrentNode->dettachChildNode( this ); 
	}
	m_parrentNode = parrentNode;
}

void CNode::attachChildNode( CNode* childNode )
{
	childNode->setParrentNode( this );
	m_childNodes.push_back( childNode );
}

void CNode::dettachChildNode( CNode* childNode )
{
	if( !m_childNodes.empty() )
	{
		m_childNodes.erase( std::remove( m_childNodes.begin(), m_childNodes.end(), childNode ), m_childNodes.end() ); 
		childNode->setParrentNode( nullptr );
	}
}

Vector3D CNode::getPosition() const
{
	return m_transform.getTranslation();
}

Vector3D CNode::getRotation() const
{
	return m_transform.getRotation();
}

Vector3D CNode::getScale() const
{
	return m_transform.getScale();
}

Matrix4D CNode::getTransform() const
{
	return m_transform;
}

Matrix4D CNode::getAbsTransform() const
{
	if( m_parrentNode )
	{
		const Matrix4D absTransform = m_parrentNode->getAbsTransform() * m_transform;
		return absTransform;
	}
	return m_transform;
}

CNode* CNode::getParrentNode() const
{
	return m_parrentNode;
}

CNode* CNode::getChildNodeByID( u32 childNodeID ) const
{
	return m_childNodes[childNodeID];
}

CNode* CNode::getChildNodeByName( const std::string& name ) const
{
	for( CNode* node : m_childNodes )
	{
		const std::string& nodeName = node->getName(); 
		if( nodeName == name )
		{
			return node;
		}
	}
	return nullptr;
}
