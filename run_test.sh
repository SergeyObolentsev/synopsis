export export LD_LIBRARY_PATH=`pwd`/out:$LD_LIBRARY_PATH
echo Working directory: $LD_LIBRARY_PATH
gdb ./out/tst_test_basetest
