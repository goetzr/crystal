template<typename T>
class Handle {
 private:
	T handle_;
 public:
	Handle(T handle) : handle_{ handle } noexcept {}
	~Handle() { Close(); }
	Handle(Handle const& rhs) = delete;
	Handle& operator=(Handle const& rhs) = delete;
	Handle(Handle&& rhs) : handle_{ rhs.handle_ } { rhs.handle_ = INVALID_HANDLE_VALUE; }
	Handle& operator=(Handle&& rhs) {
		handle_ = rhs.handle_;
		rhs.handle_ = INVALID_HANDLE_VALUE;
	}

	void Close() noexcept {
		CloseHandle(handle_);
		handle_ = INVALID_HANDLE_VALUE;
	}

	HANDLE Get() const noexcept { return handle_; }

	operator bool() const noexcept { }

	bool IsValid() const noexcept() {}
};

class Handle {
	using 
}

// Type of handle (HANDLE, SOCKET, FILE*, etc.)
// Close function (CloseHandle, closesocket, fclose, etc.)
// Invalid handle value (INVALID_HANDLE_VALUE, NULL, etc.)

FileHandle f{ fopen("test.bin", "rb") };
	// Type: FILE*
	// Close: fclose
	// Invalid: NULL
FileHandle f{ CreateFile(...) };
	// Type: HANDLE
	// Close: CloseHandle
	// Invalid: INVALID_FILE_HANDLE
SocketHandle s{ socket(AF_INET, ...) };
	// Type: SOCKET
	// Close: closesocket
	// Invalid: INVALID_SOCKET
MutexHandle m{ CreateMutex(...) };
	// Type: HANDLE
	// Close: CloseHandle
	// Invalid: NULL

using FileHandle = Handle<FILE*>;
Handle<HANDLE>
Handle<SOCKET>
Handle<HANDLE>
