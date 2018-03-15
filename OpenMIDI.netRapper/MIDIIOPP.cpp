#include "stdafx.h"
#include "MIDIIO.h"
#include "MIDIIOPPin.h"


MIDIIOPPin::MIDIIOPPin()
{
}


MIDIIOPPin::~MIDIIOPPin()
{
}

long MIDIIOPPin::GetDeviceNum()
{
	return 0;
}

long MIDIIOPPin::GetDeviceName(long lIndex, TCHAR * pszDeviceName, long lLen)
{
	return 0;
}

void MIDIIOPPin::Open(const TCHAR * pszDeviceName)
{
}

void MIDIIOPPin::Reopen(const TCHAR * pszDeviceName)
{
}

long MIDIIOPPin::Close()
{
	return 0;
}

long MIDIIOPPin::Reset()
{
	return 0;
}

long MIDIIOPPin::GetMIDIMessage(unsigned char * pMessage, long lLen)
{
	return 0;
}

long MIDIIOPPin::GetThisDeviceName(TCHAR * pszCeviceName, long lLen)
{
	return 0;
}
