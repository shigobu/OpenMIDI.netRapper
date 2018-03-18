#include "stdafx.h"
#include "MIDIIOException.h"


OpenMIDInetRapper::MIDIIOException::MIDIIOException()
{
}

OpenMIDInetRapper::MIDIIOException::MIDIIOException(String ^ message) : Exception(message)
{
}

OpenMIDInetRapper::MIDIIOException::MIDIIOException(String ^ message, Exception ^ inner) : Exception(message, inner)
{
}
