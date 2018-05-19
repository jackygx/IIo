/*
 * Copyright (c) 2018 Guo Xiang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __IFOLDER_HPP__
#define __IFOLDER_HPP__

#include "IDirent.hpp"

inline void IFolder::_Begin(void)
{
	FirstEntity();
}

inline bool IFolder::_End(void) const
{
	return IsLastEntity();
}

inline void IFolder::_Next(void)
{
	NextEntity();
}

template <class Fn, class... Tn>
inline decltype(auto) IFolder::_Get(const Fn &fn, const Tn & ... tn)
{
	return fn(GetEntity(), tn...);
}

inline bool IFolder::_Match(const CConstStringPtr &name)
{
	return name == GetEntity()->GetBaseName();
}

inline void IFolder::_Sort(enum SortType type)
{
	SortEntity(type);
}

#endif /* __IFOLDER_HPP__ */

