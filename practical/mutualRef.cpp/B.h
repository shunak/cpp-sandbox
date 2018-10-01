#ifndef _B_H_
#define _B_H_


class A; // ref to class A


class B{
    private:
        A* m_pA;
    public:
        B(A* pA);
        void hoge();
};

#endif




