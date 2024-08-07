#pragma once

template <typename T>
class Singleton {
public:
	Singleton() = default;
	virtual ~Singleton() = default;
	Singleton(Singleton &&) = delete;
	Singleton(const Singleton &) = delete;
	void operator = (const Singleton &) = delete;

	static T& ins()
	{
		static T object;
		return object;
	}
};