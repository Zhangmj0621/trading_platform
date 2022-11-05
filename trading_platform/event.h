#ifndef EVENT_H
#define EVENT_H


template <typename Handler>
class event
{
private:
    Handler m_Handler;
protected:
    virtual void add(const Handler value)
    {
        m_Handler = value;
    }
    virtual void remove(const Handler value)
    {
        if (value == m_Handler)
            m_Handler = nullptr;
    }
public:
    event()
    {
        m_Handler = nullptr;
    }
    event& operator += (const Handler value)
    {
        add(value);
        return *this;
    }
    event& operator -= (const Handler value)
    {
        remove(value);
        return *this;
    }
    operator Handler()
    {
        return m_Handler;
    }
};

typedef void(*EventHandler)();

#endif // EVENT_H
