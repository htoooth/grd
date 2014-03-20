#ifndef CGRD_DATASET_H_INCLUDE

#define CGRD_DATASET_H_INCLUDE

#include "geoalgorithm.format.h"
#include "port.debug.h"

namespace cgrd
{

class CGRDRasterBand;

class CGRDDataset
{
	friend class CGRDRasterBand;

public:

	static CGRDDataset * Open ( GDALOpenInfo * );

	CGRDDataset();

	~CGRDDataset();

	CPLErr GetGeoTransform ( double * );

	const char * GetProjectionRef ( void );

	void SetnRasterXSize ( int rasterxsize );

	void SetnRasterYSize ( int rasterysize );

	int GetRasterXSize();

	int GetRasterYSize();

	int GetRasterCount();

	CGRDRasterBand * GetRasterBand();

	void SetnHZoom ( int nhzoom );

	int  GetnHZoom();

	int BlockXSize() const;

	int BlockYSize() const;


private:

	VSILFILE    *    fp;

	CGRDRasterBand * poBand;

	///����任����
	double        adfGeoTransform[6];

	///����ϵ�ַ���esri��ʽ
	char    **    papszPrj;

	///����ϵ�ַ���ogr��ʽ
	char     *    pszProjection;

	int           bNoDataSet;

	double        dfNoDataValue;

	///������
	unsigned char achReadBuf[256];

	GUIntBig      nBufferOffset;

	int           nOffsetInBuffer;

	int           nRasterXSize;

	int           nRasterYSize;

	int           nHZoom;

	int           nBandCount;

	int           nBlockXSize;

	int           nBlockYSize;

	char          Getc();

	GUIntBig      Tell();

	int           Seek ( GUIntBig nOffset );

	void          SetBand(CGRDRasterBand *);

	void BlockXSize(int val);

	void BlockYSize(int val);

};

}

#endif