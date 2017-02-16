#pragma once

template <typename T>
class Singleton
{
private:
	static T* s_instance;
protected:
	Singleton() = default;
public:
	T operator=(const T& other) = delete;

	virtual ~Singleton()
	{
		s_instance = nullptr;
	}

	static T& Instance()
	{
		if (s_instance == nullptr)
		{
			s_instance = new T();
		}

		return *s_instance;
	}
};

template <typename T> T* Singleton<T>::s_instance = nullptr;