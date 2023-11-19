#------------------------ Tool Specifications & Options ----------------------

COMPILER  =  lcc

CC        =  "C:\Program Files\MATLAB\R2021b\sys\lcc64\lcc64\bin\lcc64.exe"
LD        =  "C:\Program Files\MATLAB\R2021b\sys\lcc64\lcc64\bin\lcclnk64.exe"
LIBCMD    =  "C:\Program Files\MATLAB\R2021b\sys\lcc64\lcc64\bin\lcclib64.exe"
CFLAGS    =  -dll -noregistrylookup  -c -Zp8 -DLCC_WIN64 -DMATLAB_MEX_FILE -nodeclspec
LDFLAGS   =  -s -dll -entry LibMain 7z71epij2JJy7rLOa22lHF_cclib.def -L"C:\Program Files\MATLAB\R2021b\sys\lcc64\lcc64\lib64"

OBJECTS = \
	   myfile.obj \
	   slcc_interface_7z71epij2JJy7rLOa22lHF.obj \
	   lccstub.obj \

STATICLIBS = \

#------------------------------ Include/Lib Path ------------------------------

INCLUDE_PATH = \
     -I"c:\program files\matlab\r2021b\extern\include" \
     -I"c:\program files\matlab\r2021b\simulink\include" \
     -I"c:\users\li chong\project\repository_not_changed\medium_self_balance_vehicle\slprj\_slcc\7z71epij2jjy7rloa22lhf" \
     -I"c:\users\li chong\project\repository_not_changed\medium_self_balance_vehicle" \
     -I"c:\program files\matlab\r2021b\sys\lcc64\lcc64\include64" \
     -I"c:\program files\matlab\r2021b\sys\lcc64\lcc64\mex" \

#--------------------------------- Rules --------------------------------------

7z71epij2JJy7rLOa22lHF_cclib.dll : $(MAKEFILE) $(OBJECTS)
	$(LD) $(LDFLAGS) /OUT:7z71epij2JJy7rLOa22lHF_cclib.dll $(OBJECTS)  $(STATICLIBS) "C:\Program Files\MATLAB\R2021b\extern\lib\win64\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2021b\extern\lib\win64\microsoft\libmx.lib"
myfile.obj :	c:\users\LICHON~1\project\REPOSI~1\MEDIUM~1\myfile.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "c:\users\li chong\project\repository_not_changed\medium_self_balance_vehicle\myfile.c"
slcc_interface_7z71epij2JJy7rLOa22lHF.obj :	C:\Users\LICHON~1\project\REPOSI~1\MEDIUM~1\slprj\_slcc\7Z71EP~1\SLCC_I~1.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Users\Li Chong\project\repository_not_changed\Medium_Self_Balance_Vehicle\slprj\_slcc\7z71epij2JJy7rLOa22lHF\slcc_interface_7z71epij2JJy7rLOa22lHF.c"
lccstub.obj :	C:\PROGRA~1\MATLAB\R2021b\sys\lcc64\lcc64\mex\lccstub.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2021b\sys\lcc64\lcc64\mex\lccstub.c"
