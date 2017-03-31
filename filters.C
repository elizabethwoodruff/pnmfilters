#include <filters.h>


filter::filter(){
	;
}
void Image::Update() const {

	if (parent  == NULL){
	isUpdated = true;
	}
	else{
	parent->Update();
	isUpdated = true;
	}
	return;

}

