// Test_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../source/Valera3D.h"
#include <vector>


core::Vector2D v2t;
core::Vector3D v3t;
core::Vector4D v4t;
core::Matrix2D m2t;
core::Matrix3D m3t;
core::Matrix4D m4t;

core::Vector2D v2;
core::Vector3D v3;
core::Vector4D v4;
core::Matrix2D m2;
core::Matrix3D m3;
core::Matrix4D m4;

void TestVector2D()
{
		v2.operator -  ();
		v2.operator =  ( v2t );
		v2.operator +  ( v2t );
		v2.operator += ( v2t ); 
		v2.operator +  ( 0 );
		v2.operator += ( 0 ); 
		v2.operator -  ( v2t );
		v2.operator -= ( v2t ); 
		v2.operator -  ( 0 );
		v2.operator -= ( 0 );
		v2.operator *  ( v2t );
		v2.operator *= ( v2t );
		v2.operator *  ( 0 );
		v2.operator *= ( 0 ); 
		v2.operator /  ( v2t );
		v2.operator /= ( v2t ); 
		v2.operator /  ( 0 );
		v2.operator /= ( 0 );
		v2.operator <= ( v2t );
		v2.operator >= ( v2t );
		v2.operator <  (v2t );
		v2.operator >  ( v2t );
		v2.operator == ( v2t );
		v2.operator != ( v2t );

		v2.set( 0, 0 ); 
		v2.set( v2t );

		v2.isEquals( v2t );
		v2.isInLine( v2t, v2t );
	
		v2.length();
		v2.lengthSQ();

		v2.distanceFrom( v2t );
		v2.distanceFromSQ( v2t );
	
		v2.normalize();
		v2.invert();

		v2.setLength( 0 );
}

void TestVector3D()
{
		v3.operator -  ();
		v3.operator =  ( v3t );
		v3.operator +  ( v3t );
		v3.operator += ( v3t ); 
		v3.operator +  ( 0 );
		v3.operator += ( 0 ); 
		v3.operator -  ( v3t );
		v3.operator -= ( v3t ); 
		v3.operator -  ( 0 );
		v3.operator -= ( 0 );
		v3.operator *  ( v3t );
		v3.operator *= ( v3t );
		v3.operator *  ( 0 );
		v3.operator *= ( 0 ); 
		v3.operator /  ( v3t );
		v3.operator /= ( v3t ); 
		v3.operator /  ( 0 );
		v3.operator /= ( 0 );
		v3.operator <= ( v3t );
		v3.operator >= ( v3t );
		v3.operator <  (v3t );
		v3.operator >  ( v3t );
		v3.operator == ( v3t );
		v3.operator != ( v3t );

		v3.set( 0, 0, 0 ); 
		v3.set( v3t );

		v3.isEquals( v3t );
		v3.isInLine( v3t, v3t );
	
		v3.length();
		v3.lengthSQ();

		v3.distanceFrom( v3t );
		v3.distanceFromSQ( v3t );
	
		v3.normalize();
		v3.invert();

		v3.setLength( 0 );
}

void TestVector4D()
{
		v4.operator -  ();
		v4.operator =  ( v4t );
		v4.operator +  ( v4t );
		v4.operator += ( v4t ); 
		v4.operator +  ( 0 );
		v4.operator += ( 0 ); 
		v4.operator -  ( v4t );
		v4.operator -= ( v4t ); 
		v4.operator -  ( 0 );
		v4.operator -= ( 0 );
		v4.operator *  ( v4t );
		v4.operator *= ( v4t );
		v4.operator *  ( 0 );
		v4.operator *= ( 0 ); 
		v4.operator /  ( v4t );
		v4.operator /= ( v4t ); 
		v4.operator /  ( 0 );
		v4.operator /= ( 0 );
		v4.operator <= ( v4t );
		v4.operator >= ( v4t );
		v4.operator <  (v4t );
		v4.operator >  ( v4t );
		v4.operator == ( v4t );
		v4.operator != ( v4t );

		v4.set( 0, 0, 0, 0 ); 
		v4.set( v4t );

		v4.isEquals( v4t );
		v4.isInLine( v4t, v4t );
	
		v4.length();
		v4.lengthSQ();

		v4.distanceFrom( v4t );
		v4.distanceFromSQ( v4t );
	
		v4.normalize();
		v4.invert();

		v4.setLength( 0 );
}

void TestMatrix2D()
{
	m2.operator () ( 0, 0 );
	m2.operator () ( 0, 0 );
	m2.operator [] ( 0 ); 					
	m2.operator [] ( 0 );			
	m2.operator =  ( 0 );			
	m2.operator == ( m2t );	
	m2.operator != ( m2t );	
	m2.operator +  ( m2t );	
	m2.operator += ( m2t );	
	m2.operator -  ( m2t );	
	m2.operator -= ( m2t );	
	m2.operator *  ( m2t );	
	m2.operator *= ( m2t );	
	m2.operator *  ( 0 );				
	m2.operator *= ( 0 );			
	
	m2.set( 0 );

	m2.getPtr(); 
	m2.getPtr();									
										
	m2.makeIdentity();								
	m2.isIdentity();							

	m2.setRotation( 0 );						
	m2.getRotation();								
	
	m2.preScale( v2t );
	m2.postScale( v2t );	
	m2.setScale( v2t );		
	m2.getScale();									

	m2.makeInverse();								
	m2.getInverse( m2t );								
	
	m2.makeTransposed();
	m2.getTransposed();								
}

void TestMatrix3D()
{
	m3.operator () ( 0, 0 );
	m3.operator () ( 0, 0 );
	m3.operator [] ( 0 ); 					
	m3.operator [] ( 0 );			
	m3.operator =  ( 0 );			
	m3.operator == ( m3t );	
	m3.operator != ( m3t );	
	m3.operator +  ( m3t );	
	m3.operator += ( m3t );	
	m3.operator -  ( m3t );	
	m3.operator -= ( m3t );	
	m3.operator *  ( m3t );	
	m3.operator *= ( m3t );	
	m3.operator *  ( 0 );				
	m3.operator *= ( 0 );			
	
	m3.set( 0 );

	m3.getPtr(); 
	m3.getPtr();									
										
	m3.makeIdentity();								
	m3.isIdentity();							

	m3.setRotation( 0 );						
	m3.getRotation();								
	
	m3.preScale( v2t );
	m3.postScale( v2t );	
	m3.setScale( v2t );		
	m3.getScale();									

	m3.makeInverse();								
	m3.getInverse( m3t );								
	
	m3.makeTransposed();
	m3.getTransposed();			
}

void TestMatrix4D()
{
	m4.operator () ( 0, 0 );
	m4.operator () ( 0, 0 );
	m4.operator [] ( 0 ); 					
	m4.operator [] ( 0 );			
	m4.operator =  ( 0 );			
	m4.operator == ( m4t );	
	m4.operator != ( m4t );	
	m4.operator +  ( m4t );	
	m4.operator += ( m4t );	
	m4.operator -  ( m4t );	
	m4.operator -= ( m4t );	
	m4.operator *  ( m4t );	
	m4.operator *= ( m4t );	
	m4.operator *  ( 0 );				
	m4.operator *= ( 0 );			
	
	m4.set( 0 );

	m4.getPtr(); 
	m4.getPtr();									
										
	m4.makeIdentity();								
	m4.isIdentity();							

	m4.setRotation( v3t );						
	m4.getRotation();								
	
	m4.preScale( v3t );
	m4.postScale( v3t );	
	m4.setScale( v3t );		
	m4.getScale();									

	m4.makeInverse();								
	m4.getInverse();								
	
	m4.makeTransposed();
	m4.getTransposed();

	m4t = core::buildProjectionMatrixPerspective( 0, 0, 0, 0 );
	m4t = core::buildProjectionMatrixOrtho( 0, 0, 0, 0, 0, 0 );
	m4t = core::buildLookAtMatrix( v3t, v3t, v3t ); 

}



int _tmain(int argc, _TCHAR* argv[])
{
	TestVector2D();
	TestVector3D();
	TestVector4D();
	TestMatrix2D();
	TestMatrix3D();
	TestMatrix4D();

	f32 d0 = core::distance( v2t, v2t );
	f32 d1 = core::distance( v2t, v2t );
	f32 d2 = core::distance( v2t, v2t );

	//v2.isInLine( v2t, v2t );

	//m3.setRotation( core::Vector3D(0,0,0) );

	return 0;
}

