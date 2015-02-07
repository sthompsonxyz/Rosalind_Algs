#include <string>

class sequence {
	public:
		//ctors
		sequence();

		//getter/setters
		void set_seq(std::string);
		void app_seq(std::string);
		std::string get_seq () const;
		
		void set_name(std::string);
		std::string get_name () const;

		//
		double calc_gc ();



	private:
		std::string name;
		std::string dna_seq;

};
