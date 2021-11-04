function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["px4demo_attitude_control20190_B"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	size: 196};
	 this.metricsArray.var["px4demo_attitude_control20190_U"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	size: 44};
	 this.metricsArray.var["px4demo_attitude_control20190_Y"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	size: 54};
	 this.metricsArray.var["px4demo_attitude_control2019_DW"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	size: 66};
	 this.metricsArray.var["px4demo_attitude_control2019_M_"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	size: 10};
	 this.metricsArray.fcn["atan"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
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
	 this.metricsArray.fcn["px4demo_attitud_MATLABFunction1"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	stack: 0,
	stackTotal: 4};
	 this.metricsArray.fcn["px4demo_attitud_MATLABFunction2"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	stack: 0,
	stackTotal: 4};
	 this.metricsArray.fcn["px4demo_attitude_contr_pwm_out1"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	stack: 4,
	stackTotal: 8};
	 this.metricsArray.fcn["px4demo_attitude_control20190311gps.c:rate_scheduler"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["px4demo_attitude_control20190311gps_initialize"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["px4demo_attitude_control20190311gps_step"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	stack: 60,
	stackTotal: 68};
	 this.metricsArray.fcn["px4demo_attitude_control20190311gps_terminate"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rt_roundf_snf"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\px4demo_attitude_control20190311gps_ert_rtw\\px4demo_attitude_control20190311gps.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["sqrt"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
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
