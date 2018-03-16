#pragma once
#include <tchar.h>
#include "MIDIIO.h"
class MIDIIOPPout
{
public:
	MIDIIOPPout();
	~MIDIIOPPout();

	static long GetDeviceNum();
	static long GetDeviceName(long lIndex, TCHAR* pszDeviceName, long lLen);

	void Open(const TCHAR* pszDeviceName);
	void Reopen(const TCHAR* pszDeviceName);

	long Close();

	long Reset();

	long PutMIDIMessage(unsigned char* pMessage, long lLen);

	long GetThisDeviceName(TCHAR* pszCeviceName, long lLen);

	MIDIOut * getMIDIobj();

private:
	MIDIOut * pMIDIOut;
};

