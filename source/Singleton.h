#ifndef _V3D_SINGLETON_H_
#define _V3D_SINGLETON_H_

namespace v3d
{
	template <class T>
	class Singleton
	{
	public:

		static T*	GetInstance();
		static void FreeInstance();
	
	protected:
					Singleton();
		virtual		~Singleton();
	
	private:

		static T*	s_pInstance;
	};
}


template <class T>
T* Singleton<T>::s_pInstance = nullptr;

template <class T>
Singleton<T>::Singleton()
{
}

template <class T>
Singleton<T>::~Singleton()
{
}

template <class T>
T *Singleton<T>::GetInstance()
{
	if( s_pInstance == nullptr )
	{
		s_pInstance = new T;
	}

	return s_pInstance;
}

template <class T>
void Singleton<T>::FreeInstance()
{
	if( s_pInstance )	
	{
		delete s_pInstance;
	}

	s_pInstance = nullptr;
}

#endif
