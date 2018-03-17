#pragma once
#include <tchar.h>
#include "MIDIIO.h"

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

	MIDIIn * getMIDIobj();
	
private:
	MIDIIn *pMIDIIn;
};

