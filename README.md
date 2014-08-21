Synopsis Project
==================

Environment variables:
ROOT_SYNOPSIS - project root folder.  
LD_LIBRARY_PATH - add build output folder to this variable and export it
SQL_DB_CONN_STR_POSTGRES - connection string to PostgreSQL test database 
==================

Build and run tests:
1) set SQL_DB_CONN_STR_POSTGRES in setupenv.sh
2) . ./setupenv.sh
3) ./build.sh
4) ./run_test.sh
==================

