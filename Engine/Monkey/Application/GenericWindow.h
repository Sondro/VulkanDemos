#pragma once

#include "Common/Common.h"
#include <string>

namespace WindowMode
{
	enum Type
	{
		Fullscreen,
		WindowedFullscreen,
		Windowed,
		NumWindowModes
	};

	static FORCEINLINE Type ConvertIntToWindowMode(int32 windowMode)
	{
		Type mode = Windowed;
		switch (windowMode)
		{
		case 0:
			mode = Fullscreen;
			break;
		case 1:
			mode = WindowedFullscreen;
			break;
		case 2:
		default:
			mode = Windowed;
			break;
		}
		return mode;
	}
	
	FORCEINLINE const char* LexToString(Type windowMode)
	{
		switch (windowMode)
		{
			case Fullscreen:			return "Fullscreen";
			case WindowedFullscreen:	return "WindowedFullscreen";
			case Windowed:				return "Windowed";
			default:					return "Unknown";
		}
	}
}

class GenericWindow
{
public:
	GenericWindow();

	virtual ~GenericWindow();

	virtual const std::string& GetTitle() const;

	virtual void ReshapeWindow(int32 x, int32 y, int32 width, int32 height);

	virtual bool GetFullScreenInfo(int32& x, int32& y, int32& width, int32& height) const;

	virtual void MoveWindowTo(int32 x, int32 y);

	virtual void BringToFront(bool force = false);

	virtual void Destroy();

	virtual void Minimize();

	virtual void Maximize();

	virtual void Restore();

	virtual void Show();

	virtual void Hide();

	virtual void SetWindowMode(WindowMode::Type newWindowMode);

	virtual WindowMode::Type GetWindowMode() const;

	virtual bool IsMaximized() const;

	virtual bool IsMinimized() const;

	virtual bool IsVisible() const;

	virtual bool GetRestoredDimensions(int32& x, int32& y, int32& width, int32& height);

	virtual void SetWindowFocus();

	virtual void SetOpacity(const float opacity);

	virtual void Enable(bool enable);

	virtual bool IsPointInWindow(int32 x, int32 y) const;

	virtual int32 GetWindowBorderSize() const;

	virtual int32 GetWindowTitleBarSize() const;

	virtual void* GetOSWindowHandle() const;

	virtual bool IsForegroundWindow() const;

	virtual void SetText(const char* const text);

	virtual float GetDPIScaleFactor() const;

	virtual void SetDPIScaleFactor(const float factor);

	virtual bool IsManualManageDPIChanges() const;

	virtual void SetManualManageDPIChanges(const bool autoHandle);

};


