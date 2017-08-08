#pragma once
class Mp4TopBoxes
{
public:
    Mp4TopBoxes();
    ~Mp4TopBoxes();

    int parseTopBoxes(std::string filePath);
};

