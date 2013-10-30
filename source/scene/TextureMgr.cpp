#include "TextureMgr.h"
#include "stream/FileStream.h"
#include "renderer/Renderer.h"

using namespace v3d;
using namespace v3d::scene;

CTextureManager::CTextureManager()
{

}

CTextureManager::~CTextureManager()
{
	unloadAll();
}

TexturePtr CTextureManager::get( const std::string& name )
{
	return m_textures[name];
}


TexturePtr CTextureManager::load( const std::string& name )
{
	auto it = m_textures.find( name );

	if( it != m_textures.end() )
	{
		return it->second;
	}
	else
	{
		
		for( std::string& path : m_pathes )
		{
			const std::string fullName = path + name;
			const bool isFileExist = stream::FileStream::isFileExist( fullName );
			if( isFileExist )
			{	
				stream::FileStream stream( fullName, stream::FileStream::e_in ); 

				if( stream.isOpen() )
				{
					for( DecoderPtr decoder : m_decoders )
					{
						renderer::CTexture* tex = static_cast<renderer::CTexture*>( decoder->decode( stream ) );
						if( tex )
						{
							TexturePtr texture( tex );
							m_textures[name] = texture;
							return texture;
						}
					}
				}
			}
		}
	}

	return nullptr;
}

TexturePtr CTextureManager::load( const stream::IStream& stream ) 
{
	return nullptr;
}


void CTextureManager::unload( const std::string& name )
{
	
}

void CTextureManager::unload( TexturePtr texture )
{

}


void CTextureManager::unloadAll()
{

}


void CTextureManager::registerPatch( const std::string& patch )
{
	m_pathes.push_back( patch );
}

void CTextureManager::registerDecoder( DecoderPtr decoder )
{
	m_decoders.push_back( decoder );
}

void CTextureManager::unregisterPatch( const std::string& patch )
{
	/*auto it = std::find( m_pathes.begin(), m_pathes.end(), patch );
	if( it != m_pathes.end() )
	{
		m_pathes.erase( std::remove( m_pathes.begin(), m_pathes.end(), m_pathes ), m_pathes.end() );
	}*/
}

void CTextureManager::unregisterDecoder( DecoderPtr decoder )
{
	/*auto it = std::find( m_decoders.begin(), m_decoders.end(), m_decoders );
	if( it != m_decoders.end() )
	{
		m_decoders.erase( std::remove( m_decoders.begin(), m_decoders.end(), m_decoders ), m_decoders.end() );
	}*/
}
