#ifndef GEO_ALGORITHM_CGRD2GDAL_H_INCLUDE

#define GEO_ALGORITHM_CGRD2GDAL_H_INCLUDE

#include "geoalgorithm.h"
#include "port.debug.h"
#include "fmts.cgrd.h"

class CGRDAlgorihtm: public GEOAlgorithm
{
public:

	CGRDAlgorihtm();

	~CGRDAlgorihtm();

	///��ʼ����������ѡ
	int Init(int argc, char ** argv);

	///���Ŀ�����ݼ���������ѡ
	int GetDstDriver();

	///��Դ���ݼ�����ѡ
	int OpenSrcDS();

	///�ر�Դ���ݼ�����ѡ
	int CloseSrcDS();

	///��������Ŀ�����ݼ�����ѡ
	int CreateDstDS();

	///��Ŀ�����ݼ�����ѡ
	int OpenDstDS();

	///�ر�Ŀ�����ݼ�����ѡ
	int CloseDstDS();

	///��ô������ݴ�С����ѡ
	int GetComputeDataSize(DatBlock & data);

	///�����㷨����ѡ
	int Compute(const DatBlock & data);

	///һ��ֻ����һ��ͼ��
	long GetBlockYSize();

	///һ��ֻ����һ��ͼ��
	long GetBlockXSize();

	///������ѡ
	int Clean();

	///��ӡ����
	void Help();

private:

	cgrd::CGRDDataset	  *  poSrcDS ;
	GDALDataset      *      poDstDS ;
	GDALDriver       *      poDstDriver;

	const char   	*   	pszSrcFile ;
	const char       *      pszDstFile ;

	const char       *      pszFormat ;

	long              nBlockXSize;
	long              nBlockYSize;
};

#endif
