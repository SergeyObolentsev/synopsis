cp out/libsynopsisbase.so /usr/lib
cp out/libsynopsisbase.so.1 /usr/lib
cp out/libsynopsisbase.so.1.0 /usr/lib
cp out/libsynopsisbase.so.1.0.0 /usr/lib
cp out/libsynopsisdaopostgres.so /usr/lib
cp out/libsynopsisdaopostgres.so.1 /usr/lib
cp out/libsynopsisdaopostgres.so.1.0 /usr/lib
cp out/libsynopsisdaopostgres.so.1.0.0 /usr/lib
cp out/libsynopsisdao.so /usr/lib
cp out/libsynopsisdao.so.1 /usr/lib
cp out/libsynopsisdao.so.1.0 /usr/lib
cp out/libsynopsisdao.so.1.0.0 /usr/lib
cp out/libsynopsisdaofacade.so /usr/lib
cp out/libsynopsisdaofacade.so.1 /usr/lib
cp out/libsynopsisdaofacade.so.1.0 /usr/lib
cp out/libsynopsisdaofacade.so.1.0.0 /usr/lib

mkdir -p /usr/include/synopsis/base/inc
cp base/inc/column.h /usr/include/synopsis/base/inc
cp base/inc/defines.h /usr/include/synopsis/base/inc
cp base/inc/field.h /usr/include/synopsis/base/inc
cp base/inc/stl_helper_map.h /usr/include/synopsis/base/inc
cp base/inc/variant.h /usr/include/synopsis/base/inc
cp base/inc/synopsis_log.h /usr/include/synopsis/base/inc

mkdir -p /usr/include/synopsis/dao/inc
cp dao/inc/daocommon.h /usr/include/synopsis/dao/inc
cp dao/inc/dataaccessorutils.h /usr/include/synopsis/dao/inc
cp dao/inc/iconnection.h /usr/include/synopsis/dao/inc
cp dao/inc/idataaccessor.h /usr/include/synopsis/dao/inc
cp dao/inc/row.h /usr/include/synopsis/dao/inc

mkdir -p /usr/include/synopsis/dao/drivers/postgres/inc
cp dao/drivers/postgres/inc/connection_postgr.h /usr/include/synopsis/dao/drivers/postgres/inc
cp dao/drivers/postgres/inc/dataaccessor_postgr.h /usr/include/synopsis/dao/drivers/postgres/inc

mkdir -p /usr/include/synopsis/dao/facade
#cp dao/facade/ids_drivers.h /usr/include/synopsis/dao/facade
#cp dao/facade/dao_class_factory.h /usr/include/synopsis/dao/facade













