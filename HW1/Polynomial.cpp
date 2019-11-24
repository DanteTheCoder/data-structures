#include "Polynomial.hpp"

Polynomial::Polynomial() {
    // Does nothing.
}

Polynomial::Polynomial(std::string expression) {
    // expression = (c_1)x^n_1 + (c_2)x^n_2 + ... + (c_k)x^n_k
    // c's are integer coefficients, n's are non-negative integer exponents.

    std::string delimiter = " + ";

    std::string term;
    std::string coefficient;
    std::string exponent;
    size_t pos = 0;

    while (true) {
        pos = expression.find(delimiter);

        bool breakTheLoop = (pos == std::string::npos);

        term = expression.substr(0, pos);
        expression.erase(0, pos + delimiter.length());

        pos = term.find("x");

        coefficient = term.substr(1, pos - 2);
        exponent = term.substr(pos + 2, term.length() - pos);

        terms.insertAtTheEnd(Term(std::atoi(coefficient.c_str()), std::atoi(exponent.c_str())));

        if (breakTheLoop) break;
    }
}

void Polynomial::printPolynomial() {
    // prints the polynomial in expression format.
    // expression = (c_1)x^n_1 + (c_2)x^n_2 + ... + (c_k)x^n_k

    Node<Term> *node = terms.getFirstNode();

    while (node) {
        std::cout << "(" << node->element.getCoefficient() << ")x^" << node->element.getExponent();
        if (node->next) std::cout << " + ";
        node = node->next;
    }

    std::cout << std::endl;
}

void Polynomial::simplifyByExponents() {
    /* TODO */

    Node<Term> *termhead = terms.getFirstNode();
    Node<Term> *tmp = NULL;
    Node<Term> *todelete;
    int maxdegree=0;

    while(termhead){

        if(termhead->element.getExponent() > maxdegree){

            maxdegree = termhead->element.getExponent();
        }

        termhead=termhead->next;
    }


    while(maxdegree){

        termhead = terms.getFirstNode();
        tmp = NULL;

        while(termhead){

            if(termhead->element.getExponent() == maxdegree){

                if(tmp == NULL){

                    tmp = termhead;
                }

                else{

                    tmp->element.setCoefficient(tmp->element.getCoefficient() + termhead->element.getCoefficient());
                    todelete=termhead;
                    termhead=termhead->next;
                    terms.removeNode(todelete);
                    continue;


                }
            }

            termhead = termhead->next;

        }

        maxdegree--;
    }

    termhead = terms.getFirstNode();

    while(termhead){

        if(termhead->element.getCoefficient() == 0){
            todelete = termhead;
            termhead = termhead->next;
            terms.removeNode(todelete);
            continue;
        }

        termhead = termhead->next;

    }

}

Polynomial Polynomial::operator+(const Polynomial &rhs) const {
    /* TODO */

    Node<Term> *tmp = rhs.terms.getFirstNode();

    Polynomial p;
    p.terms = terms;

    while(tmp){

        p.terms.insertAtTheEnd(tmp->element);
        tmp=tmp->next;

    }


    return p;

}
