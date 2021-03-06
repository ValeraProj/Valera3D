#ifndef V3D_FILE_STREAM_H_
#define V3D_FILE_STREAM_H_

#include "common.h"
#include "IStream.h"

namespace v3d
{
namespace stream
{
	class FileStream : public IStream
	{
	public:
	
		enum EOpenMode
		{
			e_in		= 1 << 0,
			e_out		= 1 << 1,
			e_ate		= 1 << 2,
			e_app		= 1 << 3,
			e_trunc		= 1 << 4,
			e_create	= 1 << 5
		};

		static bool isFileExist( const std::string& fileName );

		FileStream();
		FileStream( const std::string& fileName,
				    EOpenMode openMode = e_in );

		~FileStream();
		
		bool open( const std::string& fileName,
				   EOpenMode openMode = e_in );
		void close();
		
		bool isOpen() const;

		u32 read( void* buffer,
				  const u32 size,
			      const u32 count = 1 )			override;
		
		u32 read( u8& value )					override;
		u32 read( s8& value )					override;
		u32 read( u16& value )					override;
		u32 read( s16& value )					override;
		u32 read( u32& value )					override;
		u32 read( s32& value )					override;
		u32 read( u64& value )					override;
		u32 read( s64& value )					override;
		u32 read( f32& value )					override;
		u32 read( f64& value )					override;
		u32 read( f80& value )					override;
		u32 read( bool& value )					override;
		u32 read( std::string& value )			override;
	
		u32 write( void* buffer,
				   const u32 size,
				   const u32 count = 1 )		override;
	
		u32 write( const u8 value )				override;
		u32 write( const s8 value )				override;
		u32 write( const u16 value )			override;
		u32 write( const s16 value )			override;
		u32 write( const u32 value )			override;
		u32 write( const s32 value )			override;
		u32 write( const u64 value )			override;
		u32 write( const s64 value )			override;
		u32 write( const f32 value )			override;
		u32 write( const f64 value )			override;
		u32 write( const f80 value )			override;
		u32 write( const bool value )			override;
		u32 write( const std::string& value )	override;
		
		void seekBeg( const u32 offset )		override;
		void seekCur( const u32 offset )		override;
		u32 tell()								override;
		u32 size()								override;

		void* map( const u32 size )				override;
		void  unmap()							override;
		
		std::string  getName() const			override;

	protected:

		FILE*		m_fileHandler;
		std::string m_fileName;
		EOpenMode	m_openMode;
		u32			m_fileSize;
		bool		m_isOpen;
		
	};

}
}

#endif