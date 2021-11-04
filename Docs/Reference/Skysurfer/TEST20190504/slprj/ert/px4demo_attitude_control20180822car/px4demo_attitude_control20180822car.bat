cd .

if "%1"=="" (%PX4_ROOT%\toolchain\bin\make  -f px4demo_attitude_control20180822car.mk postdownload_preexecute all) else (%PX4_ROOT%\toolchain\bin\make  -f px4demo_attitude_control20180822car.mk postdownload_preexecute %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
