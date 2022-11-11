#include <exception>
class Ferror : public std::exception
{
  public:
    Ferror()
    {
    }
    const char *what() const throw()
    {
        return "ferror";
    }

  private:
    char *m_p;
};

const char *Ferror::what() const
{
    return ("file error");
}