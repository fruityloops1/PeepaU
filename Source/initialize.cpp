extern "C" void (*_ctors[])();

extern "C" void initialize()
{
    for (int i = 0; _ctors[i]; i++)
        (*_ctors[i])();
}