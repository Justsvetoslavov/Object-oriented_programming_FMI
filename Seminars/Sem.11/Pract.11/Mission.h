#pragma once

class Mission {
private:
    unsigned points;
    char *title;
    char *description;
    unsigned progress;
public:
    Mission(unsigned, const char *, const char *);

    bool isComplete() const;

    unsigned getProgress() const;

    void addProgress();

    const char *getTitle() const;

    const char *getDescription() const;

    unsigned getPoints();

private:
    void setTitle(const char *);

    void setDescription(const char *);

public:
    Mission(const Mission &);

    Mission(Mission &&);

    Mission &operator=(const Mission &);

    Mission &operator=(Mission &&);

    ~Mission();

private:
    void free();

    void copyFrom(const Mission &);

    void moveFrom(Mission &&);
};
