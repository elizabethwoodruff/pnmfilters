#include <logging.h>
DataFlowException::DataFlowException(const char *type, const char *error){
	sprintf(msg, "(%s):%s", type, error);
	Logger::LogEvent(msg);

}

FILE* Logger::logger = NULL;
void Logger::LogEvent(const char *event){
	logger = fopen("test_logger", "w");
	fprintf(stderr, "writing msg:%s\n", event);
	fwrite(event, sizeof(char), 1024, logger);
	return;

}
void Logger::Finalize(){
	fclose(logger);
	return;

}
