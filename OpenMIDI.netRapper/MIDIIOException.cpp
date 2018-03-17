#include "stdafx.h"
#include "MIDIIOException.h"


MIDIIOException::MIDIIOException()
{
}

MIDIIOException::MIDIIOException(String ^ message) : Exception(message)
{
}

MIDIIOException::MIDIIOException(String ^ message, Exception ^ inner) : Exception(message, inner)
{
}
