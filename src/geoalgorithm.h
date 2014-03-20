/**
\file geoalgorithm.h
\brief �����㷨�ķ�װ��

���ļ�����Ҫ���ڰ����ڵĵ����㷨��װGEOAlgorithm�С�
\author htoo
\version 0.0.0.1
\date 2013-02-18
*/

#ifndef GEO_ALGORITHM_H_INCLUDE

#define GEO_ALGORITHM_H_INCLUDE

#include "port.datblock.h"

using port::DatBlock;

class GEOAlgorithm
{
public:
	enum
	{
	    GEO_ALGORITHM_RIGHT = 0,
	    GEO_ALGORITHM_WRONG = 1
	};

	///��ʼ���㷨��
	GEOAlgorithm(const char *);

	virtual ~GEOAlgorithm();

	///��ʼ����������ѡ
	virtual int Init(int argc, char ** argv);

	///���Դ���ݼ���������ѡ
	virtual int GetSrcDriver();

	///���Ŀ�����ݼ���������ѡ
	virtual int GetDstDriver();

	///��Դ���ݼ�����ѡ
	virtual int OpenSrcDS();

	///�ر�Դ���ݼ�����ѡ
	virtual int CloseSrcDS();

	///��������Ŀ�����ݼ�����ѡ
	virtual int CreateDstDS();

	///��Ŀ�����ݼ�����ѡ
	virtual int OpenDstDS();

	///�������Ŀ�����ݼ�����ʵ��
	/** \sa GEOAlgorithm::OpenDstDS GEOAlgorithm::CreateDstDS */
	int CreateOrOpenDstDS();

	///�ر�Ŀ�����ݼ�����ѡ
	virtual int CloseDstDS();

	///��ô������ݴ�С����ѡ
	virtual int GetComputeDataSize(DatBlock & data);

	///�����㷨����ѡ
	virtual int Compute(const DatBlock & data);

	///������ѡ
	virtual int Clean();

	///��ӡ����
	virtual void Help();

	///�����㷨�����Խӿڣ���ʵ��
	int Test(int , char ** );

	///���û�ָ�����ݿ�Ĵ�С��û��ָ���򷵻���
	virtual long GetBlockXSize();

	///���û�ָ�����ݿ�Ĵ�С��û��ָ���򷵻���
	virtual long GetBlockYSize();

private:
	const char * m_algname;
};

#endif