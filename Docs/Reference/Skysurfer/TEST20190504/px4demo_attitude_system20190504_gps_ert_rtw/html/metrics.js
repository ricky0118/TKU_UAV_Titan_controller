function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtInf"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_nonfinite.c",
	size: 8};
	 this.metricsArray.var["rtInfF"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_nonfinite.c",
	size: 4};
	 this.metricsArray.var["rtMinusInf"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_nonfinite.c",
	size: 8};
	 this.metricsArray.var["rtMinusInfF"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_nonfinite.c",
	size: 4};
	 this.metricsArray.var["rtNaN"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_nonfinite.c",
	size: 8};
	 this.metricsArray.var["rtNaNF"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_nonfinite.c",
	size: 4};
	 this.metricsArray.fcn["ceil"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["fabs"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["floor"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtGetInf"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rtGetInf.c",
	stack: 20,
	stackTotal: 20};
	 this.metricsArray.fcn["rtGetInfF"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rtGetInf.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetMinusInf"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rtGetInf.c",
	stack: 20,
	stackTotal: 20};
	 this.metricsArray.fcn["rtGetMinusInfF"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rtGetInf.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetNaN"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rtGetNaN.c",
	stack: 20,
	stackTotal: 20};
	 this.metricsArray.fcn["rtGetNaNF"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rtGetNaN.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtIsInf"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsInfF"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaN"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaNF"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rt_InitInfAndNaN"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_nonfinite.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rt_roundd_snf"] = {file: "D:\\瞻聽嚙穀tamp\\TEST20190504\\slprj\\ert\\_sharedutils\\rt_roundd_snf.c",
	stack: 8,
	stackTotal: 8};
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
