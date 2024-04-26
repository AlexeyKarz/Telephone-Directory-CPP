/** \file FileManager.h
 *  \brief Declaration of the FileManager class.
 *  \author Aleksei Karzanov
 *  \version 1.0
 *  \date 26.04.2024
 *  \since 1.0
 */

#ifndef TELDIRECTORY_FILEMANAGER_H
#define TELDIRECTORY_FILEMANAGER_H

#include <string>
#include "../LinkedList/LinkedList.h"
#include "../User/User.h"

/** FileManager class is responsible for reading and writing data to file
 * @author Aleksei Karzanov
 * @created 26.04.2024
 * @version 1.0
 * @since 1.0
 */
class FileManager {
public:
    FileManager() = default;
    void writeToFile(const LinkedList<User> &users, const string &filename);
    void readFromFile(LinkedList<User> &users, const string &filename);
};


#endif //TELDIRECTORY_FILEMANAGER_H
