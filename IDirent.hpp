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

#ifndef __IDIRENT_HPP__
#define __IDIRENT_HPP__

#include "IFolderHeader.hpp"
#include "IFile.hpp"

DEFINE_INTERFACE(Dirent);

class IDirent
{
protected:
	enum DirType {
		FOLDER,
		FILE,
	};

	DEFINE_CLASS(DirInfo);

	class CDirInfo
	{
	private:
		CConstStringPtr mPath;
		uint64_t mSize;
		DirType mType;

	public:
		CDirInfo(CConstStringPtr path,
				 uint64_t size,
				 DirType type) :
			mPath(path),
			mSize(size),
			mType(type)
		{
			/* Does nothing */
		}

		inline CConstStringPtr GetPath(void) const
		{
			return mPath;
		}

		inline uint64_t GetSize(void) const
		{
			return mSize;
		}

		inline bool IsFolder(void) const
		{
			return mType == IDirent::FOLDER;
		}
	};


protected:
	CDirInfoPtr mInfo;

public:
	IDirent(const CDirInfoPtr &info) :
		mInfo(info)
	{
		/* Does nothing */
	}

	virtual ~IDirent(void) {}

public:
	inline CConstStringPtr GetPath(void) const
	{
		return mInfo->GetPath();
	}

	inline CConstStringPtr GetBaseName(void) const
	{
		return mInfo->GetPath()->Split("/")->Reverse()
			->First([](const CConstStringPtr &name) {
				return name;
			});
	}

	inline CConstStringPtr GetDirName(void) const
	{
		CConstStringPtr ret(mInfo->GetPath()->Split("/")->Reverse()
			->First([](const CConstStringPtr &) {
				/* Does nothing */
			})->Rest([](const CConstStringPtr &path) {
				return path;
			}));

		return ret ? ret : ".";
	}

	inline uint64_t GetSize(void) const
	{
		return mInfo->GetSize();
	}

	inline bool IsFolder(void) const
	{
		return mInfo->IsFolder();
	}

	inline IFolderPtr ToFolder(void) const
	{
		if (!mInfo->IsFolder()) {
			throw E("Entity: ", mInfo->GetPath(), " is a file");
		}

		return _ToFolder();
	}

	inline IFilePtr ToFile(void) const
	{
		if (mInfo->IsFolder()) {
			throw E("Entity: ", mInfo->GetPath(), " is a folder");
		}

		return _ToFile();
	}

private:
	virtual IFolderPtr _ToFolder(void) const = 0;
	virtual IFilePtr _ToFile(void) const = 0;
};

#endif /* __IDIRENT_HPP__ */

