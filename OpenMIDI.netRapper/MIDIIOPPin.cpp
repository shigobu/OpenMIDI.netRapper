#include "stdafx.h"
#include "MIDIIO.h"
#include "MIDIIOPPin.h"


MIDIIOPPin::MIDIIOPPin()
{
	pMIDIIn = NULL;
}


MIDIIOPPin::~MIDIIOPPin()
{
}

long MIDIIOPPin::GetDeviceNum()
{
	return MIDIIn_GetDeviceNum();
}

long MIDIIOPPin::GetDeviceName(long lIndex, TCHAR * pszDeviceName, long lLen)
{
	return MIDIIn_GetDeviceName(lIndex, pszDeviceName, lLen);
}

void MIDIIOPPin::Open(const TCHAR * pszDeviceName)
{
	pMIDIIn = MIDIIn_Open(pszDeviceName);
}

void MIDIIOPPin::Reopen(const TCHAR * pszDeviceName)
{
	pMIDIIn = MIDIIn_Reopen(pMIDIIn, pszDeviceName);
}

long MIDIIOPPin::Close()
{
	long retval = MIDIIn_Close(pMIDIIn);
	pMIDIIn = NULL;
	return retval;
}

long MIDIIOPPin::Reset()
{
	return MIDIIn_Reset(pMIDIIn);
}

long MIDIIOPPin::GetMIDIMessage(unsigned char * pMessage, long lLen)
{
	return MIDIIn_GetMIDIMessage(pMIDIIn, pMessage, lLen);
}

long MIDIIOPPin::GetThisDeviceName(TCHAR * pszCeviceName, long lLen)
{
	return MIDIIn_GetThisDeviceName(pMIDIIn, pszCeviceName, lLen);
}

MIDIIn * MIDIIOPPin::getMIDIobj()
{
	return pMIDIIn;
}
