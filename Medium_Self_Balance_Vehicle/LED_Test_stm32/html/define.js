function CodeDefine() { 
this.def = new Array();
this.def["LED_Test_M_"] = {file: "LED_Test_c.html",line:35,type:"var"};
this.def["LED_Test_M"] = {file: "LED_Test_c.html",line:36,type:"var"};
this.def["LED_Test_step"] = {file: "LED_Test_c.html",line:39,type:"fcn"};
this.def["LED_Test_initialize"] = {file: "LED_Test_c.html",line:46,type:"fcn"};
this.def["RT_MODEL_LED_Test"] = {file: "LED_Test_types_h.html",line:37,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:75,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:76,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:77,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:78,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:79,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:80,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:81,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:82,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:83,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:93,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:98,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:103,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:110,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:117,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:124,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:131,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:138,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:145,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:163,type:"type"};
this.def["G_TIM_Count"] = {file: "LED_Test_TIM_c.html",line:35,type:"var"};
this.def["G_TIM_Conf"] = {file: "LED_Test_TIM_c.html",line:38,type:"var"};
this.def["G_TIM_Handler"] = {file: "LED_Test_TIM_c.html",line:39,type:"var"};
this.def["TIM2_Conf"] = {file: "LED_Test_TIM_c.html",line:42,type:"var"};
this.def["TIM_PeriodElapsedCustomCallback"] = {file: "LED_Test_TIM_c.html",line:49,type:"fcn"};
this.def["HAL_TIM_PeriodElapsedCallback"] = {file: "LED_Test_TIM_c.html",line:66,type:"fcn"};
this.def["TIM2_ItUpFcn"] = {file: "LED_Test_TIM_c.html",line:81,type:"fcn"};
this.def["TIM_ConfTypeDef"] = {file: "LED_Test_TIM_h.html",line:92,type:"type"};
this.def["TIM_ChTypeDef"] = {file: "LED_Test_TIM_h.html",line:105,type:"type"};
this.def["main.c:OverrunFlags"] = {file: "main_c.html",line:38,type:"var"};
this.def["main.c:autoReloadTimerLoopVal_S"] = {file: "main_c.html",line:41,type:"var"};
this.def["remainAutoReloadTimerLoopVal_S"] = {file: "main_c.html",line:44,type:"var"};
this.def["main"] = {file: "main_c.html",line:52,type:"fcn"};
this.def["SysTick_Handler"] = {file: "stm32xxxx_it_c.html",line:34,type:"fcn"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["LED_Test_c.html"] = "../LED_Test.c";
	this.html2Root["LED_Test_c.html"] = "LED_Test_c.html";
	this.html2SrcPath["LED_Test_h.html"] = "../LED_Test.h";
	this.html2Root["LED_Test_h.html"] = "LED_Test_h.html";
	this.html2SrcPath["LED_Test_private_h.html"] = "../LED_Test_private.h";
	this.html2Root["LED_Test_private_h.html"] = "LED_Test_private_h.html";
	this.html2SrcPath["LED_Test_types_h.html"] = "../LED_Test_types.h";
	this.html2Root["LED_Test_types_h.html"] = "LED_Test_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["LED_Test_External_Functions_h.html"] = "../LED_Test_External_Functions.h";
	this.html2Root["LED_Test_External_Functions_h.html"] = "LED_Test_External_Functions_h.html";
	this.html2SrcPath["LED_Test_TIM_c.html"] = "../LED_Test_TIM.c";
	this.html2Root["LED_Test_TIM_c.html"] = "LED_Test_TIM_c.html";
	this.html2SrcPath["LED_Test_TIM_h.html"] = "../LED_Test_TIM.h";
	this.html2Root["LED_Test_TIM_h.html"] = "LED_Test_TIM_h.html";
	this.html2SrcPath["STM32_Config_h.html"] = "../STM32_Config.h";
	this.html2Root["STM32_Config_h.html"] = "STM32_Config_h.html";
	this.html2SrcPath["main_c.html"] = "../main.c";
	this.html2Root["main_c.html"] = "main_c.html";
	this.html2SrcPath["stm32xxxx_it_c.html"] = "../stm32xxxx_it.c";
	this.html2Root["stm32xxxx_it_c.html"] = "stm32xxxx_it_c.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"LED_Test_c.html","LED_Test_h.html","LED_Test_private_h.html","LED_Test_types_h.html","rtwtypes_h.html","LED_Test_External_Functions_h.html","LED_Test_TIM_c.html","LED_Test_TIM_h.html","STM32_Config_h.html","main_c.html","stm32xxxx_it_c.html"];
