Printer(const int _ppm, const std::string & _color, const std::string & _manufacturer, const std::string & _description, const std::string & _serialNumber);
        void print() const 
{
	std::cout << "Printer: PPM = " << /* ppm identifier */ << ", Color Printer = " << /* color identifier */ << ", Manufacturer = " << /* Manufacturer identifier */ << ", Description = " << /* Description identifier */ << ", SN = " << /* SerialNumber identifier */ << std::endl;
}
        std::string getType() const;
