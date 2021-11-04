function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["px4demo_attitude_con_TimingBrdg"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20180822car\\px4demo_attitude_control20180822car.c",
	size: 4};
	 this.metricsArray.var["px4demo_attitude_cont_GlobalTID"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20180822car\\px4demo_attitude_control20180822car.c",
	size: 12};
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
	 this.metricsArray.fcn["px4demo_attitud_MATLABFunction1"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20180822car\\px4demo_attitude_control20180822car.c",
	stack: 0,
	stackTotal: 4};
	 this.metricsArray.fcn["px4demo_attitud_MATLABFunction2"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20180822car\\px4demo_attitude_control20180822car.c",
	stack: 0,
	stackTotal: 4};
	 this.metricsArray.fcn["px4demo_attitude_con_initialize"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20180822car\\px4demo_attitude_control20180822car.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["px4demo_attitude_contr_pwm_out1"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20180822car\\px4demo_attitude_control20180822car.c",
	stack: 4,
	stackTotal: 8};
	 this.metricsArray.fcn["px4demo_attitude_control2018082"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20180822car\\px4demo_attitude_control20180822car.c",
	stack: 60,
	stackTotal: 68};
	 this.metricsArray.fcn["px4demo_attitude_control20_Init"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\px4demo_attitude_control20180822car\\px4demo_attitude_control20180822car.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rt_roundf_snf"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_roundf_snf.c",
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
