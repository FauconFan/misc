#ifndef DISTRIB_CLASS_HPP
#define	DISTRIB_CLASS_HPP

#include "libsat.hpp"

class Distrib
{
	public:
		Distrib();
		Distrib(const Distrib &);
		Distrib &operator=(const Distrib &);
		virtual~Distrib();

        // Getters / Setters
		const std::unordered_map<unsigned int, bool> & get_distrib() const;
        void set_presence_variables(const std::vector<Clause> & clauses);

		bool get(unsigned int) const;
		void set(unsigned int, bool);
		void remove(unsigned int);


        // Finalize
		void finalize();

	private:
		std::unordered_map<unsigned int, bool> _distrib {};
		std::set<unsigned int> _present_variables {};
};

std::ostream & operator<<(std::ostream & os, const Distrib & d);

#endif // ifndef DISTRIB_CLASS_HPP
