#ifndef _A_H_
#define _A_H_

class B; // ref to class B

class A{
    private:
        B* m_pB;
    public:
        A(); // constractor
        void foo();
        void bar();
};

#endif