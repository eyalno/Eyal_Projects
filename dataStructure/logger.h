#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

/*defining macros modes to show logger messages */
#define ERR  1
#define WARR 2
#define DEB  4
#define RMN  8 /* for showing resource managing messages */

extern char buffer[];       /* for using sprintf to formatted messages */

int     LogCreate   ( char _modes, const char* _logName );
void	LogDestroy  ( void                              );


/*   _mode:        what mode does the message belongs to   */
/*   _preMessage:  will appeare before the text. if not
                   intended to use just put "".            */
/*   _message:     the message to writte to log            */
/*   _module:      the domain of the function.             */
/*   _function:    in which function while register to log */
void	LogRegister ( char _mode, const char* _message, const char* _Module, const char* _function);

#endif /* LOGGER_H_INCLUDED */
