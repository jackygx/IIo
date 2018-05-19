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

#ifndef __IFOLDER_HEADER_HPP__
#define __IFOLDER_HEADER_HPP__

#include <EasyCpp.hpp>
#include "IFile.hpp"

DEFINE_INTERFACE(Folder);
DEFINE_INTERFACE(Dirent);
DEFINE_ITERATOR(IFolder, IDirentPtr);

class IFolder :
	public IFolderBase
{
	friend IFolderBase;

public:
	IFolder(void) {}
	virtual ~IFolder(void) {}

	enum SortType {
		BY_NAME,
		BY_SIZE,
	};

	virtual IFolderPtr CreateFolder(const CConstStringPtr &name) = 0;
	virtual IFilePtr CreateFile(const CConstStringPtr &name) = 0;
	virtual void Delete(const CConstStringPtr &name) = 0;
	virtual IDirentPtr ToDirent(void) const = 0;

private:
	virtual void FirstEntity(void) = 0;
	virtual void NextEntity(void) = 0;
	virtual bool IsLastEntity(void) const = 0;
	virtual IDirentPtr GetEntity(void) = 0;
	virtual void SortEntity(enum SortType type) = 0;

private:
	inline void _Begin(void);
	inline bool _End(void) const;
	inline void _Next(void);

	template <class Fn, class... Tn>
	inline decltype(auto) _Get(const Fn &fn, const Tn & ... tn);
	inline bool _Match(const CConstStringPtr &name);
	inline void _Sort(enum SortType type);
};

#endif /* __IFOLDER_HEADER_HPP__ */

