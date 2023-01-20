#ifndef BUFFERFILE_H
#define BUFFERFILE_H

#include "buffer.h"
#include <fstream>
#include <memory>

class BufferFile : public Buffer
{
private:
    std::unique_ptr<std::fstream> file;
public:
    BufferFile(std::string path);
    ~BufferFile();
    virtual void add(int a) override;
    virtual void write() override;
};

#endif // BUFFERFILE_H
