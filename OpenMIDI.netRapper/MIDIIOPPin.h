#pragma once
#include "MIDIIO.h"
#include <tchar.h>

class MIDIIOPPin
{
public:
	MIDIIOPPin();
	~MIDIIOPPin();

	static long GetDeviceNum();
	static long GetDeviceName(long lIndex, TCHAR* pszDeviceName, long lLen);

	void Open(const TCHAR* pszDeviceName);		//ñﬂÇËílÇÕÉÅÉìÉoïœêîÇ÷äiî[
	void Reopen(const TCHAR* pszDeviceName);

	long Close();

	long Reset();

	long GetMIDIMessage(unsigned char* pMessage, long lLen);

	long GetThisDeviceName(TCHAR* pszCeviceName, long lLen);
	
private:
	MIDIIn pMIDIIn;
};

