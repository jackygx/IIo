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

#ifndef __IWRITER_HPP__
#define __IWRITER_HPP__

#include <EasyCpp.hpp>

DEFINE_INTERFACE(Writer);

DEFINE_FUNC(OnWritten, void(void));
DEFINE_FUNC(OnWriteFail, void(void));

class IWriter
{
public:
	IWriter(void) {}
	virtual ~IWriter(void) {}

	virtual IWriterPtr Write(const CConstStringPtr &data,
							 const OnWriteFailFn &onFail = nullptr,
							 const OnWrittenFn &onWritten = nullptr) = 0;
};

#endif /* __IWRITER_HPP__ */

