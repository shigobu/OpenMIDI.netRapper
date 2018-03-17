#pragma once
#include "MIDIIOPPin.h"

using namespace System;

namespace OpenMIDInetRapper {
	
	public ref class MIDIin
	{
	private:
		MIDIIOPPin * m_pMIDIIOPPin;
	public:
		MIDIin();
		~MIDIin();
		!MIDIin();

		static long GetDeviceNum();
		static String^ GetDeviceName(long lIndex);

		void Open(String^ DeviceName);
		void Reopen(String^ DeviceName);

		void Close();

		void Reset();

		array<Byte>^ GetMIDIMessage();

		String^ GetThisDeviceName();
	};
}
