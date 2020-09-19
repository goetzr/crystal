#pragma once

#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <Windows.h>
#else
	static_assert("Unsupported platform");
#endif

namespace crystal {

#ifdef __linux__
	using Handle = int;
	constexpr Handle InvalidHandle = -1;
#elif _WIN32
	using Handle = HANDLE;
	constexpr Handle InvalidHandle = INVALID_HANDLE_VALUE;
#endif

class FileHandle {
 private:
	Handle file_;

 public:
	FileHandle(Handle file) noexcept : file_{ file } {}
	~FileHandle() { Close(); }

	FileHandle(FileHandle const&) = delete;
	FileHandle& operator=(FileHandle const&) = delete;

	FileHandle(FileHandle&& rhs) noexcept : file_{ rhs.file_ } { rhs.file_ = InvalidHandle; }
	FileHandle& operator=(FileHandle&& rhs) noexcept {
		file_ = rhs.file_;
		rhs.file_ = InvalidHandle;
		return *this;
	}

	void Close() noexcept {
		#ifdef __linux__
			close(file_);
		#elif _WIN32
			CloseHandle(file_);
		#endif
		file_ = InvalidHandle;
	}

	Handle Get() const noexcept { return file_; }

	bool IsValid() const noexcept { return file_ != InvalidHandle; }
	operator bool() const noexcept { return IsValid(); }
};

}