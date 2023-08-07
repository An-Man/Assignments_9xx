#ifndef TEMPLATE_H
#define TEMPLATE_H

template <typename R, typename... Args>
class Caller
{
    public:

        using return_type = R;
        static const int arg_count {sizeof...(Args)};
        
        Caller(R(*)(Args... args)) {}
};

#endif