#include "stdafx.h"
#include "MIDIin.h"
#include "MIDIIOException.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Text;
using namespace System::Collections::Generic;

OpenMIDInetRapper::MIDIin::MIDIin()
{
	m_pMIDIIOPPin = new MIDIIOPPin;
}

OpenMIDInetRapper::MIDIin::~MIDIin()
{
	this->!MIDIin();
}

OpenMIDInetRapper::MIDIin::!MIDIin()
{
	this->Close();
	delete m_pMIDIIOPPin;
}

long OpenMIDInetRapper::MIDIin::GetDeviceNum()
{
	return MIDIIOPPin::GetDeviceNum();
}

String^ OpenMIDInetRapper::MIDIin::GetDeviceName(long lIndex)
{
	TCHAR buf[DeviceNameLen] = {0};
	long refVal = MIDIIOPPin::GetDeviceName(lIndex, buf, DeviceNameLen);
	//IntPtr^ ip = gcnew IntPtr(buf);
	return Marshal::PtrToStringAuto((IntPtr)buf);
}

void OpenMIDInetRapper::MIDIin::Open(String^ DeviceName)
{
	IntPtr pointer;
	pointer = Marshal::StringToHGlobalUni(DeviceName);
	m_pMIDIIOPPin->Open((const TCHAR*)pointer.ToPointer());
	Marshal::FreeHGlobal(pointer);
	//失敗したら
	MIDIIn* vpt = m_pMIDIIOPPin->getMIDIobj();
	if (vpt == NULL)
	{
		throw gcnew MIDIIOException("MIDIデバイスを開くのに失敗しました。");
	}
}

void OpenMIDInetRapper::MIDIin::Reopen(String^ DeviceName)
{
	IntPtr pointer;
	pointer = Marshal::StringToHGlobalUni(DeviceName);
	m_pMIDIIOPPin->Reopen((const TCHAR*)pointer.ToPointer());
	Marshal::FreeHGlobal(pointer);
	//失敗したら
	MIDIIn* vpt = m_pMIDIIOPPin->getMIDIobj();
	if (vpt == NULL)
	{
		throw gcnew MIDIIOException("MIDIデバイスを開く、または閉じるのに失敗しました。");
	}
}

void OpenMIDInetRapper::MIDIin::Close()
{
	long refVal = m_pMIDIIOPPin->Close();
	if (refVal == 0)
	{
		throw gcnew MIDIIOException("MIDIデバイスを閉じるのに失敗しました。");
	}
}

void OpenMIDInetRapper::MIDIin::Reset()
{
	long refVal = m_pMIDIIOPPin->Reset();
	if (refVal == 0)
	{
		throw gcnew MIDIIOException("MIDIデバイスをリセットするのに失敗しました。");
	}
}

array<Byte>^ OpenMIDInetRapper::MIDIin::GetMIDIMessage()
{
	unsigned char byMessage[MessageLen];
	long refVal = m_pMIDIIOPPin->GetMIDIMessage(byMessage, MessageLen);

	//取得したMIDIメッセージをバイト配列に変換
	List<Byte>^ refMessage = gcnew List<Byte>();
	IntPtr^ ip = gcnew IntPtr(byMessage);
	for (long i = 0; i < refVal; i++)
	{
		refMessage->Add(Marshal::ReadByte(ip, i));
	}
	return refMessage->ToArray();
}

String^ OpenMIDInetRapper::MIDIin::GetThisDeviceName()
{
	TCHAR buf[DeviceNameLen] = { 0 };
	long refVal = m_pMIDIIOPPin->GetThisDeviceName(buf, DeviceNameLen);
	//IntPtr^ ip = gcnew IntPtr(buf);
	return Marshal::PtrToStringAuto((IntPtr)buf);
}
