#include "../ssd.h"
using namespace ssd;

int main()
{
	printf("Running EagleTree\n");
	set_small_SSD_config();
	string name  = "/demo_output/";
	Experiment::create_base_folder(name.c_str());
	Workload_Definition* init = new Init_Workload();
	string calibration_file = "calib.txt";
	Experiment::calibrate_and_save(init, calibration_file);
	Workload_Definition* workload = new Asynch_Random_Workload();
	Experiment* e = new Experiment();
	e->set_calibration_file(calibration_file);
	e->set_workload(workload);
	e->set_io_limit(50000);
	e->set_generate_trace_files(true);
	e->run("test");
	e->draw_graphs();
	delete init;
	delete workload;
	return 0;
}
