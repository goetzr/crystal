#pragma once

#include <cstdio>

namespace crystal {

class FileHandle {
 private:
	std::FILE* file_;

 public:
	FileHandle(std::FILE* file) noexcept : file_{ file } {}
	~FileHandle() { Close(); }

	FileHandle(FileHandle const&) = delete;
	FileHandle& operator=(FileHandle const&) = delete;

	FileHandle(FileHandle&& rhs) noexcept : file_{ rhs.file_ } { rhs.file_ = nullptr; }
	FileHandle& operator=(FileHandle&& rhs) noexcept {
		file_ = rhs.file_;
		rhs.file_ = nullptr;
		return *this;
	}

	void Close() noexcept {
		std::fclose(file_);
		file_ = nullptr;
	}

	std::FILE* Get() const noexcept { return file_; }

	bool IsValid() const noexcept { return file_ != nullptr; }
	operator bool() const noexcept { return IsValid(); }
};

}