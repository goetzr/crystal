#pragma once

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

namespace crystal {

class NativeFileHandle {
 private:
	int file_;
 public:
	NativeFileHandle(int file) noexcept : file_{ file } {}
	~NativeFileHandle() { Close(); }
	NativeFileHandle(NativeFileHandle const&) = delete;
	NativeFileHandle& operator=(NativeFileHandle const&) = delete;
	NativeFileHandle(NativeFileHandle&& rhs) noexcept : file_{ rhs.file_ } { rhs.file_ = -1; }
	NativeFileHandle& operator=(NativeFileHandle&& rhs) noexcept {
		file_ = rhs.file_;
		rhs.file_ = -1;
		return *this;
	}

	void Close() noexcept {
		close(file_);
		file_ = -1;
	}

	int Get() const noexcept { return file_; }

	bool IsValid() const noexcept { return file_ != -1; }
	operator bool() const noexcept { return IsValid(); }
};

}