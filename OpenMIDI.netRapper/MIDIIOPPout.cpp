#include "stdafx.h"
#include <tchar.h>
#include "MIDIIO.h"
#include "MIDIIOPPout.h"


MIDIIOPPout::MIDIIOPPout()
{
	pMIDIOut = NULL;
}


MIDIIOPPout::~MIDIIOPPout()
{
}

long MIDIIOPPout::GetDeviceNum()
{
	return MIDIOut_GetDeviceNum();
}

long MIDIIOPPout::GetDeviceName(long lIndex, TCHAR * pszDeviceName, long lLen)
{
	return MIDIOut_GetDeviceName(lIndex, pszDeviceName, lLen);
}

void MIDIIOPPout::Open(const TCHAR * pszDeviceName)
{
	pMIDIOut = MIDIOut_Open(pszDeviceName);
}

void MIDIIOPPout::Reopen(const TCHAR * pszDeviceName)
{
	pMIDIOut = MIDIOut_Reopen(pMIDIOut, pszDeviceName);
}

long MIDIIOPPout::Close()
{
	long retval = MIDIOut_Close(pMIDIOut);
	pMIDIOut = NULL;
	return retval;
}

long MIDIIOPPout::Reset()
{
	return MIDIOut_Reset(pMIDIOut);
}

long MIDIIOPPout::PutMIDIMessage(unsigned char * pMessage, long lLen)
{
	return MIDIOut_PutMIDIMessage(pMIDIOut, pMessage, lLen);
}

long MIDIIOPPout::GetThisDeviceName(TCHAR * pszCeviceName, long lLen)
{
	return MIDIOut_GetThisDeviceName(pMIDIOut, pszCeviceName, lLen);
}

MIDIOut * MIDIIOPPout::getMIDIobj()
{
	return pMIDIOut;
}
