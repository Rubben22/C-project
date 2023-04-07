#include <utility>

//
// Created by rubyn on 22.05.2022.
//

#ifndef PROIECT_STD_MYEXCEPTION_H
#define PROIECT_STD_MYEXCEPTION_H


class MyException: public std::exception
{
public:
    /** Constructor (C strings).
     *  @param message C-style string error message.
     *                 The string contents are copied upon construction.
     *                 Hence, responsibility for deleting the char* lies
     *                 with the caller.
     */
    explicit MyException(const char* message)
            : msg_(message) {}

    /** Constructor (C++ STL strings).
     *  @param message The error message.
     */
    explicit MyException(std::string  message)
            : msg_(std::move(message)) {}

    /** Destructor.
     * Virtual to allow for subclassing.
     */
    virtual ~MyException() noexcept {}

    /** Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. The underlying memory
     *          is in posession of the MyException object. Callers must
     *          not attempt to free the memory.
     */
    virtual const char* what() const noexcept {
        return msg_.c_str();
    }

protected:
    /** Error message.
     */
    std::string msg_;
};


#endif //PROIECT_STD_MYEXCEPTION_H
