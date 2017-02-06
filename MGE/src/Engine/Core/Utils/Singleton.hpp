#pragma once

template <typename T>
class Singleton
{
protected:
	Singleton() = default;
public:
	T operator=(const T& other) = delete;

	static T& Instance()
	{
		static T instance;
		return instance;
	}
};