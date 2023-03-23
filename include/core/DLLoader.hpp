/*
** EPITECH PROJECT, 2023
** BS
** File description:
** DLLoader
*/

/****************************************************************
 * @file DLLoader.hpp
 * @brief DLLoader class
 * @details This class is used to load dynamic libraries
 * @version 0.1
 * @date 2021-03-15
****************************************************************/
#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_
#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <vector>

/****************************************************************
 * @class DLLoader
 * @brief DLLoader class
 * @details This class is used to load and unload dynamic libraries
 * @tparam T
 * ************************************************************/
template <typename T>
class DLLoader {
  public:
    DLLoader() = default;
    ~DLLoader() = default;
    /*********************************************************
     * @brief getInstance
     * @details This function is used to load a dynamic library
     * @param filename
     * @return std::unique_ptr<T>
     * *******************************************************/
    std::unique_ptr<T> getInstance(std::string filename)
    {
        std::unique_ptr<T> (*entryPoint)(void);
        // if (this->actualLib_)
        //     this->closeLib();
        this->actualLib_ = dlopen(filename.c_str(), RTLD_LAZY);
        if (!this->actualLib_) {
            std::cout << dlerror() << std::endl;
            return nullptr;
        }
        void* result_tmp = dlsym(this->actualLib_, "entryPoint");
        entryPoint = reinterpret_cast<std::unique_ptr<T> (*)(void)>(result_tmp);
        if (!entryPoint) {
            std::cout << dlerror() << std::endl;
            this->closeLib();
            return nullptr;
        }
        return entryPoint();
    }
    /*********************************************************
     * @brief closeLib
     * @details This function is used to unload a dynamic library
     * @return void
     * *******************************************************/
    void closeLib(void)
    {
        if (!this->actualLib_)
            return;
        dlclose(this->actualLib_);
        this->actualLib_ = nullptr;
    }

  private:
    void* actualLib_ { nullptr };
};

#endif /* !DLLOADER_HPP_ */
