#pragma once

class ProgressBar
{
public: 
	ProgressBar(double startValue, double endValue, int totalSize,
				bool percentage=true, bool addInfo=false, int infoSize=0); 
	~ProgressBar();
	void init();
	double update(double newValue, std::string const& infos="");


protected:
	void addInfo(int const percentage, std::string const& infos) const;

	double const m_startValue;
	double const m_endValue;
	int const m_totalSize;	//Size of the whole thing (bar + optionnal infos)
	bool const m_percentage;
	double m_value;

	int m_sizePercent;	

	/*Informations can be passed as string when update(),
		and the be displayed next to the bar.*/
	bool const m_addInfo;	
	int const m_infoSize;	//Size of the onfo string
};