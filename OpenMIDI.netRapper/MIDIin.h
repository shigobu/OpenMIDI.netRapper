#pragma once
#include "MIDIIOPPin.h"

using namespace System;

namespace OpenMIDInetRapper {
	/// <summary>
	/// MIDIの入力に関する機能を提供します。
	/// </summary>
	public ref class MIDIin
	{
	private:
		MIDIIOPPin * m_pMIDIIOPPin;
	public:
		MIDIin();
		~MIDIin();
		!MIDIin();

		/// <summary>
		/// MIDI入力デバイスの数を返します。
		/// </summary>
		/// <returns>MIDI入力デバイスの数</returns>
		static long GetDeviceNum();

		/// <summary>
		/// MIDI入力デバイスの名前の返します。
		/// </summary>
		/// <param name="lIndex">MIDI入力デバイスのインデックス</param>
		/// <returns>MIDI入力デバイス名</returns>
		static String^ GetDeviceName(long lIndex);

		/// <summary>
		/// MIDI入力デバイスを開きます。
		/// </summary>
		/// <param name="DeviceName">MIDI入力デバイス名</param>
		void Open(String^ DeviceName);
		/// <summary>
		/// 現在使用しているMIDI入力デバイスを閉じ、新しいMIDI入力デバイスを開きます。
		/// </summary>
		/// <param name="DeviceName">新しいMIDI入力デバイス名</param>
		void Reopen(String^ DeviceName);

		/// <summary>
		/// MIDI入力デバイスを閉じます。
		/// </summary>
		void Close();

		/// <summary>
		/// MIDI入力デバイスをリセットし、MIDI入力デバイスを開いた直後の状態に初期化します。
		/// </summary>
		void Reset();

		/// <summary>
		/// MIDIメッセージをひとつ取得し、実際に取得したMIDIメッセージを返します。
		/// </summary>
		/// <returns></returns>
		array<Byte>^ GetMIDIMessage();


		/// <summary>
		/// このMIDI入力デバイスの名前を調べます。
		/// </summary>
		/// <returns></returns>
		String^ GetThisDeviceName();
	};
}
