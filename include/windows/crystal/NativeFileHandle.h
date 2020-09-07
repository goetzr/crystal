#pragma once

#include <Windows.h>

namespace crystal {

class NativeFileHandle {
 private:
	HANDLE file_;
 public:
	NativeFileHandle(HANDLE file) noexcept : file_{ file } {}
	~NativeFileHandle() { Close(); }
	NativeFileHandle(NativeFileHandle const&) = delete;
	NativeFileHandle& operator=(NativeFileHandle const&) = delete;
	NativeFileHandle(NativeFileHandle&& rhs) noexcept : file_{ rhs.file_ } { rhs.file_ = INVALID_HANDLE_VALUE; }
	NativeFileHandle& operator=(NativeFileHandle&& rhs) noexcept {
		file_ = rhs.file_;
		rhs.file_ = INVALID_HANDLE_VALUE;
		return *this;
	}

	void Close() noexcept {
		CloseHandle(file_);
		file_ = INVALID_HANDLE_VALUE;
	}

	HANDLE Get() const noexcept { return file_; }

	bool IsValid() const noexcept { return file_ != INVALID_HANDLE_VALUE; }
	operator bool() const noexcept { return IsValid(); }
};

}