#ifndef LOGICLAYER_H
#define LOGICLAYER_H
class STOP {        //描述一个公交站点
    int numb;       //所有公交站点编号
    int x, y;       //公交站点坐标
public:
    STOP(int n=0, int x=0, int y=0);
    virtual int& X();
    virtual int& Y();
    virtual int& N();
};
class LINE {        //描述一条公交线路
    const int numb; //公交线路编号从1开始
    int*const stop; //公交线路上所有站点编号
    const int nofs; //公交线路上站点数量
public:
    LINE(int numb = 0, int nofs = 0, int* stop = nullptr);
    LINE(const LINE& r);
    LINE(LINE&& r) noexcept;
    LINE& operator=(const LINE& r);
    LINE& operator=(LINE&& r)noexcept;
    virtual int has(int s)const;   //线路是否包含站点编号s,返回线路中的站次序号：-1表示没有
    virtual int cross(const LINE& b)const;  //两条公交线路相交则返回1
    virtual operator int ()const;  //取公交线路编号
    virtual int NOFS()const;       //取公交线路的站点数量
    virtual double dist(int d, int a)const; //线路从站次d到站次e的距离
    virtual int& operator[](int x);//取线路某个站次的站点编号
    virtual ~LINE()noexcept;
};

class TRAN {        //从线路from经站点编号stop转至线路to
    int from;       //现在乘坐的公交线路号
    int to;         //需要转乘的公交线路号
    int stop;       //由stops.txt定义的站点编号
public:
    TRAN(int from=0, int to=0, int stop=0);
    int operator==(const TRAN& t)const;
    virtual int&F();//现在乘坐的公交线路号
    virtual int&T();//需要转乘的公交线路号
    virtual int&S();//转乘点的站点编号
};

class ROUTE {       //一个转乘路径
    TRAN*const tran;//转乘路径上的所有转乘
    const int noft; //转乘路径上转乘次数
public:
    ROUTE(TRAN* tran = nullptr, int noft = 0);
    ROUTE(const TRAN& t);
    ROUTE(const ROUTE& r);
    ROUTE(ROUTE&& r) noexcept;
    virtual int print()const;
    virtual operator int()const;        //得到转乘次数
    virtual int operator==(const ROUTE& r)const;
    virtual ROUTE operator *()const;    //去重复公交转乘
    virtual TRAN& operator[](int);      //一条路径上的所有转乘
    virtual ROUTE operator+(const ROUTE& r)const;
    virtual ROUTE& operator=(const ROUTE& r);
    virtual ROUTE& operator=(ROUTE&& r) noexcept;
    virtual ROUTE& operator+=(const ROUTE& r);
    virtual ~ROUTE() noexcept;
};

class NODE {        //闭包矩阵元素：记载的转乘次数和线路
    ROUTE* const p; //闭包矩阵r*c个元素记载的转乘路径方案
    int n;          //闭包矩阵r*c个元素记载的转乘路径方案数
public:
    NODE(ROUTE*p, int n);
    NODE(int n = 0);
    NODE(const NODE &n);
    NODE(NODE&& n)noexcept;
    virtual NODE  operator*()const; //矩阵元素约简：去掉转乘中的环
    virtual NODE  operator+(const ROUTE& n)const;
    virtual NODE  operator+(const NODE& n)const;
    virtual NODE  operator*(const NODE& n)const;
    virtual NODE& operator=(const NODE& n);
    virtual NODE& operator+=(const NODE& n);
    virtual NODE& operator+=(const ROUTE& n);
    virtual NODE& operator*=(const NODE& n);
    virtual NODE& operator=(NODE&& n)noexcept;
    virtual ROUTE& operator [](int x);
    virtual operator int&();        //可转乘路径数n
    virtual ~NODE()noexcept;
    virtual void print()const;      //打印转乘矩阵的元素
};

class TMAP {        //所有公交转乘元素的闭包矩阵
    NODE *const p;  //指向闭包矩阵的r*c个元素
    const int r, c; //闭包矩阵的行数和列数
public:
    TMAP(int r=0,int c=0);
    TMAP(const TMAP& a);
    TMAP(TMAP&& a)noexcept;
    virtual ~TMAP();
    virtual int notZero()const;                 //若有不可达站点则返回0
    virtual int miniTran(int b, int e, int& noft, ROUTE(&r)[100])const;   //起点站次b,终点站次e,r最多存10条路径，返回路径数
    virtual int miniDist(int b, int e, double& dist, ROUTE(&r)[100])const;//起点站次b,终点站次e,r最多存10条路径，返回路径数
    static  double getDist(int b, int e, ROUTE& r); //起点站次b,终点站次e,基于路径r的距离
    virtual NODE* operator[](int r);            //得到存储多种路径的NODE类元素的某行首址
    virtual int& operator()(int r, int c);      //得到r到c可转乘路径数目
    virtual TMAP operator*(const TMAP& a)const; //闭包运算：乘法
    virtual TMAP operator+(const TMAP& a)const; //闭包运算：加法
    virtual TMAP& operator=(const TMAP& a);
    virtual TMAP& operator=(TMAP&& a);
    virtual TMAP& operator+=(const TMAP& a);
    virtual TMAP& operator*=(const TMAP& a);
    virtual TMAP& operator()(int r, int c, const ROUTE& a);//将路径加入到r行c列元素中
    virtual void print()const;                  //打印转乘矩阵
};

struct GIS {                //描述地理信息系统的类
    static STOP*  st;       //所有公交站点
    static LINE*  ls;       //所有公交线路
    static int  ns, nl;     //公交站数ns，公交线路数nl
    static TMAP raw, tra;   //原始转乘矩阵， 闭包转乘矩阵
    static int  obs;        //GIS的对象数量
public:
    GIS();
    GIS(const char* flstop, const char* flline);
    int miniTran(int fx, int fy, int tx, int ty, int& f, int& t, int& n, ROUTE(&r)[100]);
    int miniDist(int fx, int fy, int tx, int ty, int& f, int& t, double& d, ROUTE(&r)[100]);
    ~GIS();
};

extern GIS *gis;

#endif // LOGICLAYER_H
