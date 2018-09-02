#include <iostream>
#include <string>

#include "ProgressBar.h"

ProgressBar::ProgressBar(double startValue, double endValue, int totalSize,
						 bool percentage, bool addInfo, int infoSize):
	m_startValue(startValue), m_endValue(endValue), m_totalSize(totalSize),
	m_percentage(percentage), m_value(0.0), m_sizePercent(0),
	m_addInfo(addInfo), m_infoSize(infoSize)
{
	/*If no size for the info string is given but m_addInfo==true, 
		the string will be displayed but its size will not be included in m_totalSize*/

	if (m_percentage){m_sizePercent=4;}else{m_sizePercent=0;}
	//4 characters to display percentage
}


ProgressBar::~ProgressBar(){
	std::cout<<std::endl;
}


void ProgressBar::init(){
	int const barSize {m_totalSize-m_infoSize-m_sizePercent};
	std::cout<<"[";
	for (int i{1}; i<barSize-1 ; i++){std::cout<<" ";}
	std::cout<<"]";
	std::cout.flush();
}

double ProgressBar::update(double newValue, std::string const& infos){	//Update Bar and return percentage
	int const barSize {m_totalSize-m_infoSize-m_sizePercent};
	std::cout<<"\r";
	m_value = static_cast<int>( barSize*(newValue-m_startValue)/(m_endValue-m_startValue));	//Nb of markers to display
	int percentage = static_cast<int>(100*(newValue-m_startValue)/(m_endValue-m_startValue));

	//Redraw bar
	std::cout<<"[";
	for (int i {1}; i<barSize-1 ; i++) {
		if (i-1<m_value){
			std::cout<<"=";
		}else{
		std::cout<<" ";
		}
	}
	std::cout<<"]";
	
	//Append infos
	addInfo(percentage, infos);
	std::cout.flush();
	return (newValue-m_startValue)/(m_endValue-m_startValue);
}

void ProgressBar::addInfo(int const percentage, std::string const& infos) const{	//Append info after redrawing the bar
	if(m_percentage){
	
		if (percentage>=10&&percentage<100){
			std::cout<<"0"<< percentage<<"%";
		}else if (percentage<10){
			std::cout<< "00"<<percentage<<"%";
		}else{
			std::cout<<percentage<<"%";
		}
	}
	if(m_addInfo){
		std::cout<<infos;
	}
}
