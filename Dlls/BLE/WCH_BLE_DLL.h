//****************************************
//**  Copyright  (C)  WCH 2019   **
//**  Web:  http://www.wch.cn  **
//****************************************
//**  DLL for BLE  **
//**  Win10 ,C/C++ **
//****************************************
//
// BLE�ӿڿ� Version��1.0.0
// �ߺ�΢����  ����: WCH��PK 2019.10
// WCH_BLE_DLL  V1.0 
// ���л���: Windows 10
#pragma once
#include "stdafx.h"

#ifdef __cplusplus
extern "C" {
#endif

//
// ժҪ:
//     �ص���֪ͨӦ���ϲ�BLE�����ѳɹ��������Ϣ
//
// ����:
//   uAction_Service:
//     BLE��������ţ�
//	   0:����ͨѶ	
//	   1:���������豸����
//	   2:��ȡ����
//	   3:��ȡ����
//	   4:�鿴����֧�ֵĲ���
//	   5:��
//	   6:д����
//	   7:�򿪶���
//	   8:�رն���
//	   9:�ͷ���Դ
//	   10:�����豸IDֵ
//	   11:��
//	   12:�رպ�̨ͨѶ
//   tmpStr:
//     ��̨�����Ľ����
//   iExtraInfo:
//     1.ָ������ֵ�����еĲ������(Read�� Write�� Subscribe)��0-7��������ö������ֵ����ʱ
//
// ���ؽ��:
//     �ޡ�
typedef void (CALLBACK* Notify_AppService)(ULONG uAction_Service, PCHAR tmpStr, INT iExtraInfo);
//
// ժҪ:
//     �ص���֪ͨӦ���ϲ�DeviceWatcher�Ĳ������
//
// ����:
//   deviceName:
//     ö�ٵ����豸���ơ�
//   deviceID:
//     ö�ٵ����豸ID��
//
// ���ؽ��:
//     �ޡ�
typedef void (CALLBACK* Notify_DeviceWatcher)(PCHAR deviceName, PCHAR deviceID);
//
// ժҪ:
//     �ص���֪ͨӦ���ϲ�AppService�����쳣��ֵ
//     �����ˣ�BLE�������쳣������Ӧ�úͺ�̨����ͨѶ����쳣
//
// ����:
//   errorString:
//     �쳣�����ԡ�
//
// ���ؽ��:
//     �ޡ�
typedef void (CALLBACK* Notify_ErrorStatus)(PCHAR errorString);
//
// ժҪ:
//     �ص������ض�ȡ���ֽ�
//
// ����:
//   readBytes:
//     ��ȡ���ֽڡ�
//   iLength:
//     �ֽ�����
//
// ���ؽ��:
//     �ޡ�
typedef void (CALLBACK* Notify_ReadBytes)(PUCHAR readBytes, INT iLength);
//
// ժҪ:
//     ��һ�������Ӻ�̨UWP����ͨ���ص��ж����ӽ����
//
// ����:
//	   �ص�������
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEConnectToService(Notify_AppService fun, Notify_ErrorStatus errorFun, Notify_ReadBytes readFun);
//
// ժҪ:
//     �ڶ�����ö����ΧBLE�豸��ͨ���ص�Notify_DeviceWatcher����ö�ٽ����
//
// ����:
//	   �ص�������
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEStartScanBLEDevices(Notify_DeviceWatcher fun);
//
// ժҪ:
//     ������������ö�٣��ͷ���Դ��
//
// ����:
//	   �ص�������
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEStopScanBLEDevices(Notify_DeviceWatcher fun);
//
// ժҪ:
//     ���Ĳ���ѡ��������豸�����豸ID���͸���̨UWP����
//
// ����:
//	   �ص�������
//   deviceID:
//		�豸��ID�ַ�����
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLESendBLEDeviceID(PCHAR deviceID, Notify_AppService fun, Notify_ErrorStatus errorFun);
//
// ժҪ:
//     ���岽������ָ����BLE�豸
//
// ����:
//	   �ص�������
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLECreateConnection(Notify_AppService fun, Notify_ErrorStatus errorFun);
//
// ժҪ:
//     ����������ȡָ��BLE֧�ֵķ����б����ַ�����ʽͨ���ص������ϲ�Ӧ��
//
// ����:
//	   �ص�������
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEGetServicesEnum(Notify_AppService fun, Notify_ErrorStatus errorFun);
//
// ժҪ:
//     ���߲�����ȡָ��������֧�ֵ������б����ַ�����ʽͨ���ص������ϲ�Ӧ��
//
// ����:
//	   �ص�������
//   nService:
//		ָ���ķ�����š�
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEGetCharacteristicEnum(INT nService, Notify_AppService fun, Notify_ErrorStatus errorFun);
//
// ժҪ:
//     �ڰ˲�����ȡָ��������֧�ֵĲ������ص�����0-7����λ��ʾ���еĹ���(��λ-��λ��read, write, subscribe)
//	   0			0			0
//	 Subscribe    Write		   Read
//
// ����:
//	   �ص�������
//   nCharacteristic:
//	   ѡ���������
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEGetCharacteristicAction(INT nCharacteristic, Notify_AppService fun, Notify_ErrorStatus errorFun);
//
// ժҪ:
//     �ھŲ�����ȡ����ֵ��
//
// ����:
//	   �ص�������
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEGetReadBuffer(Notify_ReadBytes fun, Notify_ErrorStatus errorFun);
//
// ժҪ:
//     ��ʮ����д������ֵ��
//
// ����:
//	   �ص�������
//   bufferStr:
//	   ��д������顣
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEWriteBuffer(PCHAR bufferStr, Notify_AppService fun, Notify_ErrorStatus errorFun);
//
// ժҪ:
//     ��ʮ��Ex��д������ֵ��
//
// ����:
//	   �ص�������
//   bufferStr:
//	   ��д������顣
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEWriteBufferEx(PCHAR bufferStr, UINT length, Notify_AppService fun, Notify_ErrorStatus errorFun);
//
// ժҪ:
//     ��ʮһ��������ValueChanged�¼����ģ�ÿ������ֵ�ı�ʱ����ȡ����ֵ
//
// ����:
//	   �ص�������
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEStartMonitoring(Notify_AppService fun, Notify_ErrorStatus errorFun);
//
// ժҪ:
//     ��ʮ�������ر�ValueChanged�¼�����
//
// ����:
//	   �ص�������
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEStopMonitoring(Notify_AppService fun, Notify_ErrorStatus errorFun);
//
// ժҪ:
//     ��ʮ�������ͷ���Դ���ر���BLE�豸������
//
// ����:
//	   �ص�������
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLEReleaseResource(Notify_AppService fun, Notify_ErrorStatus errorFun);
//
// ժҪ:
//     ��ʮ�Ĳ����ͷ���Դ���ر����̨UWP������
//
// ����:
//	   �ޡ�
//
// ���ؽ��:
//     �ޡ�
void WINAPI WCHBLECloseConnection();

#ifdef __cplusplus
}
#endif