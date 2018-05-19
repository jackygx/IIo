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

#ifndef __IREADER_HPP__
#define __IREADER_HPP__

#include <EasyCpp.hpp>

DEFINE_INTERFACE(Reader);

DEFINE_FUNC(OnRead, void(const CConstStringPtr &));
DEFINE_FUNC(OnReadFail, void(void));

class IReader
{
public:
	IReader(void) {}
	virtual ~IReader(void) {}

	virtual IReaderPtr Read(const OnReadFn &onRead,
							const OnReadFailFn &onFail = nullptr) = 0;
};

#endif /* __IREADER_HPP__ */

