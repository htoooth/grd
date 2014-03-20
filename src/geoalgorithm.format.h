#ifndef GEO_ALGORITHM_FORMAT_H_INCLUDE

#define GEO_ALGORITHM_FORMAT_H_INCLUDE

#include <cpl_string.h>
#include <cpl_conv.h>
#include <cpl_port.h>
#include <cpl_vsi.h>

#include <ogr_api.h>
#include <ogr_feature.h>
#include <ogr_spatialref.h>
#include <ogrsf_frmts.h>

#include <gdal.h>
#include <gdal_priv.h>
#include <gdal_pam.h>
#include <vrtdataset.h>

///ע�����еĸ�ʽ����������ʸ����դ��
void RegisterAll();

void RegisterVector();

void RegisterRaster();

///���ʸ����������
OGRSFDriver * GetVectorDriver(const char * pszFormat);

///���դ����������
GDALDriver * GetRasterDriver(const char * pszFormat );

///��ʸ�����ݼ�
OGRDataSource * VectorOpen(const char * pszFilename,
                           GDALAccess eAccess);

///��դ�����ݼ�
GDALDataset * RasterOpen(const char * pszFilename,
                         GDALAccess eAccess);

///����ʸ�����ݼ�
OGRDataSource * VectorCreate(const char * pszFormat,
                             const char * pszFilename,
                             char ** papszOptions = NULL);

///����դ�����ݼ�
GDALDataset * RasterCreate(const char * pszFormat,
                           const char * pszFilename,
                           char ** papszOptions = NULL);

///����դ�����ݼ�Ԫ����
char ** SetCreateMetaData(int xsize, int ysize,
                          int band, GDALDataType eDataType);

///�ر�ʸ�����ݼ�
void VectorClose(OGRDataSource * poDS);

///�ر�դ�����ݼ�
void RasterClose(GDALDataset * poDS);

///���ʸ��������Ϣ
void VectorClean();

///���դ��������Ϣ
void RasterClean();

#endif