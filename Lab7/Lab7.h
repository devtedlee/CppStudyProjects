#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;

		typename std::vector<K>::const_iterator kIter = keys.begin();
		typename std::vector<V>::const_iterator vIter = values.begin();
		while (kIter != keys.end() && vIter != values.end())
		{
			if (m.find(*kIter) == m.end())
			{
				m.insert(std::pair<K, V>(*kIter, *vIter));
			}

			++kIter;
			++vIter;
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		
		for (typename std::vector<T>::const_reverse_iterator rIter = v.rbegin(); rIter != v.rend(); ++rIter)
		{
			rv.push_back(*rIter);
		}

		return rv;
	}

	template <typename T>
	bool IsDuplicatedValueExist(const std::vector<T>& v, const T value)
	{
		for (typename std::vector<T>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			if (value == *iter)
			{
				return true;
			}
		}

		return false;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;

		typename std::vector<T>::const_iterator iter = v1.begin();
		for (; iter != v1.end(); ++iter)
		{
			if (!IsDuplicatedValueExist(combined, *iter))
			{
				combined.push_back(*iter);
			}
		}

		for (iter = v2.begin(); iter != v2.end(); ++iter)
		{
			if (!IsDuplicatedValueExist(combined, *iter))
			{
				combined.push_back(*iter);
			}
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		typename std::map<K, V>::const_iterator iter = m1.begin();
		for (; iter != m1.end(); ++iter)
		{
			if (combined.find(iter->first) == combined.end())
			{
				combined.insert(*iter);
			}
		}

		for (iter = m2.begin(); iter != m2.end(); ++iter)
		{
			if (combined.find(iter->first) == combined.end())
			{
				combined.insert(*iter);
			}
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		typename std::vector<T>::const_iterator iter = v.begin();
		if (iter == v.end())
		{
			return os;
		}

		for (; iter != v.end() - 1; ++iter)
		{
			os << *iter << ", ";
		}
		
		os << *iter;

		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			os << "{ " << iter->first << ", " << iter->second << " }" << std::endl;
		}

		return os;
	}
}
