#ifndef Q_DEBUGSTREAM_H
#define Q_DEBUGSTREAM_H

#include <iostream>
#include <streambuf>
#include <string>

#include "QTextEdit.h"

/* http://www.qtforum.org/article/39768/redirecting-std-cout-std-cerf-qdebug-to-qtextedit.html */

class Q_DebugStream : public QObject, std::basic_streambuf<char>
{
    Q_OBJECT
public:
    Q_DebugStream(std::ostream &stream, QTextEdit* text_edit) : m_stream(stream)
    {
        log_window = text_edit;
        m_old_buf = stream.rdbuf();
        stream.rdbuf(this);
    }

    ~Q_DebugStream()
    {
        m_stream.rdbuf(m_old_buf);
    }

protected:

    //This is called when a std::endl has been inserted into the stream
    virtual int_type overflow(int_type v)
    {
        if (v == '\n')
        {
            emit emitConsole(" <br/>");
        }else{
            emit emitConsole((QString)v);
        }
        return v;
    }


    virtual std::streamsize xsputn(const char *p, std::streamsize n)
    {
        QString str(p);
        QString bobColor = "<font color = 'blue'>";
        QString elsaColor = "<font color = 'green'>";
        QString jessicaColor = "<font color = 'red'>";
        QString stdColor = "<font color = 'black'>";
        QString endColor = "</font>";
        QString color;
        QString res;
        res.reserve(10000);

            if(str.contains("Miner Bob:")){
                str+=" ";
                color = bobColor;
            }else if(str.contains("Elsa:")){
                str+=" ";
                color = elsaColor;
            }else if(str.contains("Jessica:")){
                str+=" ";
                color = jessicaColor;
            }else{
                color = stdColor;
            }

            res.append(color + str + endColor);

        emit emitConsole(res);

        return n;
    }

signals:
    void emitConsole(QString msg);

private:
    std::ostream &m_stream;
    std::streambuf *m_old_buf;
    QTextEdit* log_window;
};


#endif // Q_DEBUGSTREAM_H
