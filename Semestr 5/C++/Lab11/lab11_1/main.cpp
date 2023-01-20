#include <QCoreApplication>
#include "buffer.h"
#include "bufferarr.h"
#include "bufferfile.h"
using namespace std;

int main()
{
    unique_ptr<Buffer> buffers[6];
    for(int i=0;i<3;i++)
    {
        buffers[i] = make_unique<BufferArr>(i+1);
        for(int j=0;j<3;j++)
        {
            buffers[i]->add(j);
        }
    }
    for(int i=3;i<6;i++)
    {
        buffers[i] = make_unique<BufferFile>("plik" + to_string(i) + ".txt");
        for(int j=0;j<3;j++)
        {
            buffers[i]->add(j + 10);
        }

    }
    for(int i=0;i<6;i++)
    {
        buffers[i]->write();
    }
    return 0;
}
