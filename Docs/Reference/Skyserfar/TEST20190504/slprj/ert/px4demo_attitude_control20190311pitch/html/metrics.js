function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["px4demo_attitude_con_TimingBrdg"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20190311pitch\\px4demo_attitude_control20190311pitch.c",
	size: 4};
	 this.metricsArray.var["px4demo_attitude_cont_GlobalTID"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20190311pitch\\px4demo_attitude_control20190311pitch.c",
	size: 8};
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
	 this.metricsArray.fcn["px4demo_attitud_MATLABFunction1"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20190311pitch\\px4demo_attitude_control20190311pitch.c",
	stack: 0,
	stackTotal: 4};
	 this.metricsArray.fcn["px4demo_attitud_MATLABFunction2"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20190311pitch\\px4demo_attitude_control20190311pitch.c",
	stack: 0,
	stackTotal: 4};
	 this.metricsArray.fcn["px4demo_attitude_con_initialize"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20190311pitch\\px4demo_attitude_control20190311pitch.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["px4demo_attitude_contr_pwm_out1"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20190311pitch\\px4demo_attitude_control20190311pitch.c",
	stack: 4,
	stackTotal: 8};
	 this.metricsArray.fcn["px4demo_attitude_control2019031"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20190311pitch\\px4demo_attitude_control20190311pitch.c",
	stack: 60,
	stackTotal: 68};
	 this.metricsArray.fcn["rt_roundf_snf"] = {file: "C:\\Users\\DELL\\Desktop\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_roundf_snf.c",
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
