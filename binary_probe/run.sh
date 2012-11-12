export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
export LD_PRELOAD=/u/dejun/CS533/derek/binary_probe/lib/libdyninstAPI_RT.so
export DYNINSTAPI_RT_LIB=/u/dejun/CS533/derek/binary_probe/lib/libdyninstAPI_RT.so
export DYNINST_LIBC=/u/dejun/CS533/derek/binary_probe/lib/libc-2.13.so
make
./test hello
unset DYNINST_LIBC
unset DYNINSTAPI_RT_LIB
unset LD_LIBRARY_PATH
