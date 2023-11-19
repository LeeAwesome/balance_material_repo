#------------------------ Tool Specifications & Options ----------------------

COMPILER  =  lcc

CC        =  "D:\MATLAB2020a\install\sys\lcc64\lcc64\bin\lcc64.exe"
LD        =  "D:\MATLAB2020a\install\sys\lcc64\lcc64\bin\lcclnk64.exe"
LIBCMD    =  "D:\MATLAB2020a\install\sys\lcc64\lcc64\bin\lcclib64.exe"
CFLAGS    =  -dll -noregistrylookup  -c -Zp8 -DLCC_WIN64 -DMATLAB_MEX_FILE -nodeclspec
LDFLAGS   =  -s -dll -entry LibMain 0TWQQ1wfypZRJ8lXW0NTh_cclib.def -L"D:\MATLAB2020a\install\sys\lcc64\lcc64\lib64"

OBJECTS = \
	   myfile.obj \
	   slcc_interface_0TWQQ1wfypZRJ8lXW0NTh.obj \
	   lccstub.obj \

STATICLIBS = \

#------------------------------ Include/Lib Path ------------------------------

INCLUDE_PATH = \
     -I"d:\matlab2020a\install\extern\include" \
     -I"d:\matlab2020a\install\simulink\include" \
     -I"d:\软件\stm32\twowheel\simulink\medium_self_balance_vehicle\slprj\_slcc\0twqq1wfypzrj8lxw0nth" \
     -I"d:\软件\stm32\twowheel\simulink\medium_self_balance_vehicle" \
     -I"d:\matlab2020a\install\sys\lcc64\lcc64\include64" \
     -I"d:\matlab2020a\install\sys\lcc64\lcc64\mex" \

#--------------------------------- Rules --------------------------------------

0TWQQ1wfypZRJ8lXW0NTh_cclib.dll : $(MAKEFILE) $(OBJECTS)
	$(LD) $(LDFLAGS) /OUT:0TWQQ1wfypZRJ8lXW0NTh_cclib.dll $(OBJECTS)  $(STATICLIBS) "D:\MATLAB2020a\install\extern\lib\win64\microsoft\libmex.lib" "D:\MATLAB2020a\install\extern\lib\win64\microsoft\libmx.lib"
myfile.obj :	d:\软件\stm32\twowheel\simulink\medium_self_balance_vehicle\myfile.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "d:\软件\stm32\twowheel\simulink\medium_self_balance_vehicle\myfile.c"
slcc_interface_0TWQQ1wfypZRJ8lXW0NTh.obj :	D:\软件\STM32\TwoWheel\simulink\Medium_Self_Balance_Vehicle\slprj\_slcc\0TWQQ1wfypZRJ8lXW0NTh\slcc_interface_0TWQQ1wfypZRJ8lXW0NTh.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "D:\软件\STM32\TwoWheel\simulink\Medium_Self_Balance_Vehicle\slprj\_slcc\0TWQQ1wfypZRJ8lXW0NTh\slcc_interface_0TWQQ1wfypZRJ8lXW0NTh.c"
lccstub.obj :	D:\MATLAB2020a\install\sys\lcc64\lcc64\mex\lccstub.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "D:\MATLAB2020a\install\sys\lcc64\lcc64\mex\lccstub.c"
