function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["fflush"] = {file: "C:\\Program Files\\MATLAB\\R2020a\\sys\\lcc\\include\\stdio.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memset"] = {file: "C:\\Program Files\\MATLAB\\R2020a\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["printf"] = {file: "C:\\Program Files\\MATLAB\\R2020a\\sys\\lcc\\include\\stdio.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sf_te_submission_flowchart_Init"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sf_test_cruise_flowchart"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sf_test_cruise_flowchart_Init"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sf_test_cruise_mode"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sf_test_cruise_mode_Init"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sf_test_initialize"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["sf_test_sensor_fusion"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sf_test_sensor_fusion_Init"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sf_test_step"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["sf_test_submission_flowchart"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sf_test_submission_mode"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sf_test_submission_mode_Init"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sf_test_terminate"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\sf_test_ert_rtw\\sf_test.c",
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
	 return data; }; 
	 this.codeMetricsSummary = '<a href="sf_test_metrics.html">Global Memory: 0(bytes) Maximum Stack: 4(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
