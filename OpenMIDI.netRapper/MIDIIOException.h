#pragma once
using namespace System;
namespace OpenMIDInetRapper 
{
	ref class MIDIIOException : Exception
	{
	public:
		MIDIIOException();
		MIDIIOException(String^ message);
		MIDIIOException(String^ message, Exception^ inner);
	};
}

