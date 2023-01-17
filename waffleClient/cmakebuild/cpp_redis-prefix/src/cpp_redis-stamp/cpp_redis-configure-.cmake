

set(command "/usr/bin/cmake;-Wno-dev;-DCMAKE_CXX_COMPILER=/usr/bin/c++;-DCMAKE_C_COMPILER=/usr/bin/cc;-DCMAKE_CXX_FLAGS=;-DCMAKE_C_FLAGS=;-DCMAKE_BUILD_TYPE=;-DCMAKE_INSTALL_PREFIX=/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/external/cpp_redis;-DBUILD_EXAMPLES=OFF;-DBUILD_TESTS=OFF;-DBUILD_SHARED_LIBS=OFF;-GUnix Makefiles;/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp/cpp_redis-configure-out.log"
  ERROR_FILE "/home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp/cpp_redis-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp/cpp_redis-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "cpp_redis configure command succeeded.  See also /home/avishekde/Desktop/Sharath_Waffle/waffle_final/waffle_test/waffleClient/cmakebuild/cpp_redis-prefix/src/cpp_redis-stamp/cpp_redis-configure-*.log")
  message(STATUS "${msg}")
endif()