function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["px4demo_attitude_control20190_B"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	size: 124};
	 this.metricsArray.var["px4demo_attitude_control20190_U"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	size: 32};
	 this.metricsArray.var["px4demo_attitude_control20190_Y"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	size: 74};
	 this.metricsArray.var["px4demo_attitude_control2019_DW"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	size: 42};
	 this.metricsArray.var["px4demo_attitude_control2019_M_"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	size: 6};
	 this.metricsArray.fcn["ceil"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["fabs"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["floor"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memset"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["px4demo_attitud_MATLABFunction1"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	stack: 0,
	stackTotal: 4};
	 this.metricsArray.fcn["px4demo_attitud_MATLABFunction2"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	stack: 0,
	stackTotal: 4};
	 this.metricsArray.fcn["px4demo_attitude_contr_pwm_out1"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	stack: 4,
	stackTotal: 8};
	 this.metricsArray.fcn["px4demo_attitude_control20190311roll.c:rate_scheduler"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["px4demo_attitude_control20190311roll_initialize"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["px4demo_attitude_control20190311roll_step"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	stack: 56,
	stackTotal: 64};
	 this.metricsArray.fcn["px4demo_attitude_control20190311roll_terminate"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rt_roundf_snf"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311roll_ert_rtw\\px4demo_attitude_control20190311roll.c",
	stack: 4,
	stackTotal: 4};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data;}
}
	 CodeMetrics.instance = new CodeMetrics();
