#ifndef Q_DEBUGSTREAM_H
#define Q_DEBUGSTREAM_H

#include <iostream>
#include <streambuf>
#include <string>

#include "QTextEdit.h"

/* http://www.qtforum.org/article/39768/redirecting-std-cout-std-cerf-qdebug-to-qtextedit.html */

class Q_DebugStream : public std::basic_streambuf<char>
{
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
            log_window->append(" ");
        }else{
            log_window->insertHtml((QString)v);
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

        if(str.contains("\n")){
            QStringList strSplitted = str.split("\n");

            log_window->moveCursor (QTextCursor::End);
            log_window->insertHtml(strSplitted.at(0)); //Index 0 is still on the same old line

            for(int i = 1; i < strSplitted.size(); i++){
                log_window->append(strSplitted.at(i));
            }
        }else{
            log_window->moveCursor (QTextCursor::End);
            if(str == "Miner Bob"){
                str+=" ";
                color = bobColor;
            }else if(str == "Elsa"){
                str+=" ";
                color = elsaColor;
            }else if(str == "Jessica"){
                str+=" ";
                color = jessicaColor;
            }else{
                color = stdColor;
            }
            log_window->insertHtml(color + str + endColor);
        }
        return n;
    }

private:
    std::ostream &m_stream;
    std::streambuf *m_old_buf;
    QTextEdit* log_window;
};


#endif // Q_DEBUGSTREAM_H