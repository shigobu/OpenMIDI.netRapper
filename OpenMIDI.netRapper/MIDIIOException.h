#pragma once
using namespace System;
ref class MIDIIOException : Exception
{
public:
	MIDIIOException();
	MIDIIOException(String^ message);
	MIDIIOException(String^ message, Exception^ inner);
};

