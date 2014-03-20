#include "geoalgorithm.format.h"

OGRSFDriver * GetVectorDriver( const char * pszFormat )
{
	RegisterVector();
	return OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName( pszFormat );
}

GDALDriver * GetRasterDriver( const char * pszFormat )
{
	RegisterRaster();
	return GetGDALDriverManager()->GetDriverByName( pszFormat );
}

OGRDataSource * VectorOpen( const char * pszFilename, GDALAccess eAccess )
{
	RegisterVector();
	return (OGRDataSource *)OGROpen(pszFilename, eAccess, NULL);
}

GDALDataset * RasterOpen( const char * pszFilename, GDALAccess eAccess )
{
	RegisterRaster();
	return (GDALDataset *)GDALOpen(pszFilename, eAccess);
}

OGRDataSource * VectorCreate( const char * pszFormat, const char * pszFilename, char ** papszOptions/*=NULL*/ )
{
	OGRSFDriver * poDriver = GetVectorDriver(pszFormat);
	OGRDataSource * poOGRDataSource =
	    poDriver->CreateDataSource(pszFilename, papszOptions);

#ifdef TRACEON
	//����ʱʹ���ļ������ݿ⣬û��ͼ��ʱ�������⣬����������һ��ͼ��
	//�������ܴ�,���ò��Կ��Թرգ���release��û��
	poOGRDataSource->CreateLayer("TEMP", NULL, wkbUnknown, NULL);
#endif

	return poOGRDataSource;
}

GDALDataset * RasterCreate( const char * pszFormat, const char * pszFilename, char ** papszOptions /*=NULL*/ )
{
	int nXSize = atoi(CSLFetchNameValue(papszOptions, "XSize"));
	int nYSize = atoi(CSLFetchNameValue(papszOptions, "YSize"));
	int nBands = atoi(CSLFetchNameValue(papszOptions, "Bands"));
	GDALDataType eBandType = GDALGetDataTypeByName(CSLFetchNameValue(papszOptions, "DataType"));

	char ** papszCreate = NULL;
	papszCreate = CSLSetNameValue(papszCreate, "BLOCKXSIZE", "256");
	papszCreate = CSLSetNameValue( papszCreate, "BLOCKYSIZE", "1" );

	GDALDriver * poDriver = GetRasterDriver(pszFormat);
	GDALDataset * poDS = poDriver->Create( pszFilename,
	                                       nXSize, nYSize, nBands,
	                                       eBandType, papszCreate) ;

	CSLDestroy(papszCreate);
	return poDS;
}

void VectorClose( OGRDataSource * poDS )
{
	OGR_DS_Destroy(poDS);
}

void RasterClose( GDALDataset * poDS )
{
	GDALClose(poDS);
}

void VectorClean()
{
	OGRCleanupAll();
}

void RasterClean()
{
	GDALDestroyDriverManager();
}

char ** SetCreateMetaData( int xsize, int ysize, int bands , GDALDataType eDataType)
{
	char ** papszMetaData = NULL;
	papszMetaData = CSLAppendPrintf(papszMetaData, "Xsize=%d", xsize);
	papszMetaData = CSLAppendPrintf(papszMetaData, "YSize=%d", ysize);
	papszMetaData = CSLAppendPrintf(papszMetaData, "Bands=%d", bands);
	papszMetaData = CSLAppendPrintf(papszMetaData, "DataType=%s", GDALGetDataTypeName(eDataType));
	return papszMetaData;
}

void RegisterAll()
{
	RegisterVector();
	RegisterRaster();
}

void RegisterVector()
{
	OGRRegisterAll();
}

void RegisterRaster()
{
	GDALAllRegister();
}

