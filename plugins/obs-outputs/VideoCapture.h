#ifndef _VIDEO_CAPTURE_
#define _VIDEO_CAPTURE_

#include "modules/video_capture/video_capture_impl.h"
#include "rtc_base/refcountedobject.h"
class VideoCapture : public rtc::RefCountedObject<webrtc::videocapturemodule::VideoCaptureImpl>
{
public:
	VideoCapture() 
	{
		started = false;
	}
	int32_t StartCapture(const webrtc::VideoCaptureCapability& capability) override
	{
		_requestedCapability = capability;
		started = true;
		return 0;
	}
	int32_t StopCapture() override 
	{
		started = false;
		return 0;
	}
	bool CaptureStarted() override 
	{ 
		return started;
	}
	int32_t CaptureSettings(webrtc::VideoCaptureCapability& /*settings*/) override
	{
		return 0;
	}
private:
	bool started;
};


#endif
