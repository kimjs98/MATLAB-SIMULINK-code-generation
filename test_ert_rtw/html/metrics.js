function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["memset"] = {file: "C:\\Program Files\\MATLAB\\R2020a\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["test_call_sensor_fusion"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\test_ert_rtw\\test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["test_call_sensor_fusion_Init"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\test_ert_rtw\\test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["test_cruise_mode"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\test_ert_rtw\\test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["test_cruise_mode_Init"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\test_ert_rtw\\test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["test_cruise_mode_stateflow"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\test_ert_rtw\\test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["test_cruise_mode_stateflow_Init"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\test_ert_rtw\\test.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["test_initialize"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\test_ert_rtw\\test.c",
	stack: 20,
	stackTotal: 20};
	 this.metricsArray.fcn["test_step"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\test_ert_rtw\\test.c",
	stack: 20,
	stackTotal: 20};
	 this.metricsArray.fcn["test_terminate"] = {file: "C:\\Users\\김진성\\Desktop\\matlab\\test_ert_rtw\\test.c",
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
	 this.codeMetricsSummary = '<a href="test_metrics.html">Global Memory: 0(bytes) Maximum Stack: 20(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
